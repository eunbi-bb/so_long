#include "mlx_linux/mlx.h"
#include "so_long.h"

#define KEY_ESC				65307
#define KEY_W				119
#define KEY_S				115
#define KEY_A				97
#define KEY_D				100

int	key_hook(int keycode, t_data *vars)
{
	printf("%d\n", keycode);
	if(keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int exit_hook()
{
	exit(0);
}
