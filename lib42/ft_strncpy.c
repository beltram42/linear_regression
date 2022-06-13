/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:46:04 by alambert          #+#    #+#             */
/*   Updated: 2022/06/13 10:47:53 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strncpy(char *dst, const char *src, size_t maxlen)
{
	size_t	srclen;

	srclen = ft_strnlen(src, maxlen);
	if (srclen < maxlen)
	{
		ft_memcpy(dst, src, srclen);
		ft_memset(dst + srclen, 0, maxlen - srclen);
	}
	else
		ft_memcpy(dst, src, maxlen);
	return (dst);
}
