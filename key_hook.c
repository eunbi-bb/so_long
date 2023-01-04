#include "mlx_linux/mlx.h"
#include "so_long.h"

#define KEY_ESC	65307
#define UP 2
#define DOWN 1
#define LEFT 
#define RIGHT 2


int	key_hook(int keycode, t_vars *vars)
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

void	up(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y - 1][move->player_x] = 'P';
	move->player_mov++;
	fill_window(move);
}

void	down(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y + 1][move->player_x] = 'P';
	move->player_mov++;
	fill_window(move);
}

void	left(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y][move->player_x - 1] = 'P';
	move->player_mov++;
	fill_window(move);
}

void	right(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y][move->player_x + 1] = 'P';
	move->player_mov++;
	fill_window(move);
}

int	finish(int	keyhook, t_data *move)
{
	if (move->collect == 0
	&& ((keyhook == UP && move->map[move->player_y - 1][move->player_x] = 'E')
	|| (keyhook == DOWN && move->map[move->player_y + 1][move->player_x] = 'E')
	|| (keyhook == LEFT && move->map[move->player_y][move->player_x - 1] = 'E')
	|| (keyhook == RIGHT && move->map[move->player_y][move->player_x +1] = 'E')))
	{
		ft_printf("FINISH\n Good Job Minie!");
		mlx_key_hook(game.win, key_hook, &move);
	}
	return (0);
}

