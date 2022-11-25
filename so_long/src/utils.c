/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:50:13 by roramos           #+#    #+#             */
/*   Updated: 2022/11/25 18:36:40 by roramos          ###   ########.fr       */
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
		handle_errors("P");
	if (props->map.collectibles < 1)
		handle_errors("C");
	if (e != 1)
		handle_errors("E");
}

void	count_steps(t_props *props)
{
	write(1, "Steps:", 6);
	ft_putnbr_fd(++props->steps, 1);
	write(1, "\n", 1);
}
