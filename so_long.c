/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:20 by marlean           #+#    #+#             */
/*   Updated: 2022/02/24 16:57:01 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sl_error(int errcode)
{
	ft_printf("Error\n%s\n", strerror(errcode));
	// strerror(errcode);
	// perror("Error message");
	exit(errcode);
}

void	ft_init_map(t_map *map_inf)
{
	map_inf->fd_map = 0;
	map_inf->line_len = 0;
	map_inf->map = NULL;
	map_inf->line = NULL;
	map_inf->map_h = 0;
	map_inf->read_result = 0;
}


int	main(int argc, char **argv)
{
	t_map	map_inf;
	int		i;

	i = 0;
	ft_init_map(&map_inf);
	if (argc != 2)
		ft_sl_error(2);
	ft_arg_is_ber(argv[1]);
	ft_read_map(&map_inf, argv[1]);
	ft_validation(&map_inf);

	ft_game(&map_inf);

	ft_free_map(&map_inf);
	return (0);
}
