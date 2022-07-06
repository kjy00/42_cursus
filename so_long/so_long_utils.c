/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:39:43 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/04 16:38:27 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(const char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int	exit_game(t_game *g)
{
	mlx_destroy_window(g->mlxptr, g->winptr);
	exit(0);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && (tmp1[i] || tmp2[i]))
	{
		if (tmp1[i] != tmp2[i])
			return ((int)(tmp1[i] - tmp2[i]));
		i++;
	}
	return (0);
}

char	*ft_strdup_nonl(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

char	*ft_strjoin_nonl(char *map, char *line, int len1, int len2)
{
	int		i;
	char	*str;

	i = -1;
	if (map == NULL && line == NULL)
		return (NULL);
	else if (map == NULL)
		return (ft_strdup_nonl(line));
	else if (line == NULL)
		return (map);
	str = (char *)malloc(len1 + len2);
	if (str == NULL)
		return (NULL);
	while (++i < len1)
		str[i] = map[i];
	while (i < len1 + len2 - 1)
	{
		str[i] = line[i - len1];
		i++;
	}
	str[i] = '\0';
	free(map);
	free(line);
	return (str);
}
