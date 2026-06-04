/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:27:30 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/19 18:27:31 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_number(t_stack **a, int nbr)
{
	t_stack	*new;

	if (has_duplicate(*a, nbr))
		error_exit(a);
	new = stack_new(nbr);
	if (!new)
		error_exit(a);
	stack_add_back(a, new);
}

static void	parse_tab(t_stack **a, char **tab)
{
	int	i;
	int	nbr;

	i = 0;
	while (tab[i])
	{
		if (!parse_number(tab[i], &nbr))
		{
			free_split(tab);
			error_exit(a);
		}
		add_number(a, nbr);
		i++;
	}
}

int	parse_args(t_stack **a, int ac, char **av)
{
	char	**tab;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!is_option(av[i]))
		{
			tab = ps_split(av[i]);
			if (!tab)
				error_exit(a);
			parse_tab(a, tab);
			free_split(tab);
		}
		i++;
	}
	return (1);
}
