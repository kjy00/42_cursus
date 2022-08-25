/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:22:33 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/28 15:23:02 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	num;

	num = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
	str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while (*str != 0)
	{
		if (!ft_isdigit(*str))
			return (-1);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

int	check_rules(t_rules *r)
{
	if (r->philos_num < 1)
		return (-1);
	if (r->time2die < 0)
		return (-1);
	if (r->time2eat < 0)
		return (-1);
	if (r->time2slp < 0)
		return (-1);
	return (0);
}

int	parsing(int argc, char **argv, t_rules *rules)
{
	if (argc != 5 && argc != 6)
		return (-1);
	rules->philos_num = ft_atoi(argv[1]);
	rules->time2die = ft_atoi(argv[2]);
	rules->time2eat = ft_atoi(argv[3]);
	rules->time2slp = ft_atoi(argv[4]);
	rules->must_eat = -1;
	rules->die_flag = 0;
	rules->end_people = 0;
	if (argc == 6)
	{
		rules->must_eat = ft_atoi(argv[5]);
		if (rules->must_eat < 0)
			return (-1);
	}
	if (check_rules(rules) == -1)
		return (-1);
	if (pthread_mutex_init(&(rules->end_mtx), NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&(rules->print_mtx), NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&(rules->die_mtx), NULL) != 0)
		return (-1);
	return (0);
}
