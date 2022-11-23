/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:42:56 by roramos           #+#    #+#             */
/*   Updated: 2022/11/23 16:19:50 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	check_square(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows - 1)
		if (ft_strlen(map->map[i]) != map->columns)
			handle_errors("!square");
}

void	check_walls(t_map *map)
{
	int	i;

	if (ft_strlen(ft_strtrim(map->map[0], "1")) != 0 ||
	ft_strlen(ft_strtrim(map->map[map->rows - 1], "1")) != 0)
		handle_errors("WAll");
	i = 0;
	while (++i < map->rows - 1)
		if (map->map[i][0] != '1' || map->map[i][map->columns - 1] != '1')
			handle_errors("waLL");
}

int find_path(t_map *map, int x, int y, int path_finder[map->rows][map->columns], int reachable_collectible)
{
	if (map->map[x][y] == 'E')
		map->reachable_exit = true;
	if (map->map[x][y] == 'C' && path_finder[x][y] != 1)
		reachable_collectible ++;
	if (path_finder[x][y] == 1)
		return reachable_collectible;
	if (!(x >= 0 && x < map->rows && y >= 0 && y < map->columns && map->map[x][y] != '1'))
		return reachable_collectible;
	path_finder[x][y] = 1;
	reachable_collectible = find_path(map, x, y + 1, path_finder, reachable_collectible);
	reachable_collectible = find_path(map, x + 1, y, path_finder, reachable_collectible);
	reachable_collectible = find_path(map, x, y - 1, path_finder, reachable_collectible);
	reachable_collectible = find_path(map, x - 1, y, path_finder, reachable_collectible);
	return reachable_collectible;
}

void	check_path(t_map *map, int start_x_p, int start_y_p)
{
	int ij[2];
	int path_finder[map->rows][map->columns];

	ij[0] = -1;
	while (++ij[0] < map->rows)
	{
		ij[1] = -1;
		while (++ij[1] < map->columns)
			path_finder[ij[0]][ij[1]] = 0;
	}
	if(find_path(map, start_x_p, start_y_p, path_finder, 0) != map->amount_of_collectible)
		handle_errors("!c");
	if(!map->reachable_exit)
		handle_errors("!m");
}

void	check_for_icons_and_path(t_map *map)
{
	int	i;
	int	j;
	int	has[3];

	has[0] = 0;
	has[1] = 0;
	has[2] = 0;
	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->columns)
		{
			if (map->map[i][j] == 'P')
			{
				has[0] ++;
				map->player_x = i;
				map->player_y = j;
			}
			else if (map->map[i][j] == 'C')
			{
				map->amount_of_collectible ++;
				has[1]++;
			}
			else if (map->map[i][j] == 'E')
				has[2]++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				handle_errors("0");
		}
	}
	if (has[0] != 1)
		handle_errors("P");
	if (has[1] < 1)
		handle_errors("C");
	if (has[2] != 1)
		handle_errors("E");
}

void	map_check(t_map *map)
{
	check_square(map);
	check_walls(map);
	check_for_icons_and_path(map);
	check_path(map, map->player_x, map->player_y);
}