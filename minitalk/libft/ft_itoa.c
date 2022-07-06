/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:34:47 by jiyokim           #+#    #+#             */
/*   Updated: 2022/01/15 13:30:45 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	else if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = check_len(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		num = num * (-1);
		str[0] = '-';
	}
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	len--;
	while (num)
	{
		str[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (str);
}
