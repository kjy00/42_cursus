/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:52:42 by jiyokim           #+#    #+#             */
/*   Updated: 2022/08/08 17:52:42 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	getcurtime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_stat(t_rules *rules, t_philo *p, char *stat)
{
	sem_wait(rules->print);
	printf("%lld %d %s\n", getcurtime() - rules->start, p->id, stat);
	sem_post(rules->print);
}

void	sleep_ms(long long ms, long long start)
{
	while (ms > getcurtime() - start)
		usleep(100);
}
