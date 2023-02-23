/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 11:09:54 by eucho         #+#    #+#                 */
/*   Updated: 2023/02/23 20:28:18 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<sys/stat.h>/*open()*/
# include<unistd.h>/*close(), read() and write()*/
# include<stdlib.h>/*malloc(), free() and exit()*/
# include<stdio.h>
# include<string.h>/*strerror()*/
# include"libft/libft.h"

#define KEY_ESC	65307
#define	QUIT 17
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

typedef struct s_data{
	char	*file;
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
	char	*player_dir;
	int		collect;
	int		exit;
	int		count_move;
}				t_data;

void	window(t_data *window);
void	open_map(char **argv, t_data *map);
void	check_arg(int argc, char **argv);
int		close_window(t_data *win);

void	set_data(t_data *var);

void	put_background(t_data *img);
void	put_walls(t_data *img);
void	put_player(t_data *img);
void	put_collect(t_data *img);
void	put_exit(t_data *img);

void	background(t_data *img);
int		collect_total(t_data *img);
void	put_map_images(t_data *img);

int		map_line(char *str, t_data *var);
void	freemap(t_data *var);
int		draw_map(t_data *var);

void	check_map(char *buf, t_data *map);
void	check_components(char *buf, t_data *comp);
char	*join_line(char *line, char c);
int		check_line(char *line);
void	read_map(char *file, t_data *map);
char	*complete_map(int fd);

int		esc_hook(int keycode, t_data *vars);;
void	up(t_data *move);
void	down(t_data *move);
void	left(t_data *move);
void	right(t_data *move);
int		key_press(int keyhook, t_data *move);

void	error_walls(void);
void	check_walls_x(t_data *var);
void	check_walls_y(t_data *var);

void	flood_fill(t_data *map, int x, int y);
void	valid_path(t_data *map);

#endif