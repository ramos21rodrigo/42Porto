/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:06:09 by roramos           #+#    #+#             */
/*   Updated: 2022/11/27 18:43:29 by roramos          ###   ########.fr       */
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
		if (!--props->map.collectibles)
			props->tilemap[props->map.door_x][props->map.door_y].img
				= props->images.open_door;
		return ;
	}
	if (props->map.map[props->player_x][props->player_y] == EXIT
		&& props->map.collectibles == 0)
	{
		ft_printf("\n\nYou won!");
		ft_printf(" In the state of this life you don't need enemies!");
		close_program();
	}
}

void	player_movement(t_props *props, bool horizontal, int speed)
{
	if (horizontal)
	{
		if (speed < 0)
			props->images.is_left = true;
		else
			props->images.is_left = false;
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

void	animate_doggo(t_props *props)
{
	void	*current_player;

	if (!props->images.current_player_idle)
	{
		if (props->images.is_left)
			current_player = props->images.player_left_idle_1;
		else
			current_player = props->images.player_idle_1;
		props->images.current_player_idle = 1;
	}
	else
	{
		if (props->images.is_left)
			current_player = props->images.player_left_idle_2;
		else
			current_player = props->images.player_idle_2;
		props->images.current_player_idle = 0;
	}
	mlx_put_image_to_window(props->mlx.mlx_ptr, props->mlx.win_ptr,
		current_player, TILES_SIZE * props->player_y,
		TILES_SIZE * props->player_x);
}

int	render(t_props *props)
{
	static int	frames;

	if (++frames < FPS)
		return (0);
	frames = 0;
	mlx_clear_window(props->mlx.mlx_ptr, props->mlx.win_ptr);
	render_tilemap(props);
	animate_doggo(props);
	mlx_string_put(props->mlx.mlx_ptr, props->mlx.win_ptr,
		TILES_SIZE * props->player_y + 30
		- (ft_strlen(ft_itoa(props->steps)) * 2),
		TILES_SIZE * props->player_x + 52, -1, ft_itoa(props->steps));
	return (0);
}
