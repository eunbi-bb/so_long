#include "mlx_linux/mlx.h"
#include <stdio.h>

#define KEY_W				119
#define KEY_S				115
#define KEY_A				97
#define KEY_D				100
#define KEY_ESC				65307
#define CROSS_BUTTON		17

typedef struct s_data{
	int		x;
	int		y;
}				t_data;
// 값을 저장할 구조체
void	data_init(t_data *xy)
{
	xy->x = 0;
	xy->y = 0;
}
// 구조체를 생성하고 값을 초기설정 해줌
int	key_press(int keycode, t_data *xy)
{
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)//WSAD를 눌렀을때
	{
		xy->x++;
		printf("x: %d\n", xy->x);
	}
	else if (keycode == KEY_ESC) //ESC를 눌렀을때
		exit(0);
	return (0);
}

int	win_close(void)
{
	exit(0);
	return (0);
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_data		xy;

	data_init(&xy); // 구조체 값 초기설정
	mlx = mlx_init(); // mlx포인터 생성
	win = mlx_new_window(mlx, 500, 500, "key test");
    // 500x500 사이즈의 윈도우 띄우기
	printf("-------------------------------\n");
	printf("Movements\n");
	mlx_key_hook(win, &key_press, &xy);
    // 키보드의 입력을 받아 keypress 함수를 실행시키고 xy의 매개변수를 활용함
    mlx_hook(win, CROSS_BUTTON, 0, &close, &xy);
    // 여러 종류의 입력을 받아 함수를 실행시킴
    // 17은 좌측상단의 끄기버튼을 눌렀을때 실행하도록 설정해줌
	mlx_loop(mlx);
    // 계속해서 키보드 입력을 받을 수 있도록 무한루프
}