/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:47:59 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:12:58 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		fspn;
	int		bspn;
	int		len;
	char	*s1trim;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	fspn = ft_strspnfb(s1, set, 1);
	if (len == fspn)
	{
		s1trim = malloc(sizeof(char) * 1);
		if (s1trim == NULL)
			return (NULL);
		*s1trim = '\0';
		return (s1trim);
	}
	bspn = ft_strspnfb(s1, set, -1);
	len = (bspn + 1) - fspn;
	s1trim = ft_substr(s1, fspn, len);
	return (s1trim);
}
