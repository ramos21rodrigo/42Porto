/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:42:56 by roramos           #+#    #+#             */
/*   Updated: 2022/11/22 19:08:36 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	check_square(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows - 1)
		if (ft_strlen(map->map[i]) != map->column)
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
		if ((map->column - 2) < ft_strlen(ft_strtrim(map->map[i], "1")))
			handle_errors("waLL");
}

void	check_for_icons(t_map *map)
{
	int	i;
	int	j;
	int	has[3];

	has = {0 , 0 , 0 };
	i = -1;
	while (++i < map->column)
	{
		j = -1;
		while (++j < map->rows)
		{
			if (map->map[i][j] == 'P')
				has[0] ++;
				
		}
	}
}

void	map_check(t_map *map)
{
	check_square(map);
	check_walls(map);
	check_for_icons(map);
}