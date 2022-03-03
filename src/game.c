/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:36 by marlean           #+#    #+#             */
/*   Updated: 2022/03/03 12:04:08 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit()
{
	ft_printf("EXIT\n");
	exit(0);
}

//int	ft_move()
int	ft_key_hook(int keycode, t_map *inf)
{
	static int	steps = 0;

	(void)inf;
	if (keycode == UPER || keycode == UP)
	{
		////ft_move()
		ft_printf("UPPP ");
	}
	if (keycode == DOWNER || keycode == DOWN)
		ft_printf("DOWN ");
	if (keycode == RIGHTER || keycode == RIGHT)
		ft_printf("RIGHT ");
	if (keycode == LEFTER || keycode == LEFT)
		ft_printf("LEFT ");
	else if (keycode == ESCAPE)
		ft_exit();

	steps++;
	ft_printf("steps: %d\n", steps);
	
	return (0);
}

void	ft_file_towin(t_map *inf, int x, int y, const char *file)
{
	int	w;
	int	h;

	inf->img = mlx_xpm_file_to_image(inf->mlx, (char *)file, &w, &h);
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img, x, y);
	// inf->back = mlx_xpm_file_to_image(inf->mlx, BACK, &w, &h);
	// inf->play = mlx_xpm_file_to_image(inf->mlx, PLAY, &w, &h);
	// inf->wall = mlx_xpm_file_to_image(inf->mlx, WALL, &w, &h);
	// inf->coin = mlx_xpm_file_to_image(inf->mlx, COIN, &w, &h);
	// inf->exit = mlx_xpm_file_to_image(inf->mlx, EXITC, &w, &h);
}

void	ft_draw2(t_map *inf, int i, int j)
{
	int	x;
	int	y;


	x = j * SCALE;
	y = i * SCALE;
	if (inf->map[i][j] == '1')
		ft_file_towin(inf, x, y, WALL);
		else if (inf->map[i][j] == 'P')
	{
		if (inf->p.quan < 1)
		{
			++inf->p.quan;
			ft_file_towin(inf, x, y, PLAY);
			inf->p.x = j;
			inf->p.y = i;
		}
		else
			ft_file_towin(inf, x, y, BACK);
		inf->map[i][j] = '0';
	}
	else if (inf->map[i][j] == 'C')
	{
		++inf->c.quan;
		ft_file_towin(inf, x, y, COIN);
	}
	else if (inf->map[i][j] == 'E')
	{
		++inf->e.quan;
		ft_file_towin(inf, x, y, EXITC);
	}
	else
		ft_file_towin(inf, x, y, BACK);
}

void	ft_draw(t_map *inf)
{
	int	i;
	int	j;

	i = 0;
	// ft_file_toimg(inf);
	while (i < inf->map_h)
	{
		j = 0;
		while (j < inf->line_len)
		{
			ft_draw2(inf, i, j);
			j++;
		}
		i++;
	}
	ft_printf("coins: %d, exit: %d, player: %d (x - %d, y - %d)\n", inf->c.quan, inf->e.quan, inf->p.quan, inf->p.x, inf->p.y);
}

void	ft_game(t_map *inf)
{
	int		width;
	int		height;

	inf->p.quan = 0;
	inf->e.quan = 0;
	inf->c.quan = 0;
	width = inf->line_len * SCALE;
	height = inf->map_h * SCALE;
	inf->mlx = mlx_init();
	inf->win = mlx_new_window(inf->mlx, width, height, "~~~KOKOPELLI GAME~~~");
	ft_draw(inf);
	mlx_hook(inf->win, 2, 0, ft_key_hook, &inf);
	mlx_hook(inf->win, 17, 0, ft_exit, &inf);
	mlx_loop(inf->mlx);
}
