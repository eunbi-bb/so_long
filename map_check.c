#include "mlx_linux/mlx.h"
#include "so_long.h"
#include "libft/libft.h"

void	check_map(char *buf, t_data map)
{
	map->map_size = ft_strlen(buf) - map->map_y;
	if (map->map_size != map->map_x * map->map_y)
	{
		ft_printf("ERROR\n The map size is invalid.");
		exit(1);
	}
	check_limit_x(map);
	check_limit_y(map);
}

void	check_components(char *buf, t_data comp)
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
			comp->map_y++;
		i++;
	}
	if (comp->player != 1)
	{
		ft_printf("ERROR\nOnly one player is available.");
		exit(1);
	}
	if (comp->c < 1)
	{
		ft_printf("ERROR\nCollects should be more than one.");
		exit(1);
	}
	if (comp->exit != 1)
	{
		ft_printf("ERROR\nOnly one exit is available.");
		exit(1);
	}
}
//Check if I can use gnl func
char	*join_line(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i])
	{
		str[i] = line[i]
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return(str);
}

int	check_line(char *line)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*complete_map(int fd)
{
	char	buf;
	char	*line;
	int		rd_bytes;

	if (fd < 0)
		line = NULL;
	line = malloc(1);
	line[0] = '\0';
	rd_bytes = 1;
	while (!check_line(line) && rd_bytes > 0)
	{
		rd_bytes = read(fd, &buf, 1);
		if ((rd_bytes == 0 && line[0] == '\0') || rd_bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (rd_bytes == 0 && line[0] != '\0')
			return (line);
		line = join_line(line, buf);
	}
	return (line);
}