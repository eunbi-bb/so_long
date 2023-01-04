#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <fcntl.h>

void	set_data(t_data *var)
{
	var->map_area = 0;
	var->map_width = 0;
	var->map_height = 0;
	var->x = 0;
	var->y = 0;
	var->pixel = 0;
	var->player = 0;
	var->player_dir = 0;
	var->count_move = 0;
	var->count_start = 0;
	var->count_collect = 0;
	var->count_exit = 0;
	var->img_ground = mlx_xpm_file_to_image(var->mlx, "images/background.xpm", &var->win_width, &var->win_height);
	var->img_exit = mlx_xpm_file_to_image(var->mlx, "images/exit_pixel.xpm", &var->win_width, &var->win_height);
	var->img_player = mlx_xpm_file_to_image(var->mlx, "images/Minie_pixel.xpm", &var->win_width, &var->win_height);
	var->img_wall = mlx_xpm_file_to_image(var->mlx, "images/bush_pixel.xpm", &var->win_width, &var->win_height);
	var->img_collect = mlx_xpm_file_to_image(var->mlx, "images/seed_pixel.xpm", &var->win_width, &var->win_height);
}
