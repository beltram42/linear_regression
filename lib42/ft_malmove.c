/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:09:00 by alambert          #+#    #+#             */
/*   Updated: 2022/05/10 17:36:57 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_malmove(const char *dest, const char *src, int len1, int len2)
{
	char	*res;

	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_memmove((void *)(res), (void *)dest, len1);
	ft_memmove((void *)(res + len1), (void *)(src), len2 + 1);
	return (res);
}
