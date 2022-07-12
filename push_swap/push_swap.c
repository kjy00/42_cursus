/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:58:02 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/11 15:42:42 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

void	operation2(int num, t_dq *a, t_dq *b)
{
	if (num == SA)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (num == SB)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	else if (num == RRA)
	{
		rev_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (num == RRB)
	{
		rev_rotate(b);
		write(1, "rrb\n", 4);
	}
}

void	push_swap(t_dq *a, t_dq *b)
{
	if (a->size == 2)
		operation(SA, a, NULL);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
	{
		atob(a, b);
		btoa(a, b);
	}
}

void	operation(int num, t_dq *a, t_dq *b)
{
	if (num == PA)
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
	else if (num == PB)
	{
		push(b, a);
		write(1, "pb\n", 3);
	}
	else if (num == RA)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (num == RB)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	else
		operation2(num, a, b);
}

int	main(int argc, char **argv)
{
	t_dq	a;
	t_dq	b;

	if (argc < 2)
		return (0);
	init_dq(&a);
	init_dq(&b);
	parsing(argv, &a);
	init_idx(&a);
	if (is_sorted(&a))
	{
		free_nodes(&b);
		free_nodes(&a);
		return (0);
	}
	push_swap(&a, &b);
	free_nodes(&b);
	free_nodes(&a);
	return (0);
}
