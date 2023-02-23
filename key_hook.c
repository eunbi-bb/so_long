/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 09:14:15 by eucho         #+#    #+#                 */
/*   Updated: 2023/02/23 20:12:11 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	up(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y - 1][move->player_x] = 'P';
	move->count_move++;
	put_map_images(move);
}

void	down(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y + 1][move->player_x] = 'P';
	move->count_move++;
	put_map_images(move);
}

void	left(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y][move->player_x - 1] = 'P';
	move->player_dir = "images/Minie_pixel_L.xpm";
	move->count_move++;
	put_map_images(move);
}

void	right(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y][move->player_x + 1] = 'P';
	move->player_dir = "images/Minie_pixel_R.xpm";
	move->count_move++;
	put_map_images(move);
}

int	key_press(int keyhook, t_data *move)
{
	
	char	player_up;
	char	player_down;
	char	player_left;
	char	player_right;

	player_up = move->map[move->player_y - 1][move->player_x];
	player_down = move->map[move->player_y + 1][move->player_x];
	player_left = move->map[move->player_y][move->player_x - 1];
	player_right = move->map[move->player_y][move->player_x + 1];
	if (move->collect == 0 && ((keyhook == UP && player_up == 'E')
			|| (keyhook == LEFT && player_left == 'E')
			|| (keyhook == DOWN && player_down == 'E')
			|| (keyhook == RIGHT && player_right == 'E')))
		close_window(move);
	if (keyhook == UP && player_up != '1' && player_up != 'E')
		up(move);
	if (keyhook == LEFT && player_left != '1' && player_left != 'E')
		left(move);
	if (keyhook == DOWN && player_down != '1' && player_down != 'E')
		down(move);
	if (keyhook == RIGHT && player_right != '1' && player_right != 'E')
		right(move);
	return (0);
}
