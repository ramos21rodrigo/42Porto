/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <roramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:48 by roramos           #+#    #+#             */
/*   Updated: 2022/11/29 16:08:43 by roramos          ###   ########.fr       */
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
# define FPS 9000	
# define FLOOR_TILE "./assets/background.xpm"
# define WALL_TILE "./assets/wall.xpm"
# define PLAYER_IDLE_1_TILE "./assets/right_player_idle_1.xpm"
# define PLAYER_IDLE_2_TILE "./assets/right_player_idle_2.xpm"
# define PLAYER_LEFT_IDLE_1_TILE "./assets/left_player_idle_1.xpm"
# define PLAYER_LEFT_IDLE_2_TILE "./assets/left_player_idle_2.xpm"
# define COLLECTIBLE_TILE "./assets/collectible.xpm"
# define OPEN_DOOR_TILE "./assets/open_door.xpm"
# define CLOSE_DOOR_TILE "./assets/close_door.xpm"

typedef struct s_map {
	char	**map;
	int		rows;
	int		columns;
	int		collectibles;
	int		reachable_cols;
	int		door_x;
	int		door_y;
	bool	reachable_exit;
}				t_map;

typedef struct s_images
{
	int		current_player_idle;
	bool	is_left;

	void	*grass;
	void	*wall;
	void	*player_idle_1;
	void	*player_idle_2;
	void	*player_left_idle_1;
	void	*player_left_idle_2;
	void	*collectible;
	void	*open_door;
	void	*close_door;
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

void	check_ber(char *filename, t_props *props);
void	get_map(t_props *props, char *map_file);
void	check_square(t_props *props);
void	check_walls(t_props *props);
void	find_path(t_props *props, int x, int y, int **path_finder);
void	check_path(t_props *props);
void	check_for_icons_and_path(t_props *props);
void	map_check(t_props *props);
void	handle_errors(char *message, t_props *props);
void	hooks(t_props *props);
int		render(t_props *props);
int		on_key_press(int key_code, t_props *props);
int		close_program(t_props *props);
void	render_tilemap(t_props *props);
void	count_steps(t_props *props);
void	tilemap(t_props *props);
void	render_tilemap(t_props *props);
void	find_position_of(t_props *props);
void	check_for_errors_in_icons(t_props *props, int p, int e);

#endif