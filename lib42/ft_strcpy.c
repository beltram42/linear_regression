/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:39:32 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:14:01 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	len;

	len = ft_strlen(src);
	ft_memcpy(dst, src, len + 1);
	return (dst);
}
