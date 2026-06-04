/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavast <rchavast@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-04 23:51:39 by rchavast          #+#    #+#             */
/*   Updated: 2026-06-04 23:51:39 by rchavast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_range_to_b(t_stack **a, t_stack **b, int min,
	t_bench *bench)
{
	int	pos;
	int	max;
	int	chunk;
	int	size;

	size = stack_size(*a) + stack_size(*b);
	chunk = get_sqrt(size);
	max = min + chunk - 1;
	if (max >= size)
		max = size - 1;
	while (has_index_in_range(*a, min, max))
	{
		pos = get_pos_in_range(*a, min, max);
		rotate_to_pos(a, pos, bench, 0);
		pb(a, b, bench);
	}
}

static void	push_back_max(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;

	while (*b)
	{
		pos = get_max_index_pos(*b);
		rotate_to_pos(b, pos, bench, 1);
		pa(a, b, bench);
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	chunk;
	int	min;

	size = stack_size(*a);
	chunk = get_sqrt(size);
	min = 0;
	while (min < size)
	{
		push_range_to_b(a, b, min, bench);
		min += chunk;
	}
	push_back_max(a, b, bench);
}
