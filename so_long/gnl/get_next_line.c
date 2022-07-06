/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:47:32 by jiyokim           #+#    #+#             */
/*   Updated: 2022/03/10 19:02:38 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char	*split_gnl(char **save, int fd)
{
	char	*line;
	char	*update_save;
	int		i;

	i = 0;
	if (*save[fd] == 0)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	while (save[fd][i] != '\n' && save[fd][i])
		i++;
	line = ft_substr(save[fd], 0, i + 1);
	if (line == NULL)
		return (NULL);
	update_save = ft_substr(save[fd], i + 1, ft_strlen(save[fd]) - (i + 1));
	if (update_save == NULL)
	{
		free(line);
		return (NULL);
	}
	free(save[fd]);
	save[fd] = update_save;
	return (line);
}

char	*ft_check(int fd, char **save, char *buf)
{
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	if (save[fd] == 0)
		save[fd] = ft_strdup("");
	if (save[fd] == 0)
		return (0);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free(save[fd]);
		return (0);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buf;
	int			len;

	len = 1;
	buf = NULL;
	buf = ft_check(fd, save, buf);
	if (buf == 0)
		return (NULL);
	while (len != 0 && !ft_strchr(save[fd], '\n'))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(buf);
			free(save[fd]);
			return (NULL);
		}
		buf[len] = 0;
		save[fd] = ft_strjoin(save[fd], buf);
	}
	free(buf);
	return (split_gnl(save, fd));
}
