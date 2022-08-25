/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:22:23 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/28 15:23:08 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *p, char *status)
{
	pthread_mutex_lock(&(p->rules->print_mtx));
	if (!dieflag(p))
		printf("%lld %d %s\n", getcurtime() - p->rules->start, p->id, status);
	pthread_mutex_unlock(&(p->rules->print_mtx));
}

void	ft_free(t_philo *philos, t_rules rules, int flag)
{
	free(philos);
	if (flag && rules.fork)
		free(rules.fork);
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philos;

	if (parsing(argc, argv, &rules) == -1)
	{
		printf("[Error]: check arguments");
		return (-1);
	}
	philos = (t_philo *)malloc(sizeof(t_philo) * rules.philos_num);
	if (philos == NULL)
		return (-1);
	if (initialize(philos, &rules) == -1)
	{
		ft_free(philos, rules, 0);
		return (-1);
	}
	if (simulation(philos, &rules) == -1)
	{
		ft_free(philos, rules, 1);
		return (-1);
	}
	ft_free(philos, rules, 2);
	return (0);
}
