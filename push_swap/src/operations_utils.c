/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:00:46 by roramos           #+#    #+#             */
/*   Updated: 2022/12/08 23:51:45 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

bool	is_in_order(t_stack *stack)
{
	int	i;

	if (stack->top == 0)
		exit(EXIT_SUCCESS);
	i = -1;
	while (++i < stack->top)
	{
		if (stack->list[i] < stack->list[i + 1])
			return (false);
	}
	return (true);
}

bool	is_on_the_first_half(t_stack *stack, int bigger)
{
	int	i;

	i = -1;
	while (++i < stack->top / 2)
	{
		if (stack->list[i] == bigger)
			return (false);
	}
	return (true);
}

void	pass_to_indexes(t_stack *stack)
{
	int	*order;
	int	*new_list;
	int	i;
	int	j;

	order = malloc((stack->stack_size) * sizeof(int));
	new_list = malloc((stack->stack_size) * sizeof(int));
	i = -1;
	while (++i < stack-> stack_size)
		order[i] = stack->list[i];
	insertion_sort(order, stack->stack_size);
	i = -1;
	while (++i < stack->stack_size)
	{
		j = -1;
		while (++j < stack->stack_size)
			if (stack->list[i] == order[j])
				new_list[i] = j;
	}
	i = -1;
	while (++i < stack->stack_size)
		stack->list[i] = new_list[i];
	free(order);
	free(new_list);
}

void	is_special_case(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->top != 2)
		return ;
	if (a_stack->list[0] < a_stack->list[1] && a_stack->list[0]
		< a_stack->list[2] && a_stack->list[1] < a_stack->list[2])
	{
		execute(SA, a_stack, b_stack);
		execute(RRA, a_stack, b_stack);
	}
	else if (a_stack->list[0] < a_stack->list[1] && a_stack->list[0]
		> a_stack->list[2] && a_stack->list[1] > a_stack->list[2])
	{
		execute(RRA, a_stack, b_stack);
		execute(SA, a_stack, b_stack);
	}
	else if (a_stack->list[0] < a_stack->list[1] && a_stack->list[0]
		< a_stack->list[2] && a_stack->list[1] > a_stack->list[2])
		execute(RRA, a_stack, b_stack);
	else if (a_stack->list[0] > a_stack->list[1] && a_stack->list[0]
		> a_stack->list[2] && a_stack->list[1] < a_stack->list[2])
		execute(SA, a_stack, b_stack);
	else if (a_stack->list[0] > a_stack->list[1] && a_stack->list[0]
		< a_stack->list[2] && a_stack->list[1] < a_stack->list[2])
		execute(RA, a_stack, b_stack);
	exit(EXIT_SUCCESS);
}
