/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:43:05 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 19:54:06 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*startd;
	const char	*starts;
	const char	*ends;
	char		*endd;

	starts = (const char *)src;
	startd = (char *)dest;
	ends = starts + (n - 1);
	endd = startd + (n - 1);
	if (dest == NULL && src == NULL)
		return (NULL);
	if (startd < starts)
		while (n--)
			*startd++ = *starts++;
	else
		while (n--)
			*endd-- = *ends--;
	return (dest);
}
