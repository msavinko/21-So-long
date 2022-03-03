/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:36 by marlean           #+#    #+#             */
/*   Updated: 2022/03/03 18:06:58 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_map *inf)
{
	ft_free_map(inf);
	exit(0);
}

void	ft_move(t_map *inf, int x, int y)
{
	char	checkstep;

	checkstep = inf->map[y][x];
	if (checkstep == 'E' && inf->c == 0)
		ft_exit(inf);
	if (checkstep == '1' )
		return ;
	else if (checkstep == '0')
	{
		ft_file_towin(inf, x, y, PLAY);
		ft_file_towin(inf, inf->p.x, inf->p.y, BACK);
		inf->p.x = x;
		inf->p.y = y;
		inf->moves++;
		ft_printf("Moves: %d\n", inf->moves);
	}
	else if (checkstep == 'C')
	{
		ft_file_towin(inf, x, y, PLAY);
		ft_file_towin(inf, inf->p.x, inf->p.y, BACK);
		--inf->c;
		inf->p.x = x;
		inf->p.y = y;
		inf->map[y][x] = '0';
		inf->moves++;
		ft_printf("Moves: %d\n", inf->moves);
	}
}

int	ft_key_hook(int keycode, t_map *inf)
{
	if (keycode == UPER || keycode == UP)
		ft_move(inf, inf->p.x, inf->p.y - 1);
	else if (keycode == DOWNER || keycode == DOWN)
		ft_move(inf, inf->p.x, inf->p.y + 1);
	else if (keycode == LEFTER || keycode == LEFT)
		ft_move(inf, inf->p.x - 1, inf->p.y);
	else if (keycode == RIGHTER || keycode == RIGHT)
		ft_move(inf, inf->p.x + 1, inf->p.y);
	else if (keycode == ESCAPE)
		ft_exit(inf);
	if (inf->c == 0)
		ft_drawexit(inf);
	return (0);
}

void	ft_game(t_map *inf)
{
	int		width;
	int		height;

	width = inf->line_len * SCALE;
	height = inf->map_h * SCALE;
	inf->mlx = mlx_init();
	inf->win = mlx_new_window(inf->mlx, width, height, "So_long");
	ft_draw(inf);
	mlx_hook(inf->win, 2, 0, ft_key_hook, inf);
	mlx_hook(inf->win, 17, 0, ft_exit, inf);
	mlx_loop(inf->mlx);
}
