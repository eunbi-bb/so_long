#ifndef SO_LONG_H
# define SO_LONG_H

#include <sys/stat.h> /*open()*/
#include <unistd.h> /*close(), read() and write()*/
#include <stdlib.h> /*malloc(), free() and exit()*/
#include <stdio.h> /*perror()*/
#include <string.h> /*strerror()*/

typedef struct s_data{
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		fd;
	int		map;
	int		count_exit;
	int		count_start;
	int		count_collect;
	int		win_width;
	int		win_height;
	int		count_move;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_ground;
	void	*img_exit;
	void	*img_player;
	void	*img_wall;
	void	*img_collect;
	int		img_width;
	int		img_height;
	char	*addr;
}				t_data;

#endif