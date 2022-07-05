/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:59:40 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:13:03 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strtok_r(char *str, const char *sep, char **saveptr)
{
	char	*start;

	if (!str)
		str = *saveptr;
	while (*str && ft_strchr(sep, *str))
		++str;
	if (*str)
	{
		start = (char *)str;
		*saveptr = start + 1;
		while (**saveptr && !ft_strchr(sep, **saveptr))
			++*saveptr;
		if (**saveptr)
		{
			**saveptr = '\0';
			++*saveptr;
		}
		return (start);
	}
	return (NULL);
}
