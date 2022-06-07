/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:24:01 by alambert          #+#    #+#             */
/*   Updated: 2022/02/07 17:47:37 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end;
	int		len;

	len = ft_strlen(s);
	end = (char *)s + len;
	while (len-- >= 0)
	{
		if (*end == (char)c)
			return ((char *)end);
		if (len >= 0)
			end--;
	}
	return (NULL);
}
