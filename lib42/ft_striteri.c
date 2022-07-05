/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:47:36 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:13:53 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*ptr;

	if (!s || !f)
		return ;
	ptr = s;
	while (*ptr)
	{
		f(ptr - s, ptr);
		ptr++;
	}
}
