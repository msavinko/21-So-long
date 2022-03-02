/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:36 by marlean           #+#    #+#             */
/*   Updated: 2022/03/02 16:47:36 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_map *inf)
{
	static int	steps = 0;

	(void)inf;
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2
		|| keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		if (keycode == 13 || keycode == 126)
			ft_printf("UP ");
		if (keycode == 1 || keycode == 125)
			ft_printf("DOWN ");
		if (keycode == 2 || keycode == 124)
			ft_printf("RIGHT ");
		if (keycode == 0 || keycode == 123)
			ft_printf("LEFT ");
		steps++;
		ft_printf("steps: %d\n", steps);
	}
	else if (keycode == 53)
		exit (0);
	return (0);
}

void	ft_draw_img(t_map *inf)
{
	int	w;
	int	h;

	inf->back = mlx_xpm_file_to_image(inf->mlx, BACK, &w, &h);
	inf->play = mlx_xpm_file_to_image(inf->mlx, PLAY, &w, &h);
	inf->wall = mlx_xpm_file_to_image(inf->mlx, WALL, &w, &h);
	inf->coin = mlx_xpm_file_to_image(inf->mlx, COIN, &w, &h);
	inf->exit = mlx_xpm_file_to_image(inf->mlx, EXITC, &w, &h);
}

void	ft_img_towin(t_map *inf, int i, int j)
{
	int	x;
	int	y;

	x = j * SCALE;
	y = i * SCALE;
	if (inf->map[i][j] == '1')
		mlx_put_image_to_window(inf->mlx, inf->win, inf->wall, x, y);
	else if (inf->map[i][j] == '0')
		mlx_put_image_to_window(inf->mlx, inf->win, inf->back, x, y);
	else if (inf->map[i][j] == 'P')
		mlx_put_image_to_window(inf->mlx, inf->win, inf->play, x, y);
	else if (inf->map[i][j] == 'C')
		mlx_put_image_to_window(inf->mlx, inf->win, inf->coin, x, y);
	else if (inf->map[i][j] == 'E')
		mlx_put_image_to_window(inf->mlx, inf->win, inf->exit, x, y);
}

void	ft_draw(t_map *inf)
{
	int	i;
	int	j;

	i = 0;
	ft_draw_img(inf);
	while (i < inf->map_h)
	{
		j = 0;
		while (j < inf->line_len)
		{
			ft_img_towin(inf, i, j);
			j++;
		}
		i++;
	}
}

void	ft_game(t_map *inf)
{
	int		width;
	int		height;

	width = inf->line_len * SCALE;
	height = inf->map_h * SCALE;
	inf->mlx = mlx_init();
	inf->win = mlx_new_window(inf->mlx, width, height, "~~~KOKOPELLI GAME~~~");
	ft_draw(inf);
	mlx_key_hook(inf->win, ft_key_hook, &inf);
	mlx_loop(inf->mlx);
}
