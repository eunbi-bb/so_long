/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 13:52:45 by eucho         #+#    #+#                 */
/*   Updated: 2023/02/24 22:32:42 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *map, int x, int y)
{
	static int tmp[1024][1024];
	
	if (tmp[y][x] == 1 || map->map[y][x] == '1')
		return ;
	else if (map->map[y][x] == 'E')
	{
		map->exit = 0;
		return ;
	}
	tmp[y][x] = 1;
	if (map->map[y][x] == 'C')
		map->collect--;
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
}

void valid_path(t_data *map)
{
	int	exit_count;
	int	collect_count;

	collect_count = map->collect;
	exit_count = map->exit;
	flood_fill (map, map->player_x, map->player_y);
	if (map->collect == 0 && map->exit == 0)
	{
		map->collect = collect_count;
		map->exit = exit_count;
	}
	else
	{
		ft_printf("There is no valid path in the map.\n");
		exit(1);
	}
}
