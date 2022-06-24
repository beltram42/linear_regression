/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malgets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:29:48 by alambert          #+#    #+#             */
/*   Updated: 2022/06/24 19:08:06 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_malgets(int buf)
{
	char	*save;
	int		len;

	save = malloc(sizeof(char) * (buf + 1));
	if (!save)
		return (NULL);
	len = read(0, save, buf);
	if (len == -1)
	{
		save = ft_free(&save);
		return (NULL);
	}
	save[len] = '\0';
	return ((char *)save);
}
