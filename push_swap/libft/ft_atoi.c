/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:10:44 by jiyokim           #+#    #+#             */
/*   Updated: 2022/01/15 14:45:10 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static unsigned long	atolong(const char *str, int *neg, int *len)
{
	unsigned long	num;

	num = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*neg = -1;
		str++;
	}
	while (*str != 0 && '0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
		(*len)++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int				len;
	int				neg;
	unsigned long	longnum;

	len = 0;
	neg = 1;
	longnum = atolong(str, &neg, &len);
	if (longnum > LLONG_MAX + 1ULL && neg == -1)
		return ((int)LONG_MIN);
	else if (longnum > LLONG_MAX && neg == 1)
		return ((int)LONG_MAX);
	if (len > 19)
	{
		if (neg == -1)
			return ((int)LONG_MIN);
		return ((int)LONG_MAX);
	}
	return ((int)(longnum * neg));
}
