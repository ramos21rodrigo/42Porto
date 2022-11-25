/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:06:09 by roramos           #+#    #+#             */
/*   Updated: 2022/11/25 18:36:52 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	check_collison(t_props *props)
{
	if (props->map.map[props->player_x][props->player_y] == COLLECTIBLE)
	{
		props->map.map[props->player_x][props->player_y] = FLOOR;
		props->tilemap[props->player_x][props->player_y].img
			= props->images.grass;
		props->map.collectibles--;
		return ;
	}
	if (props->map.map[props->player_x][props->player_y] == EXIT
		&& props->map.collectibles == 0)
	{
		ft_printf("\nYou won!!!!!!!!!!!!");
		close_program();
	}
}

void	player_movement(t_props *props, bool horizontal, int speed)
{
	if (horizontal)
	{
		if (props->map.map[props->player_x][props->player_y + speed] == WALL)
			return ;
		props->player_y += speed;
	}
	else
	{
		if (props->map.map[props->player_x + speed][props->player_y] == WALL)
			return ;
		props->player_x += speed;
	}
	check_collison(props);
	mlx_clear_window(props->mlx.mlx_ptr, props->mlx.win_ptr);
	render_tilemap(props);
	count_steps(props);
}

int	on_key_press(int key_code, t_props *props)
{
	if (key_code == ESC)
		close_program();
	else if (key_code == W || key_code == UP)
		player_movement(props, false, -1);
	else if (key_code == A || key_code == LEFT)
		player_movement(props, true, -1);
	else if (key_code == S || key_code == DOWN)
		player_movement(props, false, 1);
	else if (key_code == D || key_code == RIGHT)
		player_movement(props, true, 1);
	return (0);
}

void	hooks(t_props *props)
{
	mlx_hook(props->mlx.win_ptr, 2, 1, on_key_press, props);
	mlx_hook(props->mlx.win_ptr, 17, (1L << 2), close_program, props);
	mlx_loop(props->mlx.mlx_ptr);
}
