/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:27:56 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/19 18:30:17 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push(a, b);
	count_op(bench, "pa");
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push(b, a);
	count_op(bench, "pb");
	ft_putstr_fd("pb\n", 1);
}
