/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:06:06 by roramos           #+#    #+#             */
/*   Updated: 2022/12/08 19:51:59 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap(t_stack *stack)
{
	int	temp;

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

	if (is_empty(stack))
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

	if (is_empty(stack))
		return (-1);
	temp = stack->list[stack->top];
	stack->top--;
	return (temp);
}

void	execute(char *op, t_stack *a_s, t_stack *b_s)
{
	if (ft_strnstr(op, SA, 2))
		swap(a_s);
	else if (ft_strnstr(op, SB, 2))
		swap(b_s);
	else if (ft_strnstr(op, SS, 2))
	{
		swap(a_s);
		swap(b_s);
	}
	else if (ft_strnstr(op, RA, 2) && ft_strlen(op) == 2)
		rotate(a_s, 0);
	else if (ft_strnstr(op, RB, 2) && ft_strlen(op) == 2)
		rotate(b_s, 0);
	else if (ft_strnstr(op, RR, 2) && ft_strlen(op) == 2)
	{
		rotate(a_s, 0);
		rotate(b_s, 0);
	}
	else if (ft_strnstr(op, RRA, 3))
		rotate(a_s, 1);
	else if (ft_strnstr(op, RRB, 3))
		rotate(b_s, 1);
	else if (ft_strnstr(op, RRR, 3))
	{
		rotate(a_s, 1);
		rotate(b_s, 1);
	}
	else if (ft_strnstr(op, PA, 5) && !is_empty(b_s))
		push(a_s, pop(b_s));
	else if (ft_strnstr(op, PB, 5) && !is_empty(a_s))
		push(b_s, pop(a_s));
	else
	{
		ft_printf("KO\n");
		exit(EXIT_FAILURE);
	}
}
