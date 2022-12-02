/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:06:06 by roramos           #+#    #+#             */
/*   Updated: 2022/12/02 15:13:39 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int temp;

	if (stack->top <= 0)
		return ;
	temp = stack->list[stack->top - 1];
	stack->list[stack->top - 1] = stack->list[stack->top];
	stack->list[stack->top] = temp;
}

void	rotate(t_stack *stack, int reverse)
{
	int	temp;
	int	i;

	if(is_empty(stack))
		return ;
	if (!reverse)
	{
		i = stack->top + 1;
		temp = stack->list[stack->top];
		while (--i)
			stack->list[i] = stack->list[i - 1];
		stack->list[0] = temp;
		return ;
	}
	i = -1;
	temp = stack->list[0];
	while (++i < stack->top)
		stack->list[i] = stack->list[i + 1];
	stack->list[stack->top] = temp;
}

void	push(t_stack *stack, int value)
{
	stack->top++;
	stack->list[stack->top] = value;
}

int	pop(t_stack *stack)
{
	int	temp;

	if(is_empty(stack))
			return (-1);
	temp = stack->list[stack->top];
	stack->top--;
	return (temp);
}

void execute(int op, t_stack *a_s, t_stack *b_s)
{
	if (op == SA || op == SS)
		swap(a_s);
	if (op == SB || op == SS)
		swap(b_s);
	if (op == PA)
	{
		if(is_empty(b_s))
			return ;
		push(a_s, pop(b_s));
	}
	if (op == PB)
	{
		if(is_empty(a_s))
			return ;
		push(b_s, pop(a_s));
	}
	if (op == RA || op == RR)
		rotate(a_s, 0);
	if (op == RB || op == RR)
		rotate(b_s, 0);
	if (op == RRA || op == RRR)
		rotate(a_s, 1);
	if (op == RB || op == RRR)
		rotate(b_s, 1);
}