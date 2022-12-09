/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:45:57 by roramos           #+#    #+#             */
/*   Updated: 2022/12/08 23:51:57 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_stack
{
	int	stack_size;
	int	*list;
	int	top;
}				t_stack;

int		*parse_input(int argc, const char **argv);
int		find_third_point(t_stack *stack);
int		find_bigger_one(t_stack *stack);
int		find_smaller_one(t_stack *stack);
bool	is_empty(t_stack *stack);
bool	is_on_the_first_half(t_stack *stack, int bigger);
void	execute(char *op, t_stack *a_s, t_stack *b_s);
void	push_by_order(t_stack *a_stack, t_stack *b_stack);
bool	is_in_order(t_stack *stack);
void	is_special_case(t_stack *a_stack, t_stack *b_stack);
void	push_by_chunks(t_stack *a_stack, t_stack *b_stack, int point);
void	pass_to_indexes(t_stack *stack);
void	insertion_sort(int *arr, int n);
void	push_binary(t_stack *a_stack, t_stack *b_stack);

#endif
