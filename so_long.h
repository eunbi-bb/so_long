#ifndef SO_LONG_H
# define SO_LONG_H

#include <sys/stat.h> /*open()*/
#include <unistd.h> /*close(), read() and write()*/
#include <stdlib.h> /*malloc(), free() and exit()*/
#include <stdio.h> /*perror()*/
#include <string.h> /*strerror()*/

typedef struct s_data{
	char	*fd;
	void	*mlx;
	void	*win;
	char	**map;
	int		map_size;
	int		map_height;
	int		map_width;
	int		pixel;
	int		x;
	int		y;
	int		player;
	int		player_x;
	int		player_y;
	int		player_mov;
	char	player_dir;
	int		collect;
	int		count_exit;
	int		count_start;
	int		count_collect;
	int		count_move;
}				t_data;

#endif
	// int		win_width;
	// int		win_height;
	// void	*img;
	// void	*img_ground;
	// void	*img_exit;
	// void	*img_player;
	// void	*img_wall;
	// void	*img_collect;
	// int		img_width;
	// int		img_height;
	// char	*addr;