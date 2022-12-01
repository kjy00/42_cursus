/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:40:07 by jiyokim           #+#    #+#             */
/*   Updated: 2022/01/12 17:07:53 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*p;

	p = (char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if ((char)c == p[len])
			return (p + len);
		len--;
	}
	return (NULL);
}
