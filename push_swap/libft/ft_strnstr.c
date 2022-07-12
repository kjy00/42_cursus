/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:39:57 by jiyokim           #+#    #+#             */
/*   Updated: 2022/01/12 18:17:12 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;
	char	*tmp;

	i = 0;
	nlen = ft_strlen(needle);
	tmp = (char *)haystack;
	if (*needle == 0)
		return (tmp);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (tmp[i] && i + nlen < len + 1)
	{
		if (ft_strncmp(tmp + i, needle, nlen) == 0)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
