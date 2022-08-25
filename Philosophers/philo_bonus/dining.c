/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:52:11 by jiyokim           #+#    #+#             */
/*   Updated: 2022/08/08 17:52:13 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_fork(t_rules *rules, t_philo *philo)
{
	sem_wait(rules->fork);
	print_stat(rules, philo, FORK);
	if (rules->philos_num == 1)
	{
		sleep_ms(rules->time2die, philo->last_eat);
		sem_wait(rules->print);
		printf("%lld %d %s\n", getcurtime() - rules->start, philo->id, DIED);
		sem_post(rules->end_flag);
	}
	sem_wait(rules->fork);
	print_stat(rules, philo, FORK);
}

void	eating(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&(philo->mtx));
	philo->last_eat = getcurtime();
	pthread_mutex_unlock(&(philo->mtx));
	print_stat(rules, philo, EAT);
	philo->cnt++;
	sleep_ms(rules->time2eat, philo->last_eat);
	if (philo->cnt == rules->must_eat)
		sem_post(rules->end_people);
	sem_post(rules->fork);
	sem_post(rules->fork);
}

void	sleeping(t_rules *rules, t_philo *philo)
{
	long long	cur;

	cur = getcurtime();
	print_stat(rules, philo, SLEEP);
	sleep_ms(rules->time2slp, cur);
}

void	thinking(t_rules *rules, t_philo *philo)
{
	print_stat(rules, philo, THINK);
}
