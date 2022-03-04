/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:37:54 by marlean           #+#    #+#             */
/*   Updated: 2022/03/04 19:35:14 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_left(t_map *inf, int j, int i)
{
	if (i == inf->p.y && j == inf->p.x)
		ft_exit(&inf, 0);
	inf->map[i][j] = 'F';
	ft_file_towin(inf, j, i, ENEMY1);
	inf->map[i][j + 1] = '0';
	ft_file_towin(inf, j + 1, i, BACK);
}

void	ft_move_right(t_map *inf, int j, int i)
{
	if (i == inf->p.y && j == inf->p.x)
		ft_exit(&inf, 0);
	inf->map[i][j] = 'F';
	ft_file_towin(inf, j, i, ENEMY3);
	inf->map[i][j - 1] = '0';
	ft_file_towin(inf, j - 1, i, BACK);
}

// void	ft_check_direction(t_map *inf, int i, int j, int time)
// {
// 	if (inf->map[i][j] == 'F' && time== 4000)
// 	{
// 		if (inf->map[i][j - 1] == '0' && inf->enemy_direction == 1)
// 			ft_move_left(inf, j - 1, i);
// 		else if (inf->enemy_direction == 1)
// 		{
// 			ft_file_towin(inf, j, i, ENEMY2);
// 			inf->enemy_direction = 2;
// 		}
// 		else if (inf->map[i][j + 1] == '0' && inf->enemy_direction == 2)
// 		{
// 			ft_move_right(inf, j + 1, i);
// 			j++;
// 		}
// 		else if (inf->enemy_direction == 2)
// 		{
// 			ft_file_towin(inf, j, i, ENEMY4);
// 			inf->enemy_direction = 1;
// 		}
// 	}
// }

void	ft_move_enemy(t_map *inf)
{
	static int	time = 0;
	int			i;
	int			j;

	i = 0;
	while (i < inf->map_h)
	{
		j = 0;
		while (j < inf->line_len)
		{
			//ft_check_direction(inf,i,j,time);
			if (inf->map[i][j] == 'F' && time == 4000)
			{
				if (inf->map[i][j - 1] == '0' && inf->enemy_direction == 1)
					ft_move_left(inf, j - 1, i);
				else if (inf->enemy_direction == 1)
				{
					ft_file_towin(inf, j, i, ENEMY2);
					inf->enemy_direction = 2;
				}
				else if (inf->map[i][j + 1] == '0' && inf->enemy_direction == 2)
				{
					ft_move_right(inf, j + 1, i);
					j++;
				}
				else if (inf->enemy_direction == 2)
				{
					ft_file_towin(inf, j, i, ENEMY4);
					inf->enemy_direction = 1;
				}
			}
			j++;
		}
		i++;
	}
	if (time++ == 4000)
		time = 0;
}
