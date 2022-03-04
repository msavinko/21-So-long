/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:38 by marlean           #+#    #+#             */
/*   Updated: 2022/03/04 19:20:53 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BACK "img/sand100.xpm"
# define PLAY "img/koko100.xpm"
# define WALL "img/cactus100.xpm"
# define COIN "img/lizard100.xpm"
# define EXITC "img/stop100.xpm"
# define EXITO "img/sun100.xpm"

# define PLAY1 "img/koko1.xpm"
# define PLAY2 "img/koko2.xpm"
# define PLAY3 "img/koko3.xpm"
# define PLAY4 "img/koko4.xpm"
# define PLAY5 "img/koko5.xpm"
# define PLAY6 "img/koko6.xpm"
# define PLAY7 "img/koko7.xpm"
# define PLAY8 "img/koko8.xpm"

# define COIN1 "img/lizard1.xpm"
# define COIN2 "img/lizard2.xpm"

# define ENEMY1 "img/enemy1.xpm"
# define ENEMY2 "img/enemy2.xpm"
# define ENEMY3 "img/enemy3.xpm"
# define ENEMY4 "img/enemy4.xpm"

# define SCALE 100
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
}	t_coor;

typedef struct s_map
{
	t_coor	p;
	int		e;
	int		c;
	char	**map;
	char	*line;
	int		fd_map;
	int		line_len;
	int		map_h;
	int		read_result;
	void	*mlx;
	void	*win;
	void	*img;
	int		moves;
	int		right;
	int		enemy_direction;
	int		num_enem;
}	t_map;

void	ft_sl_first_error(char *string);
void	ft_sl_error(char *string, t_map *inf);
void	ft_free_map(t_map *map_inf);
void	ft_init_map(t_map *map_inf);

int		ft_sl_gnl(char **line, int fd);
void	ft_arg_is_ber(char *arg);
void	ft_read_map(t_map *map_inf, char *arg);
void	ft_validation(t_map *map_inf);

void	ft_if_sq(t_map *map_inf);
void	ft_no_walls(t_map *map_inf);
void	ft_correct_symb(t_map *map_inf);
void	ft_check_symb(t_map *inf, int i, int j);
void	ft_nsymb(t_map *map_inf);

void	ft_move_to_zero(t_map *inf, int x, int y);
void	ft_move_toc(t_map *inf, int x, int y);
void	ft_move(t_map *inf, int x, int y, int right);
int		ft_key_hook(int keycode, t_map *inf);
void	ft_game(t_map *map_inf);

int		ft_exit(t_map **inf, int game);
void	ft_steps(t_map *inf, int x, int y);
void	ft_file_towin(t_map *inf, int x, int y, const char *file);
void	ft_draw(t_map *map_inf);
void	ft_drawexit(t_map *inf);

void	ft_animate_coin(t_map *inf);
void	ft_animate_koko1(t_map *inf);
void	ft_animate_koko2(t_map *inf);
int		ft_my_sprite(t_map *inf);

void	ft_move_left(t_map *inf, int j, int i);
void	ft_move_right(t_map *inf, int j, int i);
void	ft_move_enemy(t_map *inf);
void	ft_check_direction(t_map *inf, int i, int j, int time);

void	ft_animate_enemy1(t_map *inf);
int		ft_draw_enemy(t_map *inf);

#endif