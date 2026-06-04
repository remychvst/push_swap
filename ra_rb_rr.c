/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:28:11 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/19 18:30:00 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = stack_last(*stack);
	last->next = first;
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	count_op(bench, "ra");
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	count_op(bench, "rb");
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	count_op(bench, "rr");
	ft_putstr_fd("rr\n", 1);
}
