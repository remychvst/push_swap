/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaguerd <yasser.aguerd@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:26:46 by yaaguerd          #+#    #+#             */
/*   Updated: 2026/05/19 18:29:52 by yaaguerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_bench
{
	int			enabled;
	double		disorder;
	char		*name;
	char		*complexity;
	int			total;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_bench;

typedef struct s_options
{
	t_strategy	strategy;
	int			bench;
}	t_options;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		parse_args(t_stack **a, int ac, char **av);
int		parse_number(char *str, int *nbr);
int		has_duplicate(t_stack *a, int value);
int		parse_options(int ac, char **av, t_options *opt);
int		is_option(char *s);

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		get_min_index_pos(t_stack *stack);
int		get_max_bits(t_stack *stack);
void	assign_index(t_stack *stack);

char	**ps_split(char *str);
int		ps_isspace(char c);
void	free_split(char **tab);
void	free_stack(t_stack **stack);
void	error_exit(t_stack **a);

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

void	count_op(t_bench *bench, char *op);
void	print_bench(t_bench *bench);
double	compute_disorder(t_stack *a);

void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **a, t_stack **b, t_bench *bench);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

void	sort_three(t_stack **a, t_bench *bench);
void	sort_five(t_stack **a, t_stack **b, t_bench *bench);
void	radix_sort(t_stack **a, t_stack **b, t_bench *bench);
void	simple_sort(t_stack **a, t_stack **b, t_bench *bench);
void	medium_sort(t_stack **a, t_stack **b, t_bench *bench);
void	sort_stack(t_stack **a, t_stack **b, t_options opt, t_bench *bench);

#endif