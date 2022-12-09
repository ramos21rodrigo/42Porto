/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:10:56 by roramos           #+#    #+#             */
/*   Updated: 2022/12/09 00:06:09 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_by_chunks(t_stack *a_stack, t_stack *b_stack, int point)
{
	while (a_stack->list[a_stack->top] < point)
		execute(PB, a_stack, b_stack);
	while (a_stack->list[0] < point)
	{
		execute(RRA, a_stack, b_stack);
		execute(PB, a_stack, b_stack);
	}
	while (find_smaller_one(a_stack) != point)
	{
		if (a_stack->list[a_stack->top] < point)
			execute(PB, a_stack, b_stack);
		else
			execute(RA, a_stack, b_stack);
	}	
}

void	push_by_order(t_stack *a_stack, t_stack *b_stack)
{
	int	bigger;

	bigger = find_bigger_one(b_stack);
	if (b_stack->top != 0 && b_stack->list[b_stack->top - 1] == bigger)
		execute(SB, a_stack, b_stack);
	if (is_on_the_first_half(b_stack, bigger))
	{
		while (b_stack->list[b_stack->top] != bigger)
		{
			if (b_stack->top != 0 && b_stack->list[b_stack->top - 1] == bigger)
				execute(SB, a_stack, b_stack);
			else
				execute(RB, a_stack, b_stack);
		}
		execute(PA, a_stack, b_stack);
	}
	else
	{
		while (b_stack->list[b_stack->top] != bigger)
			execute(RRB, a_stack, b_stack);
		execute(PA, a_stack, b_stack);
	}
}

void	push_binary(t_stack *a_stack, t_stack *b_stack)
{
	int	max_bits;
	int	num;
	int	i;
	int	j;

	max_bits = 0;
	num = find_bigger_one(a_stack);
	while((num >> max_bits) != 0)
		++max_bits;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < a_stack->stack_size)
		{
			num = a_stack->list[a_stack->top];
			if(((num >> i)&1) == 1)
				execute(RA, a_stack, b_stack);
			else
				execute(PB, a_stack, b_stack);
		}
		while (b_stack->top != -1)
			execute(PA, a_stack, b_stack);
	}
}