#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>


void	window(t_data *window)
{
	// int win_width;
	// int win_height;

	// window->pixel = 50;
	// win_width = window->pixel * window->map_width;
	// win_height = window->pixel * window->map_height;
	// window->mlx = mlx_init();
	// window->win = mlx_new_window(window->mlx, win_width, win_height, "so_long");
	// mapping(window);
	window->pixel = 80;
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->pixel * window->map_width, window->pixel * window->map_height, "so_long");
	mapping(window);
}

void	open_map(char **argv, t_data *map)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR!\nCan not load a map.\n");
		exit(1);
	}
	buffer = complete_map(fd);
	check_components(buffer, map);
	map->map = ft_split(buffer, '\n'); // checke if I can use gnl
	while (map->map[0][i] != '\0')
	{
		map->map_width++;
		i++;
	}
	check_map(buffer, map);
	close(fd);
}

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("ERORR\nNumber of arguments should be 2.");
		exit(0);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_printf("Error\nInavlid filename extension");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data game;

	check_arg(argc, argv);
	set_data(&game);
	open_map(argv, &game);
	window(&game);
	mlx_hook(game.win, 2, 1L << 0, finish, &game);
	mlx_hook(game.win, QUIT, LeaveWindowMask, close_window, &game); // Cross button
	mlx_key_hook(game.win, ESC_hook, &game); // ESC key
	mlx_loop(game.mlx);
	exit(0);
	return(0);
}
