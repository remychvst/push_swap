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

void	rotate_to_pos(t_stack **stack, int pos, t_bench *bench, int is_b)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (is_b)
				rb(stack, bench);
			else
				ra(stack, bench);
		}
	}
	else
	{
		while (pos++ < size)
		{
			if (is_b)
				rrb(stack, bench);
			else
				rra(stack, bench);
		}
	}
}
