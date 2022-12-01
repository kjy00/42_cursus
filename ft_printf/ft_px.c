/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:52:38 by jiyokim           #+#    #+#             */
/*   Updated: 2022/04/29 16:47:50 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long long p)
{
	int		len;
	int		i;
	char	arr[16];

	len = 2;
	i = 0;
	write(1, "0x", 2);
	if (p == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	while (i < 16 && p != 0)
	{
		arr[i] = "0123456789abcdef"[p % 16];
		p /= 16;
		i++;
	}
	len += i;
	while (--i >= 0)
		write(1, &arr[i], 1);
	return (len);
}

int	ft_print_x(unsigned int hex)
{
	char	res[16];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (len <= 16 && hex)
	{
		res[len] = "0123456789abcdef"[hex % 16];
		hex /= 16;
		len ++;
	}
	i = len - 1;
	while (i >= 0 && res[i])
	{
		write(1, &res[i], 1);
		i--;
	}
	return (len);
}

int	ft_print_upperx(unsigned int hex)
{
	char	res[16];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (len <= 16 && hex)
	{
		res[len] = "0123456789ABCDEF"[hex % 16];
		hex /= 16;
		len ++;
	}
	i = len - 1;
	while (i >= 0 && res[i])
	{
		write(1, &res[i], 1);
		i--;
	}
	return (len);
}
