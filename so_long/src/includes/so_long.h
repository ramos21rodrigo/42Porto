/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:48 by roramos           #+#    #+#             */
/*   Updated: 2022/11/25 18:36:44 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include "../../mlx/mlx.h"
# include "libft.h"
# include "key_map.h"

# define TILES_SIZE 64
# define FLOOR_TILE "./assets/black_square.xpm"
# define WALL_TILE "./assets/wall.xpm"
# define PLAYER_TILE "./assets/player.xpm"
# define COLLECTIBLE_TILE "./assets/collectible.xpm"

typedef struct s_map {
	char	**map;
	int		rows;
	int		columns;
	int		collectibles;
	int		reachable_cols;
	bool	reachable_exit;
}				t_map;

typedef struct s_images
{
	void	*grass;
	void	*wall;
	void	*player;
	void	*collectible;

}				t_images;

typedef struct s_tilemap
{
	void	*img;
}				t_tilemap;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct s_props
{
	struct s_map		map;
	struct s_mlx		mlx;
	struct s_images		images;
	struct s_tilemap	**tilemap;

	int					steps;
	int					player_x;
	int					player_y;
}				t_props;

void	get_map(t_props *props, char *map_file);
void	map_check(t_props *props);
void	handle_errors(char *message);
void	hooks(t_props *props);
int	close_program(void);
void	render_tilemap(t_props *props);
void	count_steps(t_props *props);
void	tilemap(t_props *props);
void	render_tilemap(t_props *props);
void	check_for_errors_in_icons(t_props *props, int p, int e);

#endif