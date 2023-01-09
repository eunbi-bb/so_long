#include "mlx_linux/mlx.h"
#include <stdio.h>

#define KEY_ESC				65307
#define KEY_W				119
#define KEY_S				115
#define KEY_A				97
#define KEY_D				100

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*c;
	void	*g;
	void	*w;
	size_t	fd;
	int		x;
	int		y;
	int		wi;
	int		he;
	int		win_width;
	int		win_height;
}	t_param;

int	key_press(int keycode, t_param *param)
// 입력에따라 좌표로 사용할 값을 증감시킴
{
	if (keycode == KEY_W && param->y != 0)
		param->y -= param->he;
	if (keycode == KEY_S && param->y != 480)
		param->y += param->he;
	else if (keycode == KEY_A && param->x != 0)
		param->x -= param->wi;
	else if (keycode == KEY_D && param->x != 480)
		param->x += param->wi;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", param->y, param->x);
	return (0);
}

int	draw(t_param *loc)
{
	mlx_clear_window(loc->mlx, loc->win); //기존에 그려놨던 윈도우를 지워줌
	mlx_put_image_to_window(loc->mlx, loc->win, loc->c, loc->x, loc->y);
    //새로운 좌표를 이용한 새 위치에 이미지를 그려줌
	return (0);
}

int	main(void)
{
	t_param		par;

	par.mlx = mlx_init();
	par.c = mlx_xpm_file_to_image(par.mlx, "images/Minie_pixel.xpm", &par.wi, &par.he);
	par.win = mlx_new_window(par.mlx, 1000, 1000, "DrawMap");
	par.x = 0;
	par.y = 0;
	mlx_key_hook(par.win, &key_press, &par);
    //키보드 입력을 받아줌
	mlx_loop_hook(par.mlx, &draw, &par);
    //이미지를 지우고 다시 그려주는 draw함수를 이벤트마다 실행해줌
	mlx_loop(par.mlx);
	return (0);
}