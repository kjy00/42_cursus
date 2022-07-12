/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:02:01 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/11 13:02:21 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_dq(t_dq *dq)
{
	dq->head = NULL;
	dq->tail = NULL;
	dq->size = 0;
}

void	free_nodes(t_dq *dq)
{
	t_node	*tmp;

	tmp = dq->head;
	dq->tail = NULL;
	dq->size = 0;
	while (dq->head)
	{
		dq->head = dq->head->next;
		free(tmp);
		tmp = dq->head;
	}
}
