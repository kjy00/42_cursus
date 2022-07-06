/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:20:11 by jiyokim           #+#    #+#             */
/*   Updated: 2022/01/15 13:36:22 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	checkfront(const char *s1, const char *set)
{
	int	front;
	int	setcheck;

	front = 0;
	setcheck = 1;
	while (s1[front] != '\0')
	{
		setcheck = is_set(s1[front], set);
		if (setcheck == 0)
			break ;
		front++;
	}
	return (front);
}

static int	checkback(const char *s1, const char *set)
{
	int	back;
	int	setcheck;

	back = 0;
	setcheck = 1;
	while (s1[back] != 0)
		back++;
	back--;
	while (back > 0)
	{
		setcheck = is_set(s1[back], set);
		if (setcheck == 0)
			break ;
		back--;
	}
	return (back);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		back;
	int		front;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	front = checkfront(s1, set);
	back = checkback(s1, set);
	if (back < front)
		return (ft_strdup(""));
	str = (char *)malloc(back - front + 2);
	if (str == NULL)
		return (NULL);
	while (i < back - front + 1)
	{
		str[i] = s1[front + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
