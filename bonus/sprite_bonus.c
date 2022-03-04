/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:01:33 by marlean           #+#    #+#             */
/*   Updated: 2022/03/04 18:30:45 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animate_coin(t_map *inf)
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
			if (inf->map[i][j] == 'C')
			{
				if (time == 3000)
					ft_file_towin(inf, j, i, COIN1);
				else if (time == 6000)
					ft_file_towin(inf, j, i, COIN2);
			}
			j++;
		}
		i++;
	}
	if (time++ == 6000)
		time = 0;
}

void	ft_animate_koko1(t_map *inf)
{
	static int	time = 0;
	int			i;
	int			j;

	j = inf->p.x;
	i = inf->p.y;
	if (time == 1000)
		ft_file_towin(inf, j, i, PLAY1);
	else if (time == 2000)
		ft_file_towin(inf, j, i, PLAY2);
	else if (time == 3000)
		ft_file_towin(inf, j, i, PLAY3);
	else if (time == 4000)
		ft_file_towin(inf, j, i, PLAY4);
	if (time++ == 4000)
		time = 0;
}

void	ft_animate_koko2(t_map *inf)
{
	static int	time = 0;
	int			i;
	int			j;

	j = inf->p.x;
	i = inf->p.y;
	if (time == 1000)
		ft_file_towin(inf, j, i, PLAY5);
	else if (time == 2000)
		ft_file_towin(inf, j, i, PLAY6);
	else if (time == 3000)
		ft_file_towin(inf, j, i, PLAY7);
	else if (time == 4000)
		ft_file_towin(inf, j, i, PLAY8);
	if (time++ == 4000)
		time = 0;
}

int	ft_my_sprite(t_map *inf)
{
	ft_animate_coin(inf);
	if (inf->right == 1)
		ft_animate_koko1(inf);
	else if (inf->right == 2)
		ft_animate_koko2(inf);
	if (inf->num_enem > 0)
		ft_move_enemy(inf);
	return (0);
}
