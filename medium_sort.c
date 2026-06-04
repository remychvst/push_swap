/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavast <rchavast@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-04 22:59:46 by rchavast          #+#    #+#             */
/*   Updated: 2026-06-04 22:59:46 by rchavast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

static int	has_index_in_range(t_stack *a, int min, int max)
{
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	get_pos_in_range(t_stack *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

static int	get_max_index_pos(t_stack *stack)
{
	int	pos;
	int	best_pos;
	int	max;

	pos = 0;
	best_pos = 0;
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			best_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (best_pos);
}

static void	push_range_to_b(t_stack **a, t_stack **b, int min, int max,
		t_bench *bench)
{
	int	pos;
	int	size;

	while (has_index_in_range(*a, min, max))
	{
		pos = get_pos_in_range(*a, min, max);
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
		pb(a, b, bench);
	}
}

static void	push_back_max(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;
	int	size;

	while (*b)
	{
		pos = get_max_index_pos(*b);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b, bench);
		}
		else
		{
			while (pos++ < size)
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	chunk;
	int	min;
	int	max;

	size = stack_size(*a);
	chunk = get_sqrt(size);
	min = 0;
	while (min < size)
	{
		max = min + chunk - 1;
		if (max >= size)
			max = size - 1;
		push_range_to_b(a, b, min, max, bench);
		min += chunk;
	}
	push_back_max(a, b, bench);
}
