/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:00:46 by roramos           #+#    #+#             */
/*   Updated: 2022/12/08 20:34:32 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

void	is_in_order(t_stack *stack)
{
	int	i;

	if (stack->top == 0)
		exit(EXIT_SUCCESS);
	i = -1;
	while (++i < stack->top)
	{
		if (stack->list[i] < stack->list[i + 1])
			return ;
	}
	exit(EXIT_SUCCESS);
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
