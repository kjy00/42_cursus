/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:52:17 by jiyokim           #+#    #+#             */
/*   Updated: 2022/08/08 17:52:18 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_exit(char *str)
{
	printf("%s\n", str);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("end_flag");
	sem_unlink("end_people");
	exit(1);
}

void	initialize(t_rules *rules, t_philo *philos)
{
	int	i;

	i = -1;
	rules->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, rules->philos_num);
	if (rules->fork == SEM_FAILED)
		ft_exit("[Error]: sem_open failed");
	rules->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	if (rules->print == SEM_FAILED)
		ft_exit("[Error]: sem_open failed");
	rules->end_flag = sem_open("end_flag", O_CREAT | O_EXCL, 0644, 0);
	if (rules->end_flag == SEM_FAILED)
		ft_exit("[Error]: sem_open failed");
	rules->end_people = sem_open("end_people", O_CREAT | O_EXCL, 0644, 0);
	if (rules->end_people == SEM_FAILED)
		ft_exit("[Error]: sem_open failed");
	while (++i < rules->philos_num)
	{
		memset(&philos[i], 0, sizeof(t_philo));
		philos[i].r = rules;
		pthread_mutex_init(&(philos[i].mtx), NULL);
	}
}
