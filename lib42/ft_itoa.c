/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:51:32 by alambert          #+#    #+#             */
/*   Updated: 2022/06/16 23:40:53 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

int	ft_timer(int n)
{
	long	c;
	int		i;

	c = n;
	if (c < 0)
		c *= -1;
	i = 0;
	while (i++, c > 9)
		c /= 10;
	return (i);
}

void	ft_itok(int n, char *str)
{
	long	c;
	char	buf;

	c = n;
	buf = 0;
	if (c < 0)
		c = -c;
	if (c / 10)
		ft_itok(c / 10, str - 1);
	buf = c % 10 + '0';
	*str = buf;
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = 0;
	if (n < 0)
		len = 1;
	len += ft_timer(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	if (n < 0)
		*s = '-';
	ft_itok(n, s + len - 1);
	*(s + len) = '\0';
	return (s);
}
