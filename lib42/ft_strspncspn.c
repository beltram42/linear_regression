/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspncspn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:51:11 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:13:12 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

int	ft_strspncspn(const char *str, const char *set, int gear)
{
	const char	*p;
	const char	*s;

	p = str;
	while (*p)
	{
		s = set;
		s = ft_strchr(s, *p);
		if (s == 0 && gear == 1)
			break ;
		if (s != 0 && gear == -1)
			break ;
		else
			p++;
	}
	return (p - str);
}

/*
	strspn : gear = 1
	strcspn : gear = -1
	strlen : set = ""
*/