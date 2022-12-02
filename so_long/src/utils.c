/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:50:13 by roramos           #+#    #+#             */
/*   Updated: 2022/11/29 16:10:11 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_props(t_props *props)
{
	free(props->map.map);
	free(props->mlx.mlx_ptr);
	free(props->mlx.win_ptr);
	free(props->tilemap);
	free(props->images.grass);
	free(props->images.player_idle_1);
	free(props->images.player_idle_2);
	free(props->images.player_left_idle_1);
	free(props->images.player_left_idle_2);
	free(props->images.wall);
	free(props->images.collectible);
	free(props->images.open_door);
	free(props->images.close_door);
}

int	close_program(t_props *props)
{
	free_props(props);
	exit(EXIT_SUCCESS);
}

void	handle_errors(char *message, t_props *props)
{
	free_props(props);
	ft_printf("%s", message);
	exit(EXIT_FAILURE);
}

void	check_for_errors_in_icons(t_props *props, int p, int e)
{
	if (p != 1)
		handle_errors("Error\nAmount of starting points invalid!", props);
	if (props->map.collectibles < 1)
		handle_errors("Error\nAmount of collectibles invalid!", props);
	if (e != 1)
		handle_errors("Error\nAmount of exits invalid!", props);
}

void	check_ber(char *filename, t_props *props)
{
	if (!ft_strnstr(filename + ft_strlen(filename) - 4, ".ber", 4))
		handle_errors("Error\nInvalide file extension!", props);
}

void	count_steps(t_props *props)
{	
	ft_printf("Steps: %d\n", ++props->steps);
}
