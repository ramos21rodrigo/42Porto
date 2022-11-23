/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:45:48 by roramos           #+#    #+#             */
/*   Updated: 2022/11/23 15:51:58 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>

typedef struct map {
	char	**map;
	int		rows;
	int		columns;
	int		amount_of_collectible;
	int		player_x;
	int		player_y;
	bool	reachable_exit;
}				t_map;

t_map	*get_map(char *map_file);
void    map_check(t_map *map);
void    handle_errors(char *message);

#endif