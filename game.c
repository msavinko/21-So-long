/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:55:36 by marlean           #+#    #+#             */
/*   Updated: 2022/02/25 14:53:58 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_draw(t_map *map_inf)
// {
	
// }

void	ft_game(t_map *map_inf)
{
//	void	*img;
	void	*mlx;
	void	*mlx_win;
//	void	*koko;
	
	int len = map_inf->line_len * SCALE;
	int height = map_inf->map_h * SCALE;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, len, height, "~~~KOKOPELLI GAME~~~");
	mlx_loop(mlx);
//	ft_draw(&map_inf);

//	int w, h;

//	koko = mlx_xpm_file_to_image(mlx, (char *)PLAY, &w, &h);

//	mlx_put_image_to_window(mlx, map_inf->map, koko, 0, 1);



	// mlx_put_image_to_window(&mlx, &map_inf->map, );
//	int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

	//img = mlx_new_image(mlx, 1920, 1080);

	mlx_loop(mlx);
}
