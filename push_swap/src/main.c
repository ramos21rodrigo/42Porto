/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:34:55 by roramos           #+#    #+#             */
/*   Updated: 2022/12/05 18:47:11 by roramos          ###   ########.fr       */
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
	int	chunks = 0;
	int	bigger;

	a_stack = init_a_stack(parse_input(argc, argv), argc - 1);
	b_stack = init_b_stack(argc - 1);
	while(a_stack->top > 1)
		push_by_chunks(a_stack, b_stack, ++chunks);
	if (a_stack->list[a_stack->top] > a_stack->list[a_stack->top - 1])
		execute(SA, a_stack, b_stack);
	while (b_stack->top != -1)
		push_by_order(a_stack, b_stack);

			ft_printf("\n");
	i = a_stack->top;
	int j = b_stack->top;
	while(i >= 0 || j >= 0)
	{
		ft_printf("%d %d\n", a_stack->list[i], b_stack->list[j]);
		if (j >= 0)
			j--;
		i--;
	}
	ft_printf("- -\na b");
	
}
