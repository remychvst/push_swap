/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:18:41 by rchavast          #+#    #+#             */
/*   Updated: 2026/05/19 18:30:08 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_strategy_info(t_bench *bench, char *name, char *complexity)
{
	bench->name = name;
	bench->complexity = complexity;
}

static void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench->disorder < 0.2)
	{
		set_strategy_info(bench, "Adaptive", "O(n)");
		simple_sort(a, b, bench);
	}
	else if (bench->disorder < 0.5)
	{
		set_strategy_info(bench, "Adaptive", "O(n sqrt n)");
		medium_sort(a, b, bench);
	}
	else
	{
		set_strategy_info(bench, "Adaptive", "O(n log n)");
		radix_sort(a, b, bench);
	}
}

void	sort_stack(t_stack **a, t_stack **b, t_options opt, t_bench *bench)
{
	if (opt.strategy == STRAT_SIMPLE)
	{
		set_strategy_info(bench, "Simple", "O(n^2)");
		simple_sort(a, b, bench);
	}
	else if (opt.strategy == STRAT_MEDIUM)
	{
		set_strategy_info(bench, "Medium", "O(n sqrt n)");
		medium_sort(a, b, bench);
	}
	else if (opt.strategy == STRAT_COMPLEX)
	{
		set_strategy_info(bench, "Complex", "O(n log n)");
		radix_sort(a, b, bench);
	}
	else if (stack_size(*a) == 2)
	{
		set_strategy_info(bench, "Adaptive", "O(1)");
		sa(a, bench);
	}
	else if (stack_size(*a) == 3)
	{
		set_strategy_info(bench, "Adaptive", "O(1)");
		sort_three(a, bench);
	}
	else
		adaptive_sort(a, b, bench);
}
