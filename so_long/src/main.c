/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:05 by roramos           #+#    #+#             */
/*   Updated: 2022/11/24 19:04:59 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void    init_props(t_props *props)
{
	MAP.map=NULL;
	MAP.rows=0;
	MAP.columns=0;
	MAP.amount_of_collectible=0;
	MAP.player_x=0;
	MAP.player_y=0;
	MAP.reachable_exit=true;
	MLX.mlx_ptr = NULL;
	MLX.win_ptr = NULL;
	props->tilemap=NULL;
	props->images.grass = NULL;
}

void    open_image(t_props *props)
{
	int     img_size;

	img_size = 48;
	props->images.grass = mlx_xpm_file_to_image(
			MLX.mlx_ptr, FLOOR_TILES, &img_size, &img_size);
	props->images.wall = mlx_xpm_file_to_image(
			MLX.mlx_ptr, WALL_TILES, &img_size, &img_size);
	props->images.popo = mlx_xpm_file_to_image(
			MLX.mlx_ptr, PLAYER_TILES, &img_size, &img_size);
}

void    create_tilemap(t_props *props)
{
	int i;
	int	j;

	props->tilemap = (t_tilemap **)malloc(1  + MAP.rows * sizeof(t_tilemap *));
	if(!props->tilemap)
		handle_errors("!tilemap");
	i = -1;
	while(++i < MAP.rows)
	{
		props->tilemap[i] = (t_tilemap *)malloc(1 + MAP.columns * sizeof(t_tilemap));
		if(!props->tilemap)
			handle_errors("!tilemap");
		j = -1;
		while (++j < MAP.columns)
		{   
			if (MAP.map[i][j] == '0')
				props->tilemap[i][j].img = props->images.grass;
			else if(MAP.map[i][j] == '1')
				props->tilemap[i][j].img = props->images.wall;
			else 
				props->tilemap[i][j].img = props->images.popo;

		}
	}
}

void put_tiles_on_screen(t_props *props)
{
	int	i;
	int	j;	

	i = -1;
	while (++i < MAP.rows)
	{
		j = -1;
		while (++j < MAP.columns)
			mlx_put_image_to_window(MLX.mlx_ptr, MLX.win_ptr, props->tilemap[i][j].img, TILES_SIZE * j, TILES_SIZE * i);
	}

}


int main(int argc, char *argv[])
{
	t_props	props;
	
	if (argc != 2)
		handle_errors("!args"); 
	init_props(&props);
	get_map(&props, argv[1]);
	map_check(&props);
	props.mlx.mlx_ptr = mlx_init();
	props.mlx.win_ptr = mlx_new_window(props.mlx.mlx_ptr, TILES_SIZE * props.map.columns , TILES_SIZE * props.map.rows, "so_long");
	open_image(&props);
	create_tilemap(&props);
	put_tiles_on_screen(&props);
	mlx_loop(props.mlx.mlx_ptr);
	return 0;
}

// cc src/*.h -L ./mlx -lmlx -Ilmlx -lXext -lX11
