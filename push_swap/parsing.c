/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:59:48 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/11 16:01:31 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	long long	num;
	int			neg;

	neg = 1;
	num = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str != 0 && '0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
		if (num - 1 > INT_MAX)
			ft_error("Error\n");
	}
	return (num * neg);
}

void	check_empty(char **str)
{
	int	i;
	int	f;
	int	j;

	i = 1;
	while (str[i])
	{
		f = 0;
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]))
				f = 1;
			j++;
		}
		i++;
	}
	if (f == 0)
		ft_error("Error\n");
}

void	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			ft_error("Error\n");
		if ((str[i] == '+' || str[i] == '-') && \
			!ft_isdigit(str[i + 1]))
			ft_error("Error\n");
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			ft_error("Error\n");
		i++;
	}
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	parsing(char **argv, t_dq *a)
{
	char		**arr;
	int			i;
	int			j;
	long long	num;

	i = 1;
	check_empty(argv);
	while (argv[i])
	{
		arr = ft_split(argv[i], ' ');
		j = 0;
		while (arr[j])
		{
			ft_check_digit(arr[j]);
			num = ft_atoll(arr[j]);
			add_new_node(a, num);
			j++;
		}
		ft_free_arr(arr);
		i++;
	}
}
