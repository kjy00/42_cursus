/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:35:42 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/04 16:36:03 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_game
{
	char	*map;
	int		h;
	int		w;
	int		pos;
	int		cnt;
	int		collectible;
	void	*mlxptr;
	void	*winptr;
	void	*c_img;
	void	*t_img;
	void	*p_img;
	void	*e_img;
	void	*w_img;
}				t_game;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		exit_game(t_game *g);
int		move(int key, t_game *g);
char	*ft_strjoin_nonl(char *map, char *line, int len1, int len2);
char	*ft_strdup_nonl(char *s);
void	ft_error(const char *str);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	draw_map(t_game *g);
void	cnt_print(t_game *g);
void	ft_mapcheck(t_game *game);

#endif
