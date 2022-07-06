/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:11:44 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/04 16:19:47 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int key, t_game *g)
{
	if (key == KEY_W)
		move_up(g);
	else if (key == KEY_A)
		move_left(g);
	else if (key == KEY_S)
		move_down(g);
	else if (key == KEY_D)
		move_right(g);
	else if (key == KEY_ESC)
		exit_game(g);
	return (0);
}

void	move_up(t_game *g)
{
	if (g->map[g->pos - g->w] == '1')
		;
	else if (g->map[g->pos - g->w] == 'E')
	{
		if (g->collectible == 0)
		{
			g->cnt++;
			cnt_print(g);
			exit_game(g);
		}
	}
	else
	{
		if (g->map[g->pos - g->w] == 'C')
			g->collectible--;
		g->map[g->pos - g->w] = 'P';
		g->map[g->pos] = '0';
		g->pos -= g->w;
		g->cnt++;
		cnt_print(g);
		draw_map(g);
	}
}

void	move_down(t_game *g)
{
	if (g->map[g->pos + g->w] == '1')
		;
	else if (g->map[g->pos + g->w] == 'E')
	{
		if (g->collectible == 0)
		{
			g->cnt++;
			cnt_print(g);
			exit_game(g);
		}
	}
	else
	{
		if (g->map[g->pos + g->w] == 'C')
			g->collectible--;
		g->map[g->pos + g->w] = 'P';
		g->map[g->pos] = '0';
		g->pos += g->w;
		g->cnt++;
		cnt_print(g);
		draw_map(g);
	}
}

void	move_left(t_game *g)
{
	if (g->map[g->pos - 1] == '1')
		;
	else if (g->map[g->pos - 1] == 'E')
	{
		if (g->collectible == 0)
		{
			g->cnt++;
			cnt_print(g);
			exit_game(g);
		}
	}
	else
	{
		if (g->map[g->pos - 1] == 'C')
			g->collectible--;
		g->map[g->pos - 1] = 'P';
		g->map[g->pos] = '0';
		g->pos--;
		g->cnt++;
		cnt_print(g);
		draw_map(g);
	}
}

void	move_right(t_game *g)
{
	if (g->map[g->pos + 1] == '1')
		;
	else if (g->map[g->pos + 1] == 'E')
	{
		if (g->collectible == 0)
		{
			g->cnt++;
			cnt_print(g);
			exit_game(g);
		}
	}
	else
	{
		if (g->map[g->pos + 1] == 'C')
			g->collectible--;
		g->map[g->pos + 1] = 'P';
		g->map[g->pos] = '0';
		g->pos++;
		g->cnt++;
		cnt_print(g);
		draw_map(g);
	}
}
