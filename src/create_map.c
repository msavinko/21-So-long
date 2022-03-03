/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:42:36 by marlean           #+#    #+#             */
/*   Updated: 2022/03/03 17:46:40 by marlean          ###   ########.fr       */
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

void	ft_arg_is_ber(char *arg)
{
	int	len;

	if (!arg)
		ft_sl_first_error("No arguments given");
	len = ft_strlen(arg);
	if (strncmp(&arg[len - 4], ".ber", 4))
		ft_sl_first_error("You are trying to open file, which is not .ber");
}

void	ft_read_map(t_map *inf, char *arg)
{
	inf->fd_map = open(arg, O_RDONLY);
	if (inf->fd_map == -1)
		ft_sl_first_error("Can not open this file!");
	inf->read_result = ft_sl_gnl(&inf->line, inf->fd_map);
	if (inf->read_result <= 0)
		ft_sl_first_error("Can not read this file, it's empty or corrupted!");
	inf->map = ft_split(inf->line, '\n');
	free(inf->line);
	inf->line = NULL;
	if (inf->map == NULL)
		ft_sl_error("Empty file!", inf);
}

void	ft_validation(t_map *inf)
{
	ft_if_sq(inf);
	ft_no_walls(inf);
	ft_correct_symb(inf);
	ft_nsymb(inf);
}
