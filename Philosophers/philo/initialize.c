/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:22:14 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/28 15:23:11 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	getcurtime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	initialize(t_philo *p, t_rules *r)
{
	int	i;

	i = -1;
	r->fork = malloc(r->philos_num * sizeof(pthread_mutex_t));
	if (r->fork == NULL)
		return (-1);
	while (++i < r->philos_num)
	{
		p[i].id = i + 1;
		p[i].lfork = (i + 1) % r->philos_num;
		p[i].rfork = i;
		p[i].cnt = 0;
		p[i].rules = r;
		pthread_mutex_init(&p[i].philomtx, NULL);
	}
	i = -1;
	while (++i < r->philos_num)
		if (pthread_mutex_init(&(r->fork[i]), NULL) != 0)
			return (-1);
	return (0);
}
