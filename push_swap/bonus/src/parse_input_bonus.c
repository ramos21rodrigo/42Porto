/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:35:52 by roramos           #+#    #+#             */
/*   Updated: 2022/12/08 19:54:42 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	check_duplicates(int *stack, int length)
{
	int	i;
	int	j;

	i = -1;
	while (++i < length)
	{
		j = i;
		while (++j < length)
		{
			if (stack[i] == stack[j])
			{
				free(stack);
				ft_handle_errors();
			}
		}
	}
}

long	ft_latoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i++] == '-')
		sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + str[i++] - '0';
	return (result * sign);
}

int	check_int(const char *arg)
{
	long	n_arg;

	n_arg = ft_latoi(arg);
	if ((n_arg <= INT_MIN) || (n_arg >= INT_MAX))
		ft_handle_errors();
	if (!n_arg && *arg != '0')
		ft_handle_errors();
	return ((int)n_arg);
}

int	*parse_input(int argc, const char **argv)
{
	int	*stack;
	int	i;
	int	j;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack = malloc(sizeof(int) * argc - 1);
	if (!stack)
		ft_handle_errors();
	i = argc;
	j = -1;
	while (--i > 0)
		stack[++j] = check_int(argv[i]);
	check_duplicates(stack, argc - 1);
	return (stack);
}
