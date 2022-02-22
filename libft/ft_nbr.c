/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:11:17 by marlean           #+#    #+#             */
/*   Updated: 2022/02/22 12:32:05 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recurs_putnbr(int nb)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_recurs_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{	
		if (nb == -2147483648)
		{
			ft_putstr("-2147483648");
			return (11);
		}
		ft_putchar('-');
		nb *= -1;
		count++;
	}
	ft_recurs_putnbr(nb);
	count += ft_nbrlen(nb, 10);
	return (count);
}

static void	ft_recurs_u(unsigned int nb)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_unsigned(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

int	ft_unsigned(unsigned int nb)
{
	ft_recurs_u(nb);
	return (ft_nbrlen(nb, 10));
}
