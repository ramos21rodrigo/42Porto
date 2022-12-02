/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:35:52 by roramos           #+#    #+#             */
/*   Updated: 2022/12/02 14:45:15 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
				ft_handle_errors("Duplicates");
			}
		}
	}

}

int	check_int(const char *arg)
{
	int n_arg;

	n_arg = ft_atoi(arg);
    if (!n_arg)
        ft_handle_errors("Args!");
	return (n_arg);
}

int	*parse_input(int argc, const char **argv)
{
	int *stack;
	int	i;
	int	arg;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack = malloc(sizeof(int) * argc - 1);
    if (!stack)
        ft_handle_errors("Erro");
	i = 0;
    while (++i < argc)
		stack[i - 1] = check_int(argv[i]);
	check_duplicates(stack, argc - 1);
	return (stack);
}