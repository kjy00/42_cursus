/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:38:01 by jiyokim           #+#    #+#             */
/*   Updated: 2022/01/15 13:34:38 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	if (nb == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}

static void	ft_putnbr(int nb, int fd)
{
	int		i;
	char	arr[10];

	i = 0;
	if (check(nb, fd))
		return ;
	if (nb < 0)
	{
		nb = nb * (-1);
		write(fd, "-", 1);
	}
	while (nb != 0)
	{
		arr[i] = nb % 10 + '0';
		i++;
		nb = nb / 10;
	}
	while (i > 0)
	{
		write(fd, &arr[i - 1], 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
