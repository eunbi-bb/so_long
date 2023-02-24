/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 09:25:40 by eucho         #+#    #+#                 */
/*   Updated: 2023/02/24 22:19:38 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	check_map(char *buf, t_data *map)
{
	if (map->map_height > 1024 || map->map_width > 1024)
	{
		ft_printf("ERROR\nMaximum width and heigth is 1024.\n");
		exit(1);
	}
	map->map_size = ft_strlen(buf) - map->map_height;
	if (map->map_size != map->map_width * map->map_height)
	{
		ft_printf("ERROR\n The map size is invalid.\n");
		exit(1);
	}
	check_walls_x(map);
	check_walls_y(map);
}

void	map_error(char *buf, t_data *comp)
{
	if (!buf[0])
	{
		ft_printf("ERROR\nIt is an empty file\n.");
		exit(0);
	}
	if (comp->player != 1)
	{
		ft_printf("ERROR\nOnly one player is allowed.\n");
		exit(1);
	}
	if (comp->collect < 1)
	{
		ft_printf("ERORR\nCollects should be at least one.\n");
		exit(1);
	}
	if (comp->exit != 1)
	{
		ft_printf("ERROR\nOnly one exit is allowed.\n");
		exit(1);
	}
}

void	check_components(char *buf, t_data *comp)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == 'P') {
			comp->player++;
		} else if (buf[i] == 'C')
			comp->collect++;
		else if (buf[i] == 'E')
			comp->exit++;
		else if (buf[i] == '\n')
			comp->map_height++;
		else if (buf[i] != '1' && buf[i] != '0')
		{
			ft_printf("ERROR\nInvalid character in map.\n");
			exit(1);
		}
		i++;
	}
	map_error(buf, comp);
}

char	*complete_map(int fd)
{
	char	*line;
	char	*content;

	if (fd < 0)
		return (NULL);
	content = "";
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			content = ft_strjoin(content, line);
			free (line);
		}
		else
			return (content);
	}
	return (content);
}
