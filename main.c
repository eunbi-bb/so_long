#include "mlx_linux/mlx.h"

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "Hello World");
	mlx_loop(mlx);

	return (0);
}