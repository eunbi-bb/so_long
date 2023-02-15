#include "mlx_linux/mlx.h"
#include "so_long.h"
#include "libft/libft.h"

void	check_map(char *buf, t_data *map)
{
	map->map_size = ft_strlen(buf) - map->map_height;
	if (map->map_size != map->map_width * map->map_height)
	{
		ft_printf("ERROR\n The map size is invalid.\n");
		exit(1);
	}
	check_limit_x(map);
	check_limit_y(map);
}

void	check_components(char *buf, t_data *comp)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == 'P')
			comp->player++;
		if (buf[i] == 'C')
			comp->collect++;
		if (buf[i] == 'E')
			comp->exit++;
		if (buf[i] == '\n')
			comp->map_height++;
		i++;
	}
	if (comp->player != 1)
	{
		ft_printf("ERROR\nOnly one player is available.\n");
		exit(1);
	}
	if (comp->collect < 1)
	{
		ft_printf("ERROR\nCollects should be more than one.\n");
		exit(1);
	}
	if (comp->exit != 1)
	{
		ft_printf("ERROR\nOnly one exit is available.\n");
		exit(1);
	}
}

char	*complete_map(int fd)
{
	char	*line;
	char	*content;

	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		
		if (line) 
		{
			content = ft_strjoin(content, line);
			free(line);
		}
		else 
		{
			return (content);
		}
	}
}