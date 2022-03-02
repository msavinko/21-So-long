/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:38 by marlean           #+#    #+#             */
/*   Updated: 2022/03/02 16:48:38 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "libft/libft.h"

# define BACK "img/sand64.xpm"
# define PLAY "img/kokopelli64.xpm"
# define WALL "img/cactus64.xpm"
# define COIN "img/lizard64.xpm"
# define EXITC "img/exit_close64.xpm"

# define SCALE 64

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
	int		imgw;
	int		imgh;
	void	*play;
	void	*back;
	void	*wall;
	void	*coin;
	void	*exit;
	t_coor	c;
	t_coor	e;
	t_coor	p;
	void	*mlx;
	void	*win;
}	t_map;

int		ft_sl_gnl(char **line, int fd);
void	ft_init_map(t_map *map_inf);
void	ft_read_map(t_map *map_inf, char *arg);
void	ft_sl_error(int errcode);
void	ft_free_map(t_map *map_inf);
void	ft_arg_is_ber(char *arg);
void	ft_validation(t_map *map_inf);
void	ft_if_sq(t_map *map_inf);
void	ft_no_walls(t_map *map_inf);
void	ft_correct_symb(t_map *map_inf);
void	ft_nsymb(t_map *map_inf);
void	ft_game(t_map *map_inf);
void	ft_draw(t_map *map_inf);

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

//images
//background 64*64
//player 1/2/3/4
//walls 64*64
//collectible 64*64
//exit block
//exit open
//cage 1/2/3

//keycode
//53 esc
// 123 left errow
// 124 right errow
// 125 down errow
// 126 up errow
// 13 W (up)
// 0 A (left)
// 1 S (down)
// 2 D (right)
