/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:02:33 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/11 13:03:34 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_chunk(int x)
{
	return (0.000000053 * x * x + 0.03 * x + 14.5);
}

void	init_idx(t_dq *a)
{
	t_node	*i;
	t_node	*j;

	i = a->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data > j->data)
				i->idx++;
			else if (i->data < j->data)
				j->idx++;
			else
				ft_error("Error\n");
			j = j->next;
		}
		i = i->next;
	}
}

int	is_sorted(t_dq *a)
{
	t_node	*i;
	t_node	*j;

	i = a->head;
	while (i->next)
	{
		j = i->next;
		if (i->idx > j->idx)
			return (0);
		i = i->next;
	}
	return (1);
}

void	atob(t_dq *a, t_dq *b)
{
	int		chunk;
	int		num;
	t_node	*node;

	num = 0;
	chunk = calc_chunk(a->size);
	while (a->size != 0)
	{
		node = a->head;
		if (node->idx <= num)
		{
			operation(PB, a, b);
			num++;
		}
		else if (node->idx <= num + chunk)
		{
			operation(PB, a, b);
			operation(RB, NULL, b);
			num++;
		}
		else
			ra_or_rra(a, chunk + num);
	}
}

void	btoa(t_dq *a, t_dq *b)
{
	int		max_idx;

	while (b->size != 0)
	{
		max_idx = b->size - 1;
		if (rb_or_rrb(b) == 0)
		{
			while (b->head->idx != max_idx)
				operation(RB, NULL, b);
		}
		else
		{
			while (b->head->idx != max_idx)
				operation(RRB, NULL, b);
		}
		operation(PA, a, b);
	}
}
