/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:20 by marlean           #+#    #+#             */
/*   Updated: 2022/03/04 17:54:53 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_sl_first_error(char *string)
{
	ft_printf("Error\n%s\n", string);
	exit(1);
}

void	ft_sl_error(char *string, t_map *inf)
{
	ft_free_map(inf);
	ft_printf("Error\n%s\n", string);
	exit(1);
}

void	ft_free_map(t_map *inf)
{
	int	i;

	i = 0;
	while (i < inf->map_h)
	{
		free(inf->map[i]);
		i++;
	}	
	free(inf->map);
	inf->map = NULL;
}

void	ft_init_map(t_map *inf)
{
	inf->map = NULL;
	inf->line = NULL;
	inf->fd_map = 0;
	inf->line_len = 0;
	inf->map_h = 0;
	inf->read_result = 0;
	inf->moves = 0;
	inf->right = 1;
	inf->enemy_direction = 1;
	inf->num_enem = 0;
}

int	main(int argc, char **argv)
{
	t_map	inf;
	int		i;

	i = 0;
	ft_init_map(&inf);
	if (argc != 2)
		ft_sl_first_error("Wrong number of arguments!");
	ft_arg_is_ber(argv[1]);
	ft_read_map(&inf, argv[1]);
	ft_validation(&inf);
	ft_game(&inf);
	return (0);
}
