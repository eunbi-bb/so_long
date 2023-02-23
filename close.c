/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 11:06:28 by eucho         #+#    #+#                 */
/*   Updated: 2023/02/22 15:07:34 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "so_long.h"

int	esc_hook(int keycode, t_data *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	close_window(t_data *win)
{
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
	return (0);
}