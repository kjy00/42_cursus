/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:22:40 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/28 15:22:56 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philo *p)
{
	pthread_mutex_lock(&(p->rules->fork[p->lfork]));
	if (!dieflag(p))
		print_status(p, FORK);
	if (p->rules->philos_num == 1)
	{
		sleep_ms(p->rules->time2die, p->last_eat);
		return (1);
	}
	pthread_mutex_lock(&(p->rules->fork[p->rfork]));
	if (!dieflag(p))
		print_status(p, FORK);
	pthread_mutex_lock(&(p->philomtx));
	p->cnt++;
	p->last_eat = getcurtime();
	pthread_mutex_unlock(&(p->philomtx));
	if (!dieflag(p))
		print_status(p, EAT);
	sleep_ms(p->rules->time2eat, p->last_eat);
	pthread_mutex_lock(&(p->rules->end_mtx));
	if (p->cnt == p->rules->must_eat)
		p->rules->end_people++;
	pthread_mutex_unlock(&(p->rules->end_mtx));
	pthread_mutex_unlock(&(p->rules->fork[p->lfork]));
	pthread_mutex_unlock(&(p->rules->fork[p->rfork]));
	return (0);
}

int	sleeping(t_philo *p)
{
	long long	sleep_start;

	sleep_start = getcurtime();
	if (!dieflag(p))
	{
		print_status(p, SLEEP);
		sleep_ms(p->rules->time2slp, sleep_start);
	}
	if (dieflag(p))
		return (1);
	return (0);
}

int	thinking(t_philo *p)
{
	if (!dieflag(p))
	{
		print_status(p, THINK);
		return (0);
	}
	return (1);
}

void	*routine(void	*philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	if (!(p->id % 2))
		usleep(100);
	while (1)
	{
		if (eating(p))
			break ;
		if (sleeping(p))
			break ;
		if (dieflag(p))
			break ;
		if (thinking(p))
			break ;
		usleep(100);
	}
	return (NULL);
}

int	simulation(t_philo *p, t_rules *r)
{
	int	i;

	i = -1;
	r->start = getcurtime();
	while (++i < r->philos_num)
	{
		p[i].last_eat = r->start;
		if (pthread_create(&(p[i].th), NULL, routine, (void *)&p[i]) != 0)
			return (-1);
	}
	if (pthread_create(&(r->monitor_thread), NULL, monitor, (void *)p) != 0)
		return (-1);
	pthread_join(r->monitor_thread, NULL);
	i = -1;
	while (++i < r->philos_num)
		pthread_join(p[i].th, NULL);
	return (0);
}
