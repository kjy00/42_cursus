/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:03:44 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/11 14:14:53 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb_or_rrb(t_dq *b)
{
	int		max_idx;
	int		pos;
	t_node	*node;

	pos = 1;
	node = b->head;
	max_idx = b->size - 1;
	while (node->idx != max_idx)
	{
		pos++;
		node = node->next;
	}
	if (pos <= b->size / 2)
		return (0);
	else
		return (1);
}

void	ra_or_rra(t_dq *a, int n)
{
	if (a->tail->idx <= n)
		operation(RRA, a, NULL);
	else
		operation(RA, a, NULL);
}

void	sort_three(t_dq *a)
{
	int	tmp1;
	int	tmp2;

	tmp1 = a->head->next->idx;
	tmp2 = a->head->next->next->idx;
	if (is_sorted(a))
		return ;
	if (a->head->idx == tmp1 - 2 && a->head->idx == tmp2 - 1)
	{
		operation(SA, a, NULL);
		operation(RA, a, NULL);
	}
	else if (a->head->idx == tmp1 + 1 && a->head->idx == tmp2 - 1)
		operation(SA, a, NULL);
	else if (a->head->idx == tmp1 - 1)
		operation(RRA, a, NULL);
	else if (a->head->idx == tmp1 + 1 && a->head->idx == tmp2 + 2)
	{
		operation(SA, a, NULL);
		operation(RRA, a, NULL);
	}
	else
		operation(RA, a, NULL);
}

void	sort_four(t_dq *a, t_dq *b)
{
	while (a->size > 3)
	{
		if (a->head->idx < 1)
			operation(PB, a, b);
		else
			operation(RA, a, NULL);
	}
	sort_three(a);
	operation(PA, a, b);
}

void	sort_five(t_dq *a, t_dq *b)
{
	while (a->size > 3)
	{
		if (a->head->idx < 2)
			operation(PB, a, b);
		else
			operation(RA, a, NULL);
	}
	sort_three(a);
	while (b->size)
		operation(PA, a, b);
	if (a->head->idx != 0)
		operation(SA, a, NULL);
}
