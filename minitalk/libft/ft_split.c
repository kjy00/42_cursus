/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:14:07 by jiyokim           #+#    #+#             */
/*   Updated: 2022/01/15 16:13:18 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	memclean(char **str, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	*wordcpy(char *str, char const *s, int len)
{
	int	i;

	i = 0;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	**wordsplit(char const *s, char c, char **str, int wordnum)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < wordnum)
	{
		while (s[i] && s[i] == c)
			i++;
		j = i + 1;
		while (s[j] && s[j] != c)
			j++;
		str[k] = wordcpy(str[k], &s[i], j - i);
		if (str[k] == NULL)
		{
			memclean(str, k);
			break ;
		}
		k++;
		i = j;
	}
	str[k] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		wordnum;

	if (s == NULL)
		return (NULL);
	wordnum = wordcount(s, c);
	str = (char **)malloc(sizeof(char *) * (wordnum + 1));
	if (str == NULL)
		return (NULL);
	str = wordsplit(s, c, str, wordnum);
	return (str);
}
