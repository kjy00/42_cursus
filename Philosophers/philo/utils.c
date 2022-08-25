/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:22:42 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/28 15:22:44 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_finished(t_philo *p)
{
	pthread_mutex_lock(&(p->rules->end_mtx));
	if (p->rules->must_eat != -1 && \
			p->rules->end_people == p->rules->philos_num)
	{
		pthread_mutex_lock(&(p->rules->die_mtx));
		p->rules->die_flag = 1;
		pthread_mutex_unlock(&(p->rules->die_mtx));
		pthread_mutex_unlock(&(p->rules->end_mtx));
		return (1);
	}
	pthread_mutex_unlock(&(p->rules->end_mtx));
	return (0);
}

void	sleep_ms(long long ms, long long start)
{
	while (ms > getcurtime() - start)
		usleep(100);
}

int	dieflag(t_philo *p)
{
	pthread_mutex_lock(&(p->rules->die_mtx));
	if (p->rules->die_flag)
	{
		pthread_mutex_unlock(&(p->rules->die_mtx));
		return (1);
	}
	pthread_mutex_unlock(&(p->rules->die_mtx));
	return (0);
}

void	set_die(t_philo *p)
{
	pthread_mutex_lock(&(p->rules->die_mtx));
	pthread_mutex_lock(&(p->rules->print_mtx));
	p->rules->die_flag = 1;
	printf("%lld %d %s\n", getcurtime() - p->rules->start, p->id, DIED);
	pthread_mutex_unlock(&(p->rules->die_mtx));
	pthread_mutex_unlock(&(p->rules->print_mtx));
}

void	*monitor(void *philos)
{
	t_philo		*ps;
	t_rules		*rules;
	int			i;
	long long	last_eat;

	i = 0;
	ps = (t_philo *)philos;
	rules = ps[0].rules;
	while (1)
	{
		if (i == rules->philos_num)
			i = 0;
		if (rules->must_eat != -1 && is_finished(&ps[i]))
			break ;
		pthread_mutex_lock(&(ps[i].philomtx));
		last_eat = ps[i].last_eat;
		pthread_mutex_unlock(&(ps[i].philomtx));
		if (getcurtime() - last_eat >= rules->time2die)
		{
			set_die(&ps[i]);
			break ;
		}
		i++;
	}
	return (NULL);
}
