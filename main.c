/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/19 18:30:19 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_bench(t_bench *bench, t_options opt)
{
	bench->enabled = opt.bench;
	bench->disorder = 0;
	bench->name = "Adaptive";
	bench->complexity = "O(n log n)";
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_options	opt;
	t_bench		bench;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_options(ac, av, &opt))
		return (write(2, "Error\n", 6), 1);
	init_bench(&bench, opt);
	parse_args(&a, ac, av);
	if (!a)
		return (0);
	bench.disorder = compute_disorder(a);
	assign_index(a);
	if (!is_sorted(a))
		sort_stack(&a, &b, opt, &bench);
	if (bench.enabled)
		print_bench(&bench);
	free_stack(&a);
	return (0);
}
