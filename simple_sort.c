#include "push_swap.h"

void	simple_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	while (*a)
	{
		while (get_min_index_pos(*a) > 0)
		{
			if (get_min_index_pos(*a) <= stack_size(*a) / 2)
				ra(a, bench);
			else
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	while (*b)
		pa(a, b, bench);
}
