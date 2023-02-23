/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_map_images.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 11:02:32 by eucho         #+#    #+#                 */
/*   Updated: 2023/02/23 20:29:11 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

void	background(t_data *img)
{
	img->y = 0;
	img->file = mlx_xpm_file_to_image(img->mlx, "images/background.xpm",
			&img->pixel, &img->pixel);
	while ((img->y) < (img->map_height))
	{
		img->x = 0;
		while ((img->x) < (img->map_width))
		{
			mlx_put_image_to_window (img->mlx, img->win, img->file,
				(img->pixel * img->x), (img->pixel * img->y));
			img->x++;
		}
		img->y++;
	}
}

int	remaining_collect(t_data *img)
{
	int	i;

	i = 0;
	img->y = 0;
	while ((img->y) < (img->map_height))
	{
		img->x = 0;
		while ((img->x) < (img->map_width))
		{
			if (img->map[img->y][img->x] == 'C')
			{
				i++;
			}
			img->x++;
		}
		img->y++;
	}
	return (i);
}

void	put_map_images(t_data *img)
{
	background(img);
	img->collect = remaining_collect(img);
	img->y = 0;
	while ((img->y) < (img->map_height))
	{
		img->x = 0;
		while ((img->x) < (img->map_width))
		{
			if (img->map[img->y][img->x] == '1')
				put_walls(img);
			else if (img->map[img->y][img->x] == 'P')
				put_player(img);
			else if (img->map[img->y][img->x] == 'C')
				put_collect(img);
			else if (img->map[img->y][img->x] == 'E')
				put_exit(img);
			img->x++;
		}
		img->y++;
	}
	if (img->count_move > 0)
		ft_printf("STEPS: %d\n", img->count_move);
}
