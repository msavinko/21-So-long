/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:42:36 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 15:01:05 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_sl_gnl(char **line, int fd)
{
	int		result;
	int		i;
	char	*buffer;

	buffer = malloc(100000);
	if (!buffer)
		return (0);
	i = 0;
	*line = buffer;
	result = read(fd, &buffer[i], 1);
	while (result > 0 && buffer[i] != '\0')
	{
		i++;
		result += read(fd, &buffer[i], 1);
	}	
	buffer[i] = '\0';
	return (result);
}

void	ft_read_map(t_map *map_inf, char *arg)
{
	map_inf->map = NULL;
	map_inf->line = NULL;
	map_inf->fd_map = open(arg, O_RDONLY);
	if (map_inf->fd_map == -1)
		ft_sl_error(9);
	map_inf->read_result = ft_sl_gnl(&map_inf->line, map_inf->fd_map);
	if (map_inf->read_result <= 0)
		ft_sl_error(8);
	map_inf->map = ft_split(map_inf->line, '\n');
	free(map_inf->line);
	map_inf->line = NULL;
	if (map_inf->map == NULL)
		ft_sl_error(12);
}

void	ft_validation(t_map *map_inf)
{
	ft_if_sq(map_inf);
	ft_no_walls(map_inf);
	ft_correct_symb(map_inf);
	ft_nsymb(map_inf);
}

void	ft_free_map(t_map *map_inf)
{
	int	i;

	i = 0;
	ft_printf("=========================================\n");
	while (i < map_inf->map_h)
	{
		ft_printf("%s\n", map_inf->map[i]);
		free(map_inf->map[i]);
		i++;
	}	
	free(map_inf->map);
	map_inf->map = NULL;
}