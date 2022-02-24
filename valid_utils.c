/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:12:33 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 14:57:29 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arg_is_ber(char *arg)
{
	int	len;

	if (!arg)
		ft_sl_error(8);
	len = ft_strlen(arg);
	if (strncmp(&arg[len - 4], ".ber", 4))
		ft_sl_error(8);
}

void	ft_if_sq(t_map *map_inf)
{
	int	i;

	i = 0;
	map_inf->line_len = ft_strlen(map_inf->map[i]);
	while (map_inf->map[i])
		i++;
	map_inf->map_h = i;
	i = 1;
	while (i < map_inf->map_h)
	{
		if (map_inf->line_len == (int)ft_strlen(map_inf->map[i]))
			i++;
		else
			ft_sl_error(8);
	}
}

void	ft_no_walls(t_map *map_inf)
{
	int	i;
	int	j;
	int	len;
	int	height;

	j = 0;
	i = 1;
	len = map_inf->line_len - 1;
	height = map_inf->map_h - 1;
	while (j < map_inf->line_len)
	{
		if (map_inf->map[0][j] == '1' && map_inf->map[height][j] == '1')
			j++;
		else
			ft_sl_error(8);
	}
	while (i < height)
	{
		if (map_inf->map[i][0] == '1' && map_inf->map[i][len] == '1')
			i++;
		else
			ft_sl_error(8);
	}
}

void	ft_correct_symb(t_map *map_inf)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	while (i < map_inf->map_h)
	{
		j = 0;
		while (j < map_inf->line_len)
		{
			a = map_inf->map[i][j];
			if (a == '1' || a == '0' || a == 'C' || a == 'E' || a == 'P')
				j++;
			else
				ft_sl_error(8);
		}
		i++;
	}
}

void	ft_nsymb(t_map *map_inf)
{
	int		i;
	int		j;

	map_inf->c.quan = 0;
	map_inf->e.quan = 0;
	map_inf->p.quan = 0;
	i = 1;
	while (i < map_inf->map_h)
	{
		j = 0;
		while (j < map_inf->line_len)
		{
			if (map_inf->map[i][j] == 'C')
				map_inf->c.quan++;
			else if (map_inf->map[i][j] == 'E')
				map_inf->e.quan++;
			else if (map_inf->map[i][j] == 'P')
				map_inf->p.quan++;
			j++;
		}
		i++;
	}
	if (map_inf->c.quan < 1 || map_inf->e.quan < 1 || map_inf->p.quan < 1)
		ft_sl_error(8);
}
