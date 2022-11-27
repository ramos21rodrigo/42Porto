/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:05 by roramos           #+#    #+#             */
/*   Updated: 2022/11/27 17:06:31 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_props(t_props *props)
{
	props->map.map = NULL;
	props->map.rows = 0;
	props->map.columns = 0;
	props->map.collectibles = 0;
	props->map.reachable_exit = false;
	props->map.reachable_cols = 0;
	props->map.door_x = 0;
	props->map.door_y = 0;
	props->mlx.mlx_ptr = NULL;
	props->mlx.win_ptr = NULL;
	props->tilemap = NULL;
	props->player_x = 0;
	props->player_y = 0;
	props->steps = 0;
	props->images.is_left = false;
	props->images.current_player_idle = 0;
	props->images.grass = NULL;
	props->images.player_idle_1 = NULL;
	props->images.player_idle_2 = NULL;
	props->images.player_left_idle_1 = NULL;
	props->images.player_left_idle_2 = NULL;
	props->images.wall = NULL;
	props->images.collectible = NULL;
	props->images.open_door = NULL;
	props->images.close_door = NULL;
}

void	map_check(t_props *props)
{
	check_square(props);
	check_walls(props);
	check_for_icons_and_path(props);
	check_path(props);
}

void	hooks(t_props *props)
{
	mlx_loop_hook(props->mlx.mlx_ptr, render, props);
	mlx_hook(props->mlx.win_ptr, 2, 1, on_key_press, props);
	mlx_hook(props->mlx.win_ptr, 17, (1L << 2), close_program, props);
	mlx_loop(props->mlx.mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_props	props;

	if (argc != 2)
		handle_errors("Error\nInvalid amount of arguments!");
	check_ber(argv[1]);
	init_props(&props);
	get_map(&props, argv[1]);
	map_check(&props);
	props.mlx.mlx_ptr = mlx_init();
	props.mlx.win_ptr = mlx_new_window(props.mlx.mlx_ptr,
			TILES_SIZE * props.map.columns,
			TILES_SIZE * props.map.rows, "so_long");
	tilemap(&props);
	hooks(&props);
	return (0);
}
