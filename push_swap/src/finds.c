/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:23:21 by roramos           #+#    #+#             */
/*   Updated: 2022/12/05 18:29:04 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void insertion_sort(int *arr, int n)
{
	int i;
	int	key;
	int	j;

	i = 0;
	while (++i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int	find_middle_point(int start_position, t_stack *stack)
{
	int	*order;
	int	i;
	int	middle_point;
	int	chuck_size;

	chuck_size = (stack->top + 1) - start_position;
	order = malloc(chuck_size * sizeof(int));
	if (!order)
		ft_handle_errors("a");
	i = -1;
	while (++i + start_position < stack-> top + 1)
		order[i] = stack->list[i + start_position];
	insertion_sort(order, chuck_size);
	middle_point = order[(chuck_size / 2)];
	free(order);
	order = NULL;
	return (middle_point);
}

int	find_bigger_one(t_stack *stack)
{
	int	i;
	int bigger;

	bigger = stack->list[0];
	i = 0;
	while (++i < stack->top + 1)
	{
		if (stack->list[i] > bigger)
			bigger = stack->list[i];
	}
	return (bigger);
}