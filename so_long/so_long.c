/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:26:17 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/04 17:02:18 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *mapname, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		ft_error("open file failed");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty File");
	game->w = ft_strlen(line) - 1;
	game->map = ft_strjoin_nonl(game->map, line, 0, ft_strlen(line));
	while (line)
	{
		game->h++;
		line = get_next_line(fd);
		if (line)
			game->map = ft_strjoin_nonl(game->map, line, \
					ft_strlen(game->map), ft_strlen(line));
	}
	close(fd);
}

void	xpm_img(t_game *g)
{
	int	w;
	int	h;

	g->p_img = mlx_xpm_file_to_image(g->mlxptr, "./img/player.xpm", &w, &h);
	g->e_img = mlx_xpm_file_to_image(g->mlxptr, "./img/exit.xpm", &w, &h);
	g->w_img = mlx_xpm_file_to_image(g->mlxptr, "./img/walls.xpm", &w, &h);
	g->t_img = mlx_xpm_file_to_image(g->mlxptr, "./img/tiles.xpm", &w, &h);
	g->c_img = mlx_xpm_file_to_image(g->mlxptr, "./img/collectible.xpm", \
			&w, &h);
}

void	draw_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->h)
	{
		j = -1;
		while (++j < g->w)
		{
			mlx_put_image_to_window(g->mlxptr, g->winptr, g->t_img, \
					j * 50, i * 50);
			if (g->map[i * g->w + j] == 'P')
				mlx_put_image_to_window(g->mlxptr, g->winptr, g->p_img, \
						j * 50, i * 50);
			else if (g->map[i * g->w + j] == 'E')
				mlx_put_image_to_window(g->mlxptr, g->winptr, g->e_img, \
						j * 50, i * 50);
			else if (g->map[i * g->w + j] == '1')
				mlx_put_image_to_window(g->mlxptr, g->winptr, g->w_img, \
						j * 50, i * 50);
			else if (g->map[i * g->w + j] == 'C')
				mlx_put_image_to_window(g->mlxptr, g->winptr, g->c_img, \
						j * 50, i * 50);
		}
	}
}

void	initialize(t_game *game, char *mapname)
{
	game->map = NULL;
	game->pos = 0;
	game->h = 0;
	game->collectible = 0;
	game->cnt = 0;
	read_map(mapname, game);
	ft_mapcheck(game);
	game->mlxptr = mlx_init();
	if (game->mlxptr == NULL)
		ft_error("mlx_init failed");
	game->winptr = mlx_new_window(game->mlxptr, game->w * 50, game->h * 50, \
			"so_long");
	if (game->winptr == NULL)
		ft_error("mlx_new_window failed");
	xpm_img(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error("Error\n[Usage]: ./so_long [MAP]");
	if (ft_strlen(argv[1]) < 4 \
			|| ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 5))
		ft_error("Error\n[MAP]: filename extension is .ber");
	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("malloc failed");
	initialize(game, argv[1]);
	draw_map(game);
	mlx_hook(game->winptr, 2, 0, &move, game);
	mlx_hook(game->winptr, 17, 0, &exit_game, game);
	mlx_loop(game->mlxptr);
	return (0);
}
