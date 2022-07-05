/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:45:55 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:14:28 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	ft_putnbr(int nb)
{
	long	big_nb;
	char	printbuf;

	big_nb = nb;
	printbuf = 0;
	if (big_nb < 0)
	{
		write (1, "-", 1);
		big_nb = -big_nb;
	}
	if (big_nb / 10)
	{
		ft_putnbr(big_nb / 10);
	}
	printbuf = big_nb % 10 + '0';
	ft_putchar(printbuf);
}
