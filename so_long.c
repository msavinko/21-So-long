/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:20 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 12:22:55 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sl_error(int errcode)
{
	ft_printf("Error message: %s\n", strerror(errcode));
//	strerror(errno);
	//perror("Error message");
	exit(errcode);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_sl_error(2);
	}
	ft_validation(argv[1]);
	// void	*mlx;
	// void	*mlx_win;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 800, 500, "~~~ WELCOME TO KOKOPELLI GAME~~~");
	// mlx_loop(mlx);
	return (0);
}
