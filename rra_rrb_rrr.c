/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:18:22 by rchavast          #+#    #+#             */
/*   Updated: 2026/05/19 18:30:01 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	before = *stack;
	while (before->next->next)
		before = before->next;
	last = before->next;
	before->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, t_bench *bench)
{
	rev_rotate(a);
	count_op(bench, "rra");
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, t_bench *bench)
{
	rev_rotate(b);
	count_op(bench, "rrb");
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	rev_rotate(a);
	rev_rotate(b);
	count_op(bench, "rrr");
	ft_putstr_fd("rrr\n", 1);
}
