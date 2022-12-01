/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:58:50 by jiyokim           #+#    #+#             */
/*   Updated: 2022/04/29 17:36:25 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_checkformat(char c, va_list ap)
{
	if (c == 'c')
		return (ft_print_c(va_arg(ap, int)));
	if (c == 's')
		return (ft_print_s(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_print_p(va_arg(ap, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (ft_print_di(va_arg(ap, int)));
	if (c == 'u')
		return (ft_print_u(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_print_x(va_arg(ap, unsigned int)));
	if (c == 'X')
		return (ft_print_upperx(va_arg(ap, unsigned int)));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_checkformat(str[i], ap);
		}
		else
			count += ft_print_c(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
