/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:40:12 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/04 16:55:32 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int num)
{
	char	c;

	if ((num / 10) == 0)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else
	{
		c = num % 10 + '0';
		ft_putnbr(num / 10);
		write(1, &c, 1);
	}
}

void	cnt_print(t_game *g)
{
	write(1, "move :", 6);
	ft_putnbr(g->cnt);
	write(1, "\n", 1);
}

void	ft_mapcheck2(t_game *game)
{
	int	i;
	int	pf;
	int	ef;
	int	cf;

	i = -1;
	pf = 0;
	cf = 0;
	ef = 0;
	while (game->map[++i])
	{
		if (game->map[i] == 'P' && ++pf)
			game->pos = i;
		else if (game->map[i] == 'E')
			ef++;
		else if (game->map[i] == 'C' && ++cf)
			game->collectible++;
		else if (game->map[i] == '1' || game->map[i] == '0')
			;
		else
			ft_error("Error\nMap contains only 1, 0, P, C, E");
	}
	if (pf != 1 || ef == 0 || cf == 0)
		ft_error("Error\nInvalid Map");
}

void	ft_mapcheck(t_game *game)
{
	int	i;

	i = 0;
	if (game->w * game->h != (int)ft_strlen(game->map))
		ft_error("Error\nMap must be rectangular");
	while (game->map[i])
	{
		if (i < game->w && game->map[i] != '1')
			ft_error("Error\nMap must be surrounded by walls");
		else if (i >= (int)ft_strlen(game->map) - game->w \
				&& game->map[i] != '1')
			ft_error("Error\nMap must be surrounded by walls");
		else if ((i % game->w == game->w - 1 || i % game->w == 0) \
				&& game->map[i] != '1')
			ft_error("Error\nMap must be surrounded by walls");
		i++;
	}
	ft_mapcheck2(game);
}
