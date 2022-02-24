/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:20 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 15:02:32 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sl_error(int errcode)
{
	ft_printf("Error message: %s\n", strerror(errcode));
	// strerror(errcode);
	// perror("Error message");
	exit(errcode);
}


int	main(int argc, char **argv)
{
	t_map	map_inf;
	int		i;

	i = 0;
	if (argc != 2)
		ft_sl_error(2);
	ft_arg_is_ber(argv[1]);
	ft_read_map(&map_inf, argv[1]);
	ft_validation(&map_inf);

	void	*mlx;
	void	*mlx_win;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 500, "~~~KOKOPELLI GAME~~~");
	mlx_loop(mlx);

	ft_free_map(&map_inf);
	return (0);
}
