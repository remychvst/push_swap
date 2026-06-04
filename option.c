/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavast <rchavast@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-04 22:29:21 by rchavast          #+#    #+#             */
/*   Updated: 2026-06-04 22:29:21 by rchavast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_eq(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == '\0' && b[i] == '\0');
}

int	is_option(char *s)
{
	if (str_eq(s, "--simple"))
		return (1);
	if (str_eq(s, "--medium"))
		return (1);
	if (str_eq(s, "--complex"))
		return (1);
	if (str_eq(s, "--adaptive"))
		return (1);
	if (str_eq(s, "--bench"))
		return (1);
	return (0);
}

int	parse_options(int ac, char **av, t_options *opt)
{
	int	i;

	opt->strategy = STRAT_ADAPTIVE;
	opt->bench = 0;
	i = 1;
	while (i < ac)
	{
		if (str_eq(av[i], "--simple"))
			opt->strategy = STRAT_SIMPLE;
		else if (str_eq(av[i], "--medium"))
			opt->strategy = STRAT_MEDIUM;
		else if (str_eq(av[i], "--complex"))
			opt->strategy = STRAT_COMPLEX;
		else if (str_eq(av[i], "--adaptive"))
			opt->strategy = STRAT_ADAPTIVE;
		else if (str_eq(av[i], "--bench"))
			opt->bench = 1;
		else if (av[i][0] == '-' && av[i][1] == '-')
			return (0);
		i++;
	}
	return (1);
}
