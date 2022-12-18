#include <unistd.h>
#include <stdlib.h>
#include "mlx_linux/mlx.h"
#include <stdio.h>

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if(keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars vars;
	t_data image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World");
	image.img = mlx_new_image(vars.mlx, 500, 500);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	for (int i = 0 ; i < 500 ; i++)
	{
		for (int j = 0 ; j < 500 ; j++)
		{
			my_mlx_pixel_put(&image, i, j, 0x00FFFFFF);
		}	
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars); // esc key press event
	mlx_loop(vars.mlx);

	return (0);
}