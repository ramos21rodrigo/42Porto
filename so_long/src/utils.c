/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:50:13 by roramos           #+#    #+#             */
/*   Updated: 2022/11/27 17:07:52 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	close_program(void)
{
	exit(EXIT_SUCCESS);
}

void	handle_errors(char *message)
{
	ft_printf("%s", message);
	exit(EXIT_FAILURE);
}

void	check_for_errors_in_icons(t_props *props, int p, int e)
{
	if (p != 1)
		handle_errors("Error\nAmount of starting points invalid!");
	if (props->map.collectibles < 1)
		handle_errors("Error\nAmount of collectibles invalid!");
	if (e != 1)
		handle_errors("Error\nAmount of exits invalid!");
}

void	check_ber(char *filename)
{
	if (!ft_strnstr(filename + ft_strlen(filename) - 4, ".ber", 4))
		handle_errors("Error\nInvalide file extension!");
}

void	count_steps(t_props *props)
{	
	ft_printf("Steps: %d\n", ++props->steps);
}
