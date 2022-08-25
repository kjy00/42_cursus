/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:52:22 by jiyokim           #+#    #+#             */
/*   Updated: 2022/08/08 17:52:23 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_philo *philos, t_rules *rules)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("end_flag");
	sem_unlink("end_people");
	free(philos);
	free(rules->pid);
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;

	if (parsing(argc, argv, &rules) == -1)
	{
		printf("[Error]: check arguments\n");
		return (-1);
	}
	philos = malloc(sizeof(t_philo) * rules.philos_num);
	if (philos == NULL)
		return (1);
	initialize(&rules, philos);
	simulation(&rules, philos);
	free_all(philos, &rules);
	return (0);
}
