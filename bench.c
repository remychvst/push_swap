/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavast <rchavast@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-04 22:58:52 by rchavast          #+#    #+#             */
/*   Updated: 2026-06-04 22:58:52 by rchavast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putnbr_fd(int n, int fd)
{
	char	c;

	if (n >= 10)
		putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static void	print_percent(double d)
{
	int	value;

	value = (int)(d * 10000 + 0.5);
	putnbr_fd(value / 100, 2);
	write(2, ".", 1);
	if (value % 100 < 10)
		write(2, "0", 1);
	putnbr_fd(value % 100, 2);
	write(2, "%\n", 2);
}

void	count_op(t_bench *bench, char *op)
{
	if (!bench)
		return ;
	bench->total++;
	if (op[0] == 's' && op[1] == 'a')
		bench->sa++;
	else if (op[0] == 's' && op[1] == 'b')
		bench->sb++;
	else if (op[0] == 's' && op[1] == 's')
		bench->ss++;
	else if (op[0] == 'p' && op[1] == 'a')
		bench->pa++;
	else if (op[0] == 'p' && op[1] == 'b')
		bench->pb++;
	else if (op[0] == 'r' && op[1] == 'a')
		bench->ra++;
	else if (op[0] == 'r' && op[1] == 'b')
		bench->rb++;
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == '\0')
		bench->rr++;
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a')
		bench->rra++;
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b')
		bench->rrb++;
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r')
		bench->rrr++;
}

static void	print_first_line(t_bench *bench)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(bench->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(bench->name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(bench->complexity, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	putnbr_fd(bench->total, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench *bench)
{
	print_first_line(bench);
	ft_putstr_fd("[bench] sa: ", 2);
	putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}
