#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <fcntl.h>

void	set_data(t_data *var)
{
	var->map_size = 0;
	var->map_width = 0;
	var->map_height = 0;
	var->x = 0;
	var->y = 0;
	var->pixel = 0;
	var->player = 0;
	var->player_dir = "images/Minie_pixel_R.xpm";
	var->count_move = 0;
	var->count_start = 0;
	var->count_collect = 0;
	var->count_exit = 0;
}
