/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:01:06 by jiyokim           #+#    #+#             */
/*   Updated: 2022/07/11 14:15:26 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define PA 0
# define PB 1
# define RA 2
# define RB 3
# define SA 4
# define SB 5
# define RRA 6
# define RRB 7

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
	int				idx;
}				t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
	int		size;
}				t_dq;

void	ft_error(char *str);
void	operation(int num, t_dq *a, t_dq *b);
void	free_nodes(t_dq *dq);
void	init_dq(t_dq *dq);
/*dq_utils.c*/
void	add_new_node(t_dq *a, int num);
void	rotate(t_dq *dq);
void	rev_rotate(t_dq *dq);
void	swap(t_dq *dq);
void	push(t_dq *dst, t_dq *src);
/*parsing.c*/
void	parsing(char **argv, t_dq *a);
/*sorting.c*/
void	init_idx(t_dq *a);
int		is_sorted(t_dq *a);
void	atob(t_dq *a, t_dq *b);
void	btoa(t_dq *a, t_dq *b);
/*sorting2.c*/
int		rb_or_rrb(t_dq *b);
void	ra_or_rra(t_dq *a, int n);
void	sort_three(t_dq *a);
void	sort_four(t_dq *a, t_dq *b);
void	sort_five(t_dq *a, t_dq *b);

#endif
