/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:24:41 by alambert          #+#    #+#             */
/*   Updated: 2022/06/28 21:29:34 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

long long	ft_absll(long long i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

long	ft_absl(long i)
{
	return ((long)ft_absll(i));
}

int	ft_absi(int i)
{
	return ((int)ft_absl(i));
}

char	ft_absc(char i)
{
	return ((char)ft_absi(i));
}
