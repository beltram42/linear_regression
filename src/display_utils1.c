/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:59:44 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/06/12 18:50:26 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

enum e_ivar
{
	xa,
	ya,
	xb,
	yb
};

enum e_imax
{
	x,
	y,
};

void	ft_tr_userparam(void *id[2], int iv[4], int max[2], long double fv[22])
{
	iv[xa] = fv[userkm] / 500;
	iv[ya] = fv[userprice] / 10;
	ft_originfix(iv);
	max[x] = iv[xb];
	max[y] = iv[yb];
	ft_bzero(iv, sizeof(int) * 4);
	ft_originfix(iv);
	while (iv[xb] <= max[x] && iv[yb] <= max[y])
	{
		ft_originfix(iv);
		while (iv[xb] <= max[x])
		{
			if ((iv[xb] % 2) == 1)
				mlx_pixel_put(id[0], id[1], iv[xb], max[y], 0xa009ae51);
			iv[xa] += 1;
		}
		while (iv[yb] <= y)
		{
			if ((y % 2) == 1)
				mlx_pixel_put(id[0], id[1], max[x], iv[yb], 0xa009ae51);
			iv[ya] += 1;
		}
	}
}

void	ft_usrlabel(void *id[2], int iv[4], long double fv[22])
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		len0;
	int		len1;

	s1 = "km = , price = ";
	len0 = ft_strspncspn(s1, ",", -1);
	ft_memcpy(s3, s1, len0);
	s2 = ft_itoa(fv[userkm]);
	len1 = ft_strlen(s2);
	ft_memcpy(s3 + len0, s2, len1);
	len1 = len0;
	ft_memcpy(s3 + len0 + len1);
	while (s2)
		*s3++ = *s2++;
	while (s1)
		*s3++ = *s1++;
	s2 -= len;
	s2 = ft_itoa(fv[userprice]);
	while (s2)
		*s3++ = *s2++;
	*s3 = '\0';
	iv[xa] = fv[userkm] / 500;
	iv[ya] = fv[userprice] / 10;
	ft_originfix(iv);
	mlx_string_put(id[0], id[1], iv[xb] + 10, iv[yb] + 10, 0xa009ae51, s2);
}