/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:18:26 by rchavast          #+#    #+#             */
/*   Updated: 2026/05/19 18:30:03 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	count_op(bench, "sa");
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	count_op(bench, "sb");
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	count_op(bench, "ss");
	ft_putstr_fd("ss\n", 1);
}
