/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:36 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 17:04:44 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game(t_map *map_inf)
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	
	
	int len = map_inf->line_len * 50;
	int height = map_inf->map_h * 50;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, len, height, "~~~KOKOPELLI GAME~~~");
	mlx_loop(mlx);

	img = mlx_new_image(mlx, 1920, 1080);
}
