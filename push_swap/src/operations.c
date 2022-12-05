/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:06:06 by roramos           #+#    #+#             */
/*   Updated: 2022/12/05 15:12:43 by roramos          ###   ########.fr       */
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

void	execute_rest(int op, t_stack *a_s, t_stack *b_s)
{
	if (op == SS)
	{
		swap(a_s);
		swap(b_s);
		write(1, "ss\n", 3);
	} 
	else if (op == RR)
	{
		rotate(a_s, 0);
		rotate(b_s, 0);
		write(1, "rr\n", 3);
	}
	else if (op == RRR)
	{
		rotate(a_s, 1);
		rotate(b_s, 1);
		write(1, "rrr\n", 4);
	}
	else if (op == RRA)
	{
		rotate(a_s, 1);
		write(1, "rra\n", 4);
	}
	else if (op == RB)
	{
		rotate(b_s, 0);
		write(1, "rb\n", 3);
	}
	else if (op == RRB)
	{
		rotate(b_s, 1);
		write(1, "rrb\n", 4);
	}
}

void execute(int op, t_stack *a_s, t_stack *b_s)
{
	if (op == SA)
	{
		swap(a_s);
		write(1, "sa\n", 3);
	}
	if (op == SB)
	{
		swap(b_s);
		write(1, "sb\n", 3);
	}
	if (op == PA)
	{
		if (is_empty(b_s))
			return ;
		push(a_s, pop(b_s));
		write(1, "pa\n", 3);
	}
	if (op == PB)
	{
		if(is_empty(a_s))
			return ;
		push(b_s, pop(a_s));
		write(1, "pb\n", 3);
	}
	if (op == RA )
	{
		rotate(a_s, 0);
		write(1, "ra\n", 3);
	}
	execute_rest(op, a_s, b_s);
}