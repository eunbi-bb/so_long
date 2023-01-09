#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

void	background(t_data *img)
{
	img->y = 0;
	while ((img->y) < (img->map_height))
	{
		img->x = 0;
		while ((img->x) < (img->map_width))
		{
			img->fd = mlx_xpm_file_to_image(img->mlx, "/images/background.xpm", &img->pixel, &img->pixel);
			mlx_put_image_to_window (img->mlx, img->win, img->fd, (img->pixel * img->x), (img->pixel *img->y));
			img->x++;
		}
	}
	img->y++;
}

int	collect_total(t_data *img)
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

void mapping(t_data *img)
{
	img->collect = collect_total(img);
	background(img);
	img->y = 0;
	while ((img->y) < (img->map_height))
	{
		img->x = 0;
		while ((img->x) < (img->map_width))
		{
			if (img->map[img->y][img->x] == '1')
				put_walls(img);
			if (img->map[img->y][img->x] == 'P')
				put_player(img);
			if (img->map[img->y][img->x] == 'C')
				put_collect(img);
			if (img->map[img->y][img->x] == 'E')
				put_exit(img);
			img->x++;
		}
		img->y++;
	}
}