/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdiu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:52:41 by jiyokim           #+#    #+#             */
/*   Updated: 2022/04/29 16:39:41 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

void	ft_putnbr(long num)
{
	char	c;

	if ((num / 10) == 0)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else
	{
		c = num % 10 + '0';
		ft_putnbr(num / 10);
		write(1, &c, 1);
	}
}

int	ft_print_di(int num)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = num;
	if (tmp == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (tmp < 0)
	{
		len++;
		write(1, "-", 1);
		tmp *= -1;
	}
	ft_putnbr(tmp);
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

int	ft_print_u(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_putnbr(num);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}
