/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:05 by roramos           #+#    #+#             */
/*   Updated: 2022/11/25 18:33:26 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_props(t_props *props)
{
	props->map.map = NULL;
	props->map.rows = 0;
	props->map.columns = 0;
	props->map.collectibles = 0;
	props->map.reachable_exit = true;
	props->map.reachable_cols = 0;
	props->mlx.mlx_ptr = NULL;
	props->mlx.win_ptr = NULL;
	props->tilemap = NULL;
	props->player_x = 0;
	props->player_y = 0;
	props->steps = 0;
	props->images.grass = NULL;
	props->images.player = NULL;
	props->images.wall = NULL;
	props->images.collectible = NULL;
}

int	main(int argc, char *argv[])
{
	t_props	props;

	if (argc != 2)
		handle_errors("!args");
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

/* clear && cc src/includes/libft.h src/includes/so_long.h 
src/includes/key_map.h  src/hooks.c src/main.c src/map_check.c 
src/map_get.c src/tilemap.c src/utils.c  libft.a -L ./mlx -lmlx 
-Ilmlx -lXext -lX11 && ./a.out tests/map1.ber */
