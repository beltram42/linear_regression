/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:00:35 by alambert          #+#    #+#             */
/*   Updated: 2022/05/31 15:32:51 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	len2 = ft_strlen(s2);
	len1 = ft_strlen(s1);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_memmove((void *)(res), (void *)s1, len1);
	ft_memmove((void *)(res + len1), (void *)(s2), len2 + 1);
	return (res);
}
