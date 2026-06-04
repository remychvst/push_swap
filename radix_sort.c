/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:28:23 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/19 18:29:57 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_bit(t_stack **a, t_stack **b, int bit, int size,
		t_bench *bench)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((((*a)->index >> bit) & 1) == 1)
			ra(a, bench);
		else
			pb(a, b, bench);
		i++;
	}
	while (*b)
		pa(a, b, bench);
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	bit;
	int	size;
	int	max_bits;

	bit = 0;
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	while (bit < max_bits)
	{
		sort_bit(a, b, bit, size, bench);
		bit++;
	}
}
