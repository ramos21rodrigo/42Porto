/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:48 by roramos           #+#    #+#             */
/*   Updated: 2022/11/24 19:04:40 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include "../../mlx/mlx.h"
# include "libft.h"

# define MAP props->map
# define MLX props->mlx

# define TILES_SIZE 64
# define FLOOR_TILES "./assets/black_square.xpm"
# define WALL_TILES "./assets/wall.xpm"
# define PLAYER_TILES "./assets/cropped_1.xpm"

typedef struct s_map {
	char	**map;
	int		rows;
	int		columns;
	int		amount_of_collectible;
	int		player_x;
	int		player_y;
	bool	reachable_exit;
}				t_map;

typedef struct s_images
{
	void	*grass;
	void	*wall;
	void	*popo;
}				t_images;


typedef struct s_tilemap
{
	void	*img;
}				t_tilemap;

typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}              t_mlx;

typedef struct s_props
{
    struct s_map		map;
	struct s_mlx		mlx;
	struct s_images		images;
	struct s_tilemap	**tilemap;
	
}              t_props;

void	get_map(t_props *props, char *map_file);
void    map_check(t_props *props);
void    handle_errors(char *message);

#endif