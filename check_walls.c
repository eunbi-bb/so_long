/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_walls.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 09:13:16 by eucho         #+#    #+#                 */
/*   Updated: 2023/02/20 11:48:43 by eucho         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	error_walls(void)
{
	ft_printf("ERROR\nThe map is not surrounded by walls.");
	exit(1);
}

// void	move_error(t_data *move)
// {
// 	char	player_up;
// 	char	player_down;
// 	char	player_left;
// 	char	player_right;

// 	player_up = move->map[move->player_y - 1][move->player_x];
// 	player_down = move->map[move->player_y + 1][move->player_x];
// 	player_left = move->map[move->player_y][move->player_x - 1];
// 	player_right = move->map[move->player_y][move->player_x + 1];
// 	if ()
// }

void	check_walls_x(t_data *var)
{
	int	x;
	int	y;

	x = 0;
	y = var->map_height - 1;
	while (x < (var->map_width))
	{
		if (var->map[0][x] != '1' || var->map[y][x] != '1')
		{
			error_walls();
		}
		x++;
	}
}

void	check_walls_y(t_data *var)
{
	int	x;
	int	y;

	x = var->map_width - 1;
	y = 0;
	while ((y) < (var->map_height))
	{
		if (var->map[y][0] != '1' || var->map[y][x] != '1')
		{
			error_walls();
		}
		y++;
	}
}
