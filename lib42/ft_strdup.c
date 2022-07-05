/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:30:48 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:13:58 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, (ft_strlen(s) + 1));
	return (dup);
}
