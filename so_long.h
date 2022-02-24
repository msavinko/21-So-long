/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:38 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 14:52:40 by marlean          ###   ########.fr       */
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

typedef struct s_coor
{
	int	quan;
	int	x;
	int	y;
}	t_coor;

typedef struct s_map
{
	int		fd_map;
	int		line_len;
	char	**map;
	char	*line;
	int		map_h;
	int		read_result;
	t_coor	c;
	t_coor	e;
	t_coor	p;
}	t_map;

int		ft_sl_gnl(char **line, int fd);

void	ft_read_map(t_map *map_inf, char *arg);
void	ft_sl_error(int errcode);
void	ft_free_map(t_map *map_inf);

void	ft_arg_is_ber(char *arg);
void	ft_validation(t_map *map_inf);
void	ft_if_sq(t_map *map_inf);
void	ft_no_walls(t_map *map_inf);
void	ft_correct_symb(t_map *map_inf);
void	ft_nsymb(t_map *map_inf);

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