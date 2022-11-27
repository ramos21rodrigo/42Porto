/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:32:43 by roramos           #+#    #+#             */
/*   Updated: 2022/11/26 18:42:44 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	open_image(t_props *props)
{
	int	img_size;

	img_size = 64;
	props->images.grass = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, FLOOR_TILE, &img_size, &img_size);
	props->images.wall = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, WALL_TILE, &img_size, &img_size);
	props->images.player_idle_1 = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, PLAYER_IDLE_1_TILE, &img_size, &img_size);
	props->images.player_idle_2 = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, PLAYER_IDLE_2_TILE, &img_size, &img_size);
	props->images.player_left_idle_1 = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, PLAYER_LEFT_IDLE_1_TILE, &img_size, &img_size);
	props->images.player_left_idle_2 = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, PLAYER_LEFT_IDLE_2_TILE, &img_size, &img_size);
	props->images.collectible = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, COLLECTIBLE_TILE, &img_size, &img_size);
	props->images.open_door = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, OPEN_DOOR_TILE, &img_size, &img_size);
	props->images.close_door = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, CLOSE_DOOR_TILE, &img_size, &img_size);
}

void	create_tilemap(t_props *props)
{
	int	i;
	int	j;

	props->tilemap = malloc(1 + props->map.rows * sizeof(t_tilemap *));
	if (!props->tilemap)
		handle_errors("!tilemap");
	i = -1;
	while (++i < props->map.rows)
	{
		props->tilemap[i] = malloc(1 + props->map.columns * sizeof(t_tilemap));
		if (!props->tilemap)
			handle_errors("!tilemap");
		j = -1;
		while (++j < props->map.columns)
		{
			if (props->map.map[i][j] == WALL)
				props->tilemap[i][j].img = props->images.wall;
			else if (props->map.map[i][j] == EXIT)
				props->tilemap[i][j].img = props->images.close_door;
			else if (props->map.map[i][j] == COLLECTIBLE)
				props->tilemap[i][j].img = props->images.collectible;
			else
				props->tilemap[i][j].img = props->images.grass;
		}
	}
}

void	render_tilemap(t_props *props)
{
	int	i;
	int	j;	

	i = -1;
	while (++i < props->map.rows)
	{
		j = -1;
		while (++j < props->map.columns)
		{
			if (i != props->player_x || j != props->player_y)
				mlx_put_image_to_window(props->mlx.mlx_ptr, props->mlx.win_ptr,
					props->tilemap[i][j].img, TILES_SIZE * j, TILES_SIZE * i);
		}
	}
}

void	tilemap(t_props *props)
{
	open_image(props);
	create_tilemap(props);
	render_tilemap(props);
}
