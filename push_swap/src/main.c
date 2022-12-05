/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:34:55 by roramos           #+#    #+#             */
/*   Updated: 2022/12/04 18:44:19 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_a_stack(int *stack, int length)
{
	t_stack *a_stack;

	a_stack = malloc(sizeof(t_stack));
	if (!a_stack)
		ft_handle_errors("");
	a_stack->list = stack;
	a_stack->top = length - 1;
	a_stack->stack_size = length;
	return(a_stack);
}

t_stack	*init_b_stack(int length)
{
	t_stack *b_stack;

	b_stack = malloc(sizeof(t_stack));
	if (!b_stack)
		ft_handle_errors("");
	b_stack->list = malloc(length * sizeof(int));
	if(!b_stack->list)
		ft_handle_errors("");
	b_stack->top = -1;
	b_stack->stack_size = length;
	return(b_stack);
}

int main(int argc, char const *argv[])
{
	t_stack *a_stack;
	t_stack *b_stack;
	int	i;
	int middle_point;

	a_stack = init_a_stack(parse_input(argc, argv), argc - 1);
	b_stack = init_b_stack(argc - 1);
	middle_point = find_middle_point(0, a_stack);
	while (a_stack->list[a_stack->top] < middle_point)
		execute(PB, a_stack, b_stack);
	while (a_stack->list[0] < middle_point)
	{
		execute(RRA, a_stack, b_stack);
		execute(PB, a_stack, b_stack);
	}
	execute(RA, a_stack, b_stack);
	while (a_stack->stack_size / 2 < a_stack->top)
	{
		if (a_stack->list[a_stack->top] < middle_point)
			execute(PB, a_stack, b_stack);
		execute(RA, a_stack, b_stack);
	}
}
