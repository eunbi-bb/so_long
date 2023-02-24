/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 11:04:01 by eucho         #+#    #+#                 */
/*   Updated: 2023/02/24 22:28:00 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>

void	window(t_data *window)
{
	window->pixel = 80;
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx,
			(window->pixel * window->map_width),
			(window->pixel * window->map_height), "so_long");
	put_map_images(window);
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
	map->map = ft_split(buffer, '\n');
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
		ft_printf("ERROR\nTwo arguments are expected. eg.'./so_long *.ber.'");
		exit(1);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_printf("Error\nInvalid filename extension, .ber expected.");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	game;

	check_arg(argc, argv);
	set_data(&game);
	open_map(argv, &game);
	window(&game);
	valid_path(&game);
	mlx_hook(game.win, 02, 1L << 0, key_press, &game);
	mlx_hook(game.win, QUIT, 1L << 5, close_window, &game);
	mlx_key_hook(game.win, esc_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
