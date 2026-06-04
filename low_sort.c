/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavast <rchavast@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-04 23:05:59 by rchavast          #+#    #+#             */
/*   Updated: 2026-06-04 23:05:59 by rchavast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_stack *stack)
{
	int	pos;
	int	best_pos;
	int	min;

	pos = 0;
	best_pos = 0;
	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			best_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (best_pos);
}

static void	rotate_min_top(t_stack **a, t_bench *bench)
{
	int	pos;
	int	size;

	pos = get_min_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, bench);
	}
	else
	{
		while (pos++ < size)
			rra(a, bench);
	}
}

void	low_sort(t_stack **a, t_bench *bench)
{
	int	i;
	int	size;

	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		if ((*a)->next && (*a)->index > (*a)->next->index)
			sa(a, bench);
		ra(a, bench);
		i++;
	}
	rotate_min_top(a, bench);
}
