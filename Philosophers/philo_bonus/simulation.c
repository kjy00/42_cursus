/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:52:38 by jiyokim           #+#    #+#             */
/*   Updated: 2022/08/08 17:52:39 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_endppl(void *rules)
{
	t_rules	*r;
	int		i;

	r = (t_rules *)rules;
	i = -1;
	while (++i < r->philos_num)
	{
		sem_wait(r->end_people);
	}
	sem_wait(r->print);
	sem_post(r->end_flag);
	return (NULL);
}

void	*monitor_flag(void *rules)
{
	t_rules	*r;
	int		i;

	r = (t_rules *)rules;
	i = -1;
	sem_wait(r->end_flag);
	while (++i < r->philos_num)
		kill(r->pid[i], 9);
	return (NULL);
}

void	*monitor_die(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(&(p->mtx));
		if (getcurtime() - p->last_eat >= p->r->time2die)
		{
			pthread_mutex_unlock(&(p->mtx));
			sem_wait(p->r->print);
			printf("%lld %d %s\n", getcurtime() - p->r->start, p->id, DIED);
			sem_post(p->r->end_flag);
			break ;
		}
		pthread_mutex_unlock(&(p->mtx));
		usleep(100);
	}
	return (NULL);
}

void	dining(t_rules *rules, t_philo *philo)
{
	pthread_create(&(philo->mnt_die), NULL, monitor_die, (void *)philo);
	if (philo->id % 2)
		usleep(100);
	while (1)
	{
		get_fork(rules, philo);
		eating(rules, philo);
		sleeping(rules, philo);
		thinking(rules, philo);
	}
}

void	simulation(t_rules *r, t_philo *philos)
{
	int	i;
	int	stat;

	i = -1;
	r->start = getcurtime();
	while (++i < r->philos_num)
	{
		r->pid[i] = fork();
		if (i == 0 && r->pid[i] > 0)
		{
			if (r->must_eat != -1)
				pthread_create(&(r->mnt_flag), NULL, monitor_endppl, (void *)r);
			pthread_create(&(r->mnt_endppl), NULL, monitor_flag, (void *)r);
		}
		else if (r->pid[i] == 0)
		{
			philos[i].last_eat = r->start;
			philos[i].id = i + 1;
			dining(r, &philos[i]);
		}
	}
	i = -1;
	while (++i < r->philos_num)
		waitpid(r->pid[i], &stat, 0);
}
