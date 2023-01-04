#include "mlx_linux/mlx.h"
#include "so_long.h"
#include "libft/libft.h"
int	copy_line(char *str, t_data *var)
{
	t_list	*line;
	t_list	*curr_line;

	curr_line = var->map;
	line = malloc(sizeof(t_list));
	if (!line)
	{
		free (var);
		return (NULL);
	}
	line->next = NULL;
	line->content = ft_strdup(str);
	if (var->map == NULL)
		var->map = line;
	else
	{
		while (curr_line->next != NULL)
			curr_line = curr_line->next;
		curr_line->next = line;
	}
	return (1);
}

void	freemap(t_data *var)
{
	t_list	*curr_line;
	t_list	*next_line;

	curr_line = var->map;
	while (curr_line)
	{
		next_line = curr_line->next;
		free (curr_line->content);
		free (curr_line);
		curr_line = next_line;
	}
	free (curr_line)
}

int	draw_map(t_data *var)
{
	char	*str;

	str = get_next_line(var->fd);
	while (str != NULL)
	{
		copy_line(str, var);
		free(str);
		str = get_next_line(var->fd)
	}
	free (str);
	return (1);
}