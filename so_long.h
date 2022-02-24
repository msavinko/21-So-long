/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:38 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 12:23:27 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_map
{
	int		fd_map;
	int		line_len;
	char	**map;
	char	*line;
	int		map_h;
	int		read_result;
}	t_map;

int		ft_sl_gnl(char **line, int fd);
void	ft_validation(char *arg);
void	ft_arg_is_ber(char *arg);
void	ft_sl_error(int errcode);
//void	ft_if_sq(char **map, int line_len, int map_height);
void	ft_if_sq(t_map *map_inf);

#endif
//ERROR CODES
// man errno
// 2 ENOENT No such file or directory. 
// 7 E2BIG Arg list too long. 
// 8 ENOEXEC Exec format error. 
// 9 EBADF Bad file descriptor. 
//12 ENOMEM Cannot allocate memory. 
// 21 EISDIR Is a directory.
// 22 EINVAL Invalid argument. 