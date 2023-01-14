#include "libft/libft.h"
#include "so_long.h"
#include <stdlib.h>

void	error_limit(void)
{
	ft_printf("ERROR\nThe map is not surrounded by walls.");
	exit(1);
}

void	check_limit_x(t_data *var)
{
	while ((var->x) < (var->map_width))
	{
		if (var->map[0][var->x] != '1')
		{
			error_limit();
		}
		var->x++;
	}
	var->x = 0;
	var->y = var->map_height - 1;
	while ((var->x) < (var->map_width))
	{
		if(var->map[var->y][var->x] != '1')
		{
			error_limit();
		}
		var->x++;
	}
}

void	check_limit_y(t_data *var)
{
	var->x = 0;
	var->y = 0;
	while ((var->y) < (var->map_height))
	{
		if (var->map[var->y][0] != '1')
		{
			error_limit();
		}
		var->y++;
	}
	var->x = var->map_width - 1;
	var->y = 0;
	while ((var->y) < (var->map_height))
	{
		if (var->map[var->y][var->x] != '1')
		{
			error_limit();
		}
		var->y++;
	}
}