/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:34:55 by roramos           #+#    #+#             */
/*   Updated: 2022/12/06 18:22:18 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	init_a_stack(int *stack, int length)
{
	t_stack a_stack;

	a_stack.list = stack;
	a_stack.top = length - 1;
	a_stack.stack_size = length;
	return(a_stack);
}

t_stack	init_b_stack(int length)
{
	t_stack b_stack;

	b_stack.list = malloc(length * sizeof(int));
	if(!b_stack.list)
		ft_handle_errors("");
	b_stack.top = -1;
	b_stack.stack_size = length;
	return(b_stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->list);
	stack->list = NULL;
}

int main(int argc, char const *argv[])
{
	t_stack a_stack;
	t_stack b_stack; 
	int	chunks = 0;

	a_stack = init_a_stack(parse_input(argc, argv), argc - 1);
	b_stack = init_b_stack(argc - 1);
	is_in_order(&a_stack);
	is_special_case(&a_stack);
	while(a_stack.top > 1)
		push_by_chunks(&a_stack, &b_stack, ++chunks);
	if (a_stack.list[a_stack.top] > a_stack.list[a_stack.top - 1])
		execute(SA, &a_stack, &b_stack);
	while (b_stack.top != -1)
		push_by_order(&a_stack, &b_stack);
	free_stack(&a_stack);
	free_stack(&b_stack);
}
