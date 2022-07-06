/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:38:26 by jiyokim           #+#    #+#             */
/*   Updated: 2022/01/12 16:37:16 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		i = -1;
		while (++i < (int)len)
			dst2[i] = src2[i];
	}
	else
	{
		i = (int)len;
		while (i--)
			dst2[i] = src2[i];
	}
	return (dst);
}
