/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:36 by marlean           #+#    #+#             */
/*   Updated: 2022/03/09 12:35:07 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_to_zero(t_map *inf, int x, int y)
{
	if (inf->right == 1)
		ft_file_towin(inf, x, y, PLAY4);
	else
		ft_file_towin(inf, x, y, PLAY8);
	ft_file_towin(inf, inf->p.x, inf->p.y, BACK);
	ft_steps(inf, x, y);
}

void	ft_move_toc(t_map *inf, int x, int y)
{
	if (inf->right == 1)
		ft_file_towin(inf, x, y, PLAY4);
	else
		ft_file_towin(inf, x, y, PLAY8);
	ft_file_towin(inf, inf->p.x, inf->p.y, BACK);
	--inf->c;
	inf->map[y][x] = '0';
	ft_steps(inf, x, y);
}

void	ft_move(t_map *inf, int x, int y, int right)
{
	char	checkstep;

	checkstep = inf->map[y][x];
	if (right == 1)
		inf->right = 1;
	if (right == 2)
		inf->right = 2;
	if (checkstep == 'E' && inf->c == 0)
		ft_exit(inf, 1);
	if (checkstep == 'F')
		ft_exit(inf, 0);
	if (checkstep == '1' )
		return ;
	else if (checkstep == '0')
		ft_move_to_zero(inf, x, y);
	else if (checkstep == 'C')
		ft_move_toc(inf, x, y);
}

int	ft_key_hook(int keycode, t_map *inf)
{
	if (keycode == UPER || keycode == UP)
		ft_move(inf, inf->p.x, inf->p.y - 1, 0);
	else if (keycode == DOWNER || keycode == DOWN)
		ft_move(inf, inf->p.x, inf->p.y + 1, 0);
	else if (keycode == LEFTER || keycode == LEFT)
		ft_move(inf, inf->p.x - 1, inf->p.y, 1);
	else if (keycode == RIGHTER || keycode == RIGHT)
		ft_move(inf, inf->p.x + 1, inf->p.y, 2);
	else if (keycode == ESCAPE)
		ft_exit(inf, 0);
	if (inf->c == 0)
		ft_drawexit(inf);
	return (0);
}

void	ft_game(t_map *inf)
{
	int	width;
	int	height;

	width = inf->line_len * SCALE;
	height = inf->map_h * SCALE;
	inf->mlx = mlx_init();
	inf->win = mlx_new_window(inf->mlx, width, height, "So_long");
	ft_draw(inf);
	ft_draw_enemy(inf);
	mlx_hook(inf->win, 2, (1L << 0), ft_key_hook, inf);
	mlx_hook(inf->win, 17, (1L << 0), ft_exit, inf);
	mlx_loop_hook(inf->mlx, ft_my_sprite, inf);
	mlx_loop(inf->mlx);
}
