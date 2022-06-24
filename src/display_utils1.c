/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:59:44 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/06/24 18:13:49 by alambert         ###   ########.fr       */
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
	printf("max[x] = %d, max[y] = %d\n", max[x], max[y]);
	ft_bzero(iv, sizeof(int) * 4);
	ft_originfix(iv);
	printf("xb = %d, yb = %d\n", iv[xb], iv[yb]);
	while (iv[xb] <= max[x])
	{
		if ((iv[xb] % 3) == (iv[xb] % 2))
			mlx_pixel_put(id[0], id[1], iv[xb], max[y], 0xa0ff9bca);
		iv[xb] += 1;
	}
	while (iv[yb] >= max[y])
	{
		if ((iv[yb] % 3) == (iv[yb] % 2))
			mlx_pixel_put(id[0], id[1], max[x], iv[yb], 0xa0ff9bca);
		iv[yb] -= 1;
	}
	printf("iv[xb] = %d, iv[yb] = %d\n", iv[xb], iv[yb]);
}

void	ft_usrlabel(void *id[2], int iv[4], long double fv[22])
{
	char	*s1;
	char	*s2;

	s1 = ft_itoa((int)fv[userkm]);
	s1 = ft_strcat(s1, ", ");
	s2 = ft_itoa((int)fv[userprice]);
	s1 = ft_strcat(s1, s2);
	s2 = ft_free(&s2);
	iv[xa] = fv[userkm] / 500;
	iv[ya] = fv[userprice] / 10;
	ft_originfix(iv);
	mlx_string_put(id[0], id[1], iv[xb] + 10, iv[yb] - 10, 0xa009ae51, s1);
	s1 = ft_free(&s1);
}
