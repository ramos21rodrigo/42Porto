/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:00:46 by roramos           #+#    #+#             */
/*   Updated: 2022/12/06 18:03:44 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

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
		if(stack->list[i] < stack->list[i + 1])
			return; 
	}
	exit(EXIT_SUCCESS);
}

bool	is_on_the_first_half(t_stack *stack, int bigger)
{
	int	i;
	
	i = -1;	
	while (++i < stack->top / 2)
	{
		if(stack->list[i] == bigger)
			return (false);
	}
	return (true);
}

void	is_special_case(t_stack *stack)
{
	if (stack->top == 2)
	{
		if (stack->list[0] < stack->list[1] && stack->list[0] < stack->list[2]
		&& stack->list[1] < stack->list[2])
			write(1, "sa\nrra\n", 7);
		else if(stack->list[0] < stack->list[1] && stack->list[0] > stack->list[2]
		&& stack->list[1] > stack->list[2])
			write(1, "rra\nsa\n", 7);
		else if(stack->list[0] < stack->list[1] && stack->list[0] < stack->list[2]
		&& stack->list[1] > stack->list[2])
			write(1, "rra\n", 4);
		else if(stack->list[0] > stack->list[1] && stack->list[0] > stack->list[2]
		&& stack->list[1] < stack->list[2])
			write(1, "sa\n", 3);
		else if(stack->list[0] > stack->list[1] && stack->list[0] < stack->list[2]
		&& stack->list[1] < stack->list[2])
			write(1, "ra\n", 3);
		exit(EXIT_SUCCESS);
	}
}