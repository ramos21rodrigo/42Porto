/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:45:57 by roramos           #+#    #+#             */
/*   Updated: 2022/12/05 18:29:19 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct s_stack
{
	int	stack_size;
	int	*list;
	int	top;
}				t_stack;

int	*parse_input(int argc, const char **argv); 
void execute(int op, t_stack *a_s, t_stack *b_s);
bool	is_empty(t_stack *stack);
int	find_middle_point(int start_position, t_stack *stack);
int	find_bigger_one(t_stack *stack);
void push_by_chunks(t_stack *a_stack, t_stack *b_stack, int chunks);
void push_by_order(t_stack *a_stack, t_stack *b_stack);

#endif
