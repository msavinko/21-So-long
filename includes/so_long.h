/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:38 by marlean           #+#    #+#             */
/*   Updated: 2022/03/03 11:58:01 by marlean          ###   ########.fr       */
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
# include "../libft/libft.h"

# define BACK "img/sand64.xpm"
# define PLAY "img/kokopelli64.xpm"
# define WALL "img/cactus64.xpm"
# define COIN "img/lizard64.xpm"
# define EXITC "img/exit_close64.xpm"

# define SCALE 64
# define ESCAPE 53

# define LEFTER 123
# define LEFT 0

# define RIGHTER 124
# define RIGHT 2

# define DOWNER 125
# define DOWN 1

# define UPER 126
# define UP 13

typedef struct s_coor
{
	int				quan;
	int				x;
	int				y;
//	struct s_coor	*next;
}	t_coor;

typedef struct s_map
{
	t_coor	p;
	t_coor	e;
	t_coor	c;
	char	**map;
	char	*line;
	int		fd_map;
	int		line_len;
	int		map_h;
	int		read_result;
	// void	*play;
	// void	*back;
	// void	*wall;
	// void	*coin;
	// void	*exit;
	void	*mlx;
	void	*win;
	void	*img;
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


