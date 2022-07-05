/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:49:57 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:13:20 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l2;

	l2 = ft_strlen(needle);
	if (!l2)
		return ((char *)haystack);
	if (*haystack == '\0' && l2)
		return (NULL);
	while (len >= l2)
	{
		if (!ft_memcmp(haystack, needle, l2))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
