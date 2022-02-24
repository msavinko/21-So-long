/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:42:36 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 12:22:37 by marlean          ###   ########.fr       */
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
