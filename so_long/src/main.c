/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:05 by roramos           #+#    #+#             */
/*   Updated: 2022/11/23 18:08:49 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "../mlx/mlx.h"

int main(int argc, char *argv[])
{
    t_map	*map;
    void	*mlx;
	void	*img;
    void	*win;
	char	*relative_path = "./assets/global.xpm";
	int		img_width = 2000;
	int		img_height = 2000;

    if (argc != 2)
        handle_errors("!args"); 
	map = get_map(argv[1]);
    map_check(map);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 900,600, "cona");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	printf("%s", relative_path);
	mlx_put_image_to_window(mlx, win, img, 4,4);
	mlx_loop(mlx);
    return 0;
}

// cc src/*.h -L ./mlx -lmlx -Ilmlx -lXext -lX11
