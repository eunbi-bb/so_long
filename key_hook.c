#include "mlx_linux/mlx.h"
#include "so_long.h"

int	ESC_hook(int keycode, t_data *vars)
{
	if(keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	close_window(t_data *win)
{
	mlx_destroy_window(win->mlx, win->win);
	exit(1);
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
	move->count_move++;
	mapping(move);
}

void	down(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y + 1][move->player_x] = 'P';
	move->count_move++;
	mapping(move);
}

void	left(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y][move->player_x - 1] = 'P';
	move->player_dir = "images/Minie_pixel_L.xpm";
	move->count_move++;
	mapping(move);
}

void	right(t_data *move)
{
	move->map[move->player_y][move->player_x] = '0';
	move->map[move->player_y][move->player_x + 1] = 'P';
	move->player_dir = "images/Minie_pixel_R.xpm";
	move->count_move++;
	mapping(move);
}

int	finish(int keyhook, t_data *move)
{
	char	playerUp = move->map[move->player_y - 1][move->player_x];
	char	playerDown = move->map[move->player_y + 1][move->player_x];
	char	playerLeft = move->map[move->player_y][move->player_x - 1];
	char	playerRight = move->map[move->player_y][move->player_x + 1];


	if (move->collect == 0
		&& ((keyhook == UP && playerUp == 'E')
		|| (keyhook == LEFT && playerLeft == 'E')
		|| (keyhook == DOWN && playerDown == 'E')
		|| (keyhook == RIGHT && playerRight == 'E')))
	{
		ft_printf("\n*-------------------*\n");
		ft_printf("|      FINISH       |\n");
		ft_printf("|  Good Job Minie!  |\n");
		ft_printf("*-------------------*\n\n");
		close_window(move);
	}
	if (keyhook == UP && playerUp != '1' && playerUp != 'E')
		up(move);
	if (keyhook == LEFT && playerLeft != '1' && playerLeft != 'E')
		left(move);
	if (keyhook == DOWN && playerDown != '1' && playerDown != 'E')
		down(move);
	if (keyhook == RIGHT && playerRight != '1' && playerRight != 'E')
		right(move);
	return (0);
}

