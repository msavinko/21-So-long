/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:12:33 by marlean           #+#    #+#             */
/*   Updated: 2022/03/04 08:59:41 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_if_sq(t_map *inf)
{
	int	i;

	i = 0;
	inf->line_len = ft_strlen(inf->map[i]);
	while (inf->map[i])
		i++;
	inf->map_h = i;
	i = 0;
	while (i < inf->map_h)
	{
		if (inf->line_len == (int)ft_strlen(inf->map[i]))
			++i;
		else
			ft_sl_error("The map is nor ractangular!", inf);
	}
}

void	ft_no_walls(t_map *inf)
{
	int	i;
	int	j;
	int	len;
	int	height;

	j = 0;
	i = 1;
	len = inf->line_len - 1;
	height = inf->map_h - 1;
	while (j < inf->line_len)
	{
		if (inf->map[0][j] == '1' && inf->map[height][j] == '1')
			j++;
		else
			ft_sl_error("Map does not surrounded by walls!", inf);
	}
	while (i < height)
	{
		if (inf->map[i][0] == '1' && inf->map[i][len] == '1')
			i++;
		else
			ft_sl_error("Map does not surrounded by walls!", inf);
	}
}

void	ft_correct_symb(t_map *inf)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	while (i < inf->map_h)
	{
		j = 0;
		while (j < inf->line_len)
		{
			a = inf->map[i][j];
			if (a == '1' || a == '0' || a == 'C' || a == 'E' || a == 'P')
				j++;
			else
				ft_sl_error("Map contains wrong symbol!", inf);
		}
		i++;
	}
}

void	ft_check_symb(t_map *inf, int i, int j)
{
	if (inf->map[i][j] == 'C')
		inf->c++;
	else if (inf->map[i][j] == 'E')
		inf->e++;
	else if (inf->map[i][j] == 'P')
	{
		if (inf->p.quan < 1)
		{
			inf->p.x = j;
			inf->p.y = i;
		}
		inf->map[i][j] = '0';
		inf->p.quan++;
	}
}

void	ft_nsymb(t_map *inf)
{
	int		i;
	int		j;

	inf->c = 0;
	inf->e = 0;
	inf->p.quan = 0;
	i = 1;
	while (i < inf->map_h)
	{
		j = 0;
		while (j < inf->line_len)
		{
			ft_check_symb(inf, i, j);
			j++;
		}
		i++;
	}
	if (inf->c < 1 || inf->e < 1 || inf->p.quan < 1)
		ft_sl_error("Wrong number of symbols!", inf);
}
