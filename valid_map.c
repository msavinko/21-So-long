/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:12:33 by marlean           #+#    #+#             */
/*   Updated: 2022/02/22 17:03:41 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sl_error()
{
	ft_printf("Error %d: %s\n", errno, strerror(errno));
	perror("Error message");
	exit(errno);
}

void	ft_arg_is_ber(char *arg)
{
	int	len;

	
	len = ft_strlen(arg);

	//error 21 if you are trying to open a directory.

	if (strncmp(&arg[len-4], ".ber", 4) == 0)
		ft_printf("IT'S OK\n");
	else
		ft_sl_error(); // operation not permitted

}


// static int	valid_extension(char *path)
// {	
// 	const char	*ext;

// 	if (!path)
// 		return (1);
// 	ext = ft_strchr(path, '.');
// 	if (ft_strncmp(ext, ".ber", 5))
// 		return (1);
// 	return (0);
// }

void	ft_validation(char *arg)
{
	int		fd_map;
	char	*line;
	int		i;
//	char	*map;

	i = 0;
	line = NULL;
	ft_arg_is_ber(arg);
	fd_map = open(arg, O_RDONLY);
	if (fd_map == -1)
		ft_sl_error(); //bad file descriptor error
	while (ft_sl_gnl(&line, fd_map) > 0)
	{
		ft_printf("%s\n", line);

		free(line);
		line = NULL;
	}
	ft_printf("%s\n", line);
	free(line);
	line = NULL;
}