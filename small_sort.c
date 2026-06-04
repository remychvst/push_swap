/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:18:32 by rchavast          #+#    #+#             */
/*   Updated: 2026/05/19 18:30:06 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_bench *bench)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x > y && x > z)
		ra(a, bench);
	else if (y > x && y > z)
		rra(a, bench);
	if (!is_sorted(*a))
		sa(a, bench);
}

static void	move_min_to_b(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;
	int	size;

	pos = get_min_index_pos(*a);
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

void	sort_five(t_stack **a, t_stack **b, t_bench *bench)
{
	while (stack_size(*a) > 3)
		move_min_to_b(a, b, bench);
	sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}
