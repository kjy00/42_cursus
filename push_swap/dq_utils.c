/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:57:51 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/11 12:59:29 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_new_node(t_dq *a, int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = num;
	node->idx = 0;
	if (a->size == 0)
	{
		a->head = node;
		a->tail = node;
	}
	else
	{
		node->prev = a->tail;
		node->next = NULL;
		a->tail->next = node;
		a->tail = node;
	}
	a->size++;
}

void	rotate(t_dq	*dq)
{
	t_node	*tmp;

	if (dq->size < 2)
		return ;
	tmp = dq->head;
	dq->head = tmp->next;
	dq->head->prev = NULL;
	tmp->prev = dq->tail;
	dq->tail->next = tmp;
	tmp->next = NULL;
	dq->tail = tmp;
}

void	rev_rotate(t_dq *dq)
{
	t_node	*tmp;

	if (dq->size < 2)
		return ;
	tmp = dq->tail;
	dq->tail = tmp->prev;
	dq->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = dq->head;
	dq->head->prev = tmp;
	dq->head = tmp;
}

void	swap(t_dq *dq)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (dq->size < 2)
		return ;
	tmp1 = dq->head;
	tmp2 = tmp1->next;
	dq->head = tmp2;
	tmp1->next = tmp2->next;
	tmp1->prev = tmp2;
	if (tmp1->next)
		tmp1->next->prev = tmp1;
	else
		dq->tail = tmp1;
	tmp2->prev = NULL;
	tmp2->next = tmp1;
}

void	push(t_dq *dst, t_dq *src)
{
	t_node	*tmp;

	if (src->size == 0)
		return ;
	else
	{
		tmp = src->head;
		src->head = src->head->next;
		if (src->head)
			src->head->prev = NULL;
		else
			src->tail = NULL;
		tmp->next = dst->head;
		tmp->prev = NULL;
		if (dst->head)
			dst->head->prev = tmp;
		else
			dst->tail = tmp;
		dst->head = tmp;
		dst->size++;
		src->size--;
	}
}
