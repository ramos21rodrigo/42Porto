/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:34:55 by roramos           #+#    #+#             */
/*   Updated: 2022/12/02 15:47:08 by roramos          ###   ########.fr       */
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

	a_stack = init_a_stack(parse_input(argc, argv), argc - 1);
	b_stack = init_b_stack(argc - 1);

	i = -1;
	ft_printf("a:");
	while (++i <= a_stack -> top)
		ft_printf("%d", a_stack->list[i]);
	ft_printf("\nb:");
	i = -1;
	while (++i <= b_stack -> top)
		ft_printf("%d", b_stack->list[i]);

	execute(RA, a_stack, b_stack);

	i = -1;
	ft_printf("\n\na:");
	while (++i <= a_stack -> top)
		ft_printf("%d", a_stack->list[i]);
	i = -1;
	ft_printf("\nb:");
	while (++i <= b_stack -> top)
		ft_printf("%d", b_stack->list[i]);
}
