/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:20 by marlean           #+#    #+#             */
/*   Updated: 2022/02/21 19:01:10 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx;

	mlx = mlx_init();

	ft_printf("HELLO IM FT_PRINTF\n");
	printf("im normal printf\n");

	return (0);
}