/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:12:05 by marlean           #+#    #+#             */
/*   Updated: 2022/03/09 11:49:05 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animate_enemy1(t_map *inf)
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
			if (inf->map[i][j] == 'F')
			{
				if (time == 2000)
					ft_file_towin(inf, j, i, ENEMY2);
				else if (time == 4000)
					ft_file_towin(inf, j, i, ENEMY1);
			}
			j++;
		}
		i++;
	}
	if (time++ == 4000)
		time = 0;
}

void	ft_animate_enemy2(t_map *inf)
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
			if (inf->map[i][j] == 'F')
			{
				if (time == 2000)
					ft_file_towin(inf, j, i, ENEMY4);
				else if (time == 4000)
					ft_file_towin(inf, j, i, ENEMY3);
			}
			j++;
		}
		i++;
	}
	if (time++ == 4000)
		time = 0;
}

int	ft_draw_enemy(t_map *inf)
{
	int	i;
	int	j;

	i = 1;
	while (i < inf->map_h)
	{
		j = 1;
		while (j < inf->line_len)
		{
			if (inf->map[i][j] == '0' && i != inf->p.y
				&& inf->map[i][j - 1] == '0' && inf->map[i][j + 1] == '0'
				&& inf->map[i][j + 2] == '0')
			{
				ft_file_towin(inf, j, i, ENEMY1);
				inf->map[i][j] = 'F';
				inf->num_enem++;
				i++;
			}
			j = j + 2;
		}
		i++;
	}
	return (0);
}
