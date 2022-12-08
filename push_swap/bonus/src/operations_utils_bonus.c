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

# include "../includes/push_swap_bonus.h"

bool	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

bool	is_in_order(t_stack *stack)
{
	int	i;

	if (stack->top == 0)
	{
		ft_printf("OK\n");
		exit(EXIT_SUCCESS);
	}
	i = -1;	
	while (++i < stack->top)
	{
		if(stack->list[i] < stack->list[i + 1])
			return (false); 
	}
	return (true);
}
