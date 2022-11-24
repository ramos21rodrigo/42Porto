/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:42:56 by roramos           #+#    #+#             */
/*   Updated: 2022/11/24 14:53:39 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	check_square(t_props *props)
{
	int	i;

	i = -1;
	while (++i < MAP.rows - 1)
		if (ft_strlen(MAP.map[i]) != MAP.columns)
			handle_errors("!square");
}

void	check_walls(t_props *props)
{
	int	i;

	if (ft_strlen(ft_strtrim(MAP.map[0], "1")) != 0 ||
	ft_strlen(ft_strtrim(MAP.map[MAP.rows - 1], "1")) != 0)
		handle_errors("WAll");
	i = 0;
	while (++i < MAP.rows - 1)
		if (MAP.map[i][0] != '1' || MAP.map[i][MAP.columns - 1] != '1')
			handle_errors("waLL");
}

int find_path(t_props *props, int x, int y, int path_finder[MAP.rows][MAP.columns], int reachable_collectible)
{
	if (MAP.map[x][y] == 'E')
		MAP.reachable_exit = true;
	if (MAP.map[x][y] == 'C' && path_finder[x][y] != 1)
		reachable_collectible ++;
	if (path_finder[x][y] == 1)
		return reachable_collectible;
	if (!(x >= 0 && x < MAP.rows && y >= 0 && y < MAP.columns && MAP.map[x][y] != '1'))
		return reachable_collectible;
	path_finder[x][y] = 1;
	reachable_collectible = find_path(props, x, y + 1, path_finder, reachable_collectible);
	reachable_collectible = find_path(props, x + 1, y, path_finder, reachable_collectible);
	reachable_collectible = find_path(props, x, y - 1, path_finder, reachable_collectible);
	reachable_collectible = find_path(props, x - 1, y, path_finder, reachable_collectible);
	return reachable_collectible;
}

void	check_path(t_props *props, int start_x_p, int start_y_p)
{
	int ij[2];
	int path_finder[MAP.rows][MAP.columns];

	ij[0] = -1;
	while (++ij[0] < MAP.rows)
	{
		ij[1] = -1;
		while (++ij[1] < MAP.columns)
			path_finder[ij[0]][ij[1]] = 0;
	}
	if(find_path(props, start_x_p, start_y_p, path_finder, 0) != MAP.amount_of_collectible)
		handle_errors("!c");
	if(!MAP.reachable_exit)
		handle_errors("!m");
}

void	check_for_icons_and_path(t_props *props)
{
	int	i;
	int	j;
	int	has[3];

	has[0] = 0;
	has[1] = 0;
	has[2] = 0;
	i = -1;
	while (++i < MAP.rows)
	{
		j = -1;
		while (++j < MAP.columns)
		{
			if (MAP.map[i][j] == 'P')
			{
				has[0] ++;
				MAP.player_x = i;
				MAP.player_y = j;
			}
			else if (MAP.map[i][j] == 'C')
			{
				MAP.amount_of_collectible ++;
				has[1]++;
			}
			else if (MAP.map[i][j] == 'E')
				has[2]++;
			else if (MAP.map[i][j] != '0' && MAP.map[i][j] != '1')
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

void	map_check(t_props *props)
{
	check_square(props);
	check_walls(props);
	check_for_icons_and_path(props);
	check_path(props, MAP.player_x, MAP.player_y);
}