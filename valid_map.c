/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:12:33 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 12:22:07 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_arg_is_ber(char *arg)
{
	int	len;

	if (!arg)
		ft_sl_error(8);
	len = ft_strlen(arg);
	//error 21 if you are trying to open a directory.
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

void	ft_validation(char *arg)
{
	t_map	map_inf;
	int		i;

	i = 0;
	map_inf.map = NULL;
	map_inf.line = NULL;
	ft_arg_is_ber(arg);
	map_inf.fd_map = open(arg, O_RDONLY);
	if (map_inf.fd_map == -1)
		ft_sl_error(9);
	map_inf.read_result = ft_sl_gnl(&map_inf.line, map_inf.fd_map);
	if (map_inf.read_result <= 0)
		ft_sl_error(8);
	map_inf.map = ft_split(map_inf.line, '\n');
	if (map_inf.map == NULL)
		ft_sl_error(12);
	ft_if_sq(&map_inf);
//ft_printf("line_len: %d\nmap_height: %d\n", map_inf->line_len, map_inf->map_h);
//~~~~~~~~~~~~~FREE LINE~~~~~~~~~~~~~~
	free(map_inf.line);
	map_inf.line = NULL;
//+++++++++++++PRINT AND FREE MAP++++++++++++++
	i = 0;
	ft_printf("=========================================\n");
	while (i < map_inf.map_h)
	{
		ft_printf("%s\n", map_inf.map[i]);
		free(map_inf.map[i]);
		i++;
	}	
	free(map_inf.map);
	map_inf.map = NULL;
}
