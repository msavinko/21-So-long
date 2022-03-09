/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:53:45 by marlean           #+#    #+#             */
/*   Updated: 2022/03/09 12:33:23 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit(t_map *inf, int game)
{
	if (game == 1)
		ft_printf("YOU WON!\n");
	else
		ft_printf("YOU LOST\n");
	//mlx_destroy_window((*inf)->mlx, (*inf)->win);
	ft_free_map(inf);
	exit(0);
}

void	ft_steps(t_map *inf, int x, int y)
{
	char	*num_steps;

	inf->moves++;
	inf->p.x = x;
	inf->p.y = y;
	num_steps = ft_itoa(inf->moves);
	if (!num_steps)
		ft_sl_error("Can not move!", inf);
	ft_file_towin(inf, 0, 0, WALL);
	mlx_string_put(inf->mlx, inf->win, 10, 10, 0x0000000, num_steps);
	free(num_steps);
	num_steps = NULL;
}

void	ft_file_towin(t_map *inf, int x, int y, const char *file)
{
	int	w;
	int	h;

	x = x * SCALE;
	y = y * SCALE;
	inf->img = mlx_xpm_file_to_image(inf->mlx, (char *)file, &w, &h);
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img, x, y);
}

void	ft_draw(t_map *inf)
{
	int	i;
	int	j;

	i = 0;
	while (i < inf->map_h)
	{
		j = 0;
		while (j < inf->line_len)
		{
			if (inf->map[i][j] == '1')
				ft_file_towin(inf, j, i, WALL);
			else if (inf->map[i][j] == 'C')
				ft_file_towin(inf, j, i, COIN);
			else if (inf->map[i][j] == 'E' && inf->c != 0)
				ft_file_towin(inf, j, i, EXITC);
			else
				ft_file_towin(inf, j, i, BACK);
			j++;
		}
		i++;
	}
	ft_file_towin(inf, inf->p.x, inf->p.y, PLAY);
	mlx_string_put(inf->mlx, inf->win, 10, 10, 0x0000000, "0");
}

void	ft_drawexit(t_map *inf)
{
	int	i;
	int	j;

	i = 0;
	while (i < inf->map_h)
	{
		j = 0;
		while (j < inf->line_len)
		{
			if (inf->map[i][j] == 'E')
				ft_file_towin(inf, j, i, EXITO);
			j++;
		}
		i++;
	}
}
