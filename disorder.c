/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavast <rchavast@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-04 22:58:59 by rchavast          #+#    #+#             */
/*   Updated: 2026-06-04 22:58:59 by rchavast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	value_at(t_stack *a, int pos)
{
	int	i;

	i = 0;
	while (a && i < pos)
	{
		a = a->next;
		i++;
	}
	return (a->value);
}

double	compute_disorder(t_stack *a)
{
	int		i;
	int		j;
	int		size;
	double	mistakes;
	double	total;

	size = stack_size(a);
	if (size < 2)
		return (0);
	i = 0;
	mistakes = 0;
	total = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total++;
			if (value_at(a, i) > value_at(a, j))
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total);
}
