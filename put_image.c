#include "mlx_linux/mlx.h"
#include "so_long.h"

			if (img->map[img->y][img->x] == '1')
				put_walls(img);
			if (img->map[img->y][img->x] == 'P')
				put_player(img);
			if (img->map[img->y][img->x] == 'C')
				put_collect(img);
			if (img->map[img->y][img->x] == 'E')
				put_exit(img);
			img->x++;

void	put_background(t_data *img)
{
	img->fd = mlx_xpm_file_to_image(img->mlx, "/images/background.xpm", &img->pixel, &img->pixel);
	mlx_put_image_to_window (img->mlx, img->mlx_win, img->fd, (img->pixel * img->x), (img->pixel * img->y));
}

void	put_walls(t_data *img)
{
	img->fd = mlx_xpm_file_to_image(img->mlx, "/images/bush_pixel.xpm", &img->pixel, &img->pixel);
	mlx_put_image_to_window (img->mlx, img->mlx_win, img->fd, (img->pixel * img->x), (img->pixel * img->y));
}

void	put_player(t_data img)
{
	img->fd = mlx_xpm_file_to_image(img->mlx, "/images/Minie_pixel.xpm", &img->pixel, &img->pixel);
	mlx_put_image_to_window (img->mlx, img->mlx_win, img->fd, (img->pixel * img->x), (img->pixel * img->y));
}

void	put_collect(t_data img)
{
	img->fd = mlx_xpm_file_to_image(img->mlx, "/images/seed_pixel.xpm", &img->pixel, &img->pixel);
	mlx_put_image_to_window (img->mlx, img->mlx_win, img->fd, (img->pixel * img->x), (img->pixel * img->y));
}

void	put_exit(t_data img)
{
	img->fd = mlx_xpm_file_to_image(img->mlx, "/images/exit_pixel.xpm", &img->pixel, &img->pixel);
	mlx_put_image_to_window (img->mlx, img->mlx_win, img->fd, (img->pixel * img->x), (img->pixel * img->y));
}