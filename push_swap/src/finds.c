/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:23:21 by roramos           #+#    #+#             */
/*   Updated: 2022/12/08 19:23:52 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insertion_sort(int *arr, int n)
{
	int	i;
	int	key;
	int	j;

	i = 0;
	while (++i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}	

int	find_third_point(t_stack *stack)
{
	int	*order;
	int	i;
	int	point;
	int	chuck_size;

	chuck_size = (stack->top + 1);
	order = malloc(chuck_size * sizeof(int));
	if (!order)
		ft_handle_errors();
	i = -1;
	while (++i < stack-> top + 1)
		order[i] = stack->list[i];
	insertion_sort(order, chuck_size);
	point = order[(chuck_size / 2)];
	free(order);
	order = NULL;
	return (point);
}

int	find_smaller_one(t_stack *stack)
{
	int	i;
	int	smaller;

	smaller = stack->list[0];
	i = 0;
	while (++i < stack->top + 1)
	{
		if (stack->list[i] < smaller)
			smaller = stack->list[i];
	}
	return (smaller);
}

int	find_bigger_one(t_stack *stack)
{
	int	i;
	int	bigger;

	bigger = stack->list[0];
	i = 0;
	while (++i < stack->top + 1)
	{
		if (stack->list[i] > bigger)
			bigger = stack->list[i];
	}
	return (bigger);
}
