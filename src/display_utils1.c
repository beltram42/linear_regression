/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:59:44 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/06/28 14:47:23 by alambert         ###   ########.fr       */
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
	while (iv[xb] <= max[x])
	{
		if ((iv[xb] % 4) != (iv[xb] % 2))
			mlx_pixel_put(id[0], id[1], iv[xb], max[y], 0xa0CDA1B6);
		iv[xb] += 1;
	}
	while (iv[yb] >= max[y])
	{
		if ((iv[yb] % 4) != (iv[yb] % 2))
			mlx_pixel_put(id[0], id[1], max[x], iv[yb], 0xa0CDA1B6);
		iv[yb] -= 1;
	}
}

void	ft_pricelabel(long double fv[22], char res[30], char **p)
{
	char	*o;
	char	*q;
	char	s[12];

	o = "* $";
	o += 3;
	*p = res + 30;
	while (*o != '*')
		**p-- = *o--;
	ft_memset(s, ' ', 11);
	ft_itoav((int)fv[userprice], s);
	q = s + 11;
	while (*q != ' ')
		**p-- = *q--;
}

void	ft_kmlabel(long double fv[22], char res[30], char **p)
{
	char	*o;
	char	*q;
	char	s[12];

	o = "* km, ";
	o += 5;
	while (*o != '*')
		**p-- = *o--;
	ft_memset(s, ' ', 11);
	ft_itoav((int)fv[userkm], s);
	q = s + 11;
	while (*q != ' ')
		**p-- = *q--;
}

void	ft_usrlabel(void *id[2], int iv[4], long double fv[22])
{
	char	s[12];
	char	res[30];
	char	*o;
	char	*p;
	char	*q;

	ft_pricelabel(fv, res, &p);
	ft_kmlabel(fv, res, &p);
	printf("res = >%s<", p);
	iv[xa] = fv[userkm] / 500;
	iv[ya] = fv[userprice] / 10;
	ft_originfix(iv);
	mlx_string_put(id[0], id[1], iv[xb] + 5, iv[yb] - 5, 0xa0cda1b6, res);
}

/*
void	ft_usrlabel(void *id[2], int iv[4], long double fv[22])
{
	char	s[12];
	char	res[30];
	char	*o;
	char	*p;
	char	*q;

	o = "* km, * $";
	o += 9;
	p = res + 30;
	while (*o != '*')
		*p-- = *o--;
	ft_memset(s, ' ', 11);
	ft_itoav((int)fv[userprice], s);
	q = s + 11;
	while (*q != ' ')
		*p-- = *q--;
	o--;
	while (*o != '*')
		*p-- = *o--;
	ft_memset(s, ' ', 11);
	ft_itoav((int)fv[userkm], s);
	q = s + 11;
	while (*q != ' ')
		*p-- = *q--;
	printf("res = >%s<", p);
	iv[xa] = fv[userkm] / 500;
	iv[ya] = fv[userprice] / 10;
	ft_originfix(iv);
	mlx_string_put(id[0], id[1], iv[xb] + 5, iv[yb] - 5, 0xa0cda1b6, res);
}


void	ft_usrlabel(void *id[2], int iv[4], long double fv[22])
{
	char	*s1;
	char	*s2;
	char	*res;

	res = malloc(sizeof(char) * 30);
	s1 = ft_itoa((int)fv[userkm]);
	printf("s1 = >%s<", s1);
	res = ft_strcat(res, s1);
	s1 = ft_free(&s1);
	res = ft_strcat(res, " km, ");
	s2 = ft_itoa((int)fv[userprice]);
	res = ft_strcat(res, s2);
	s2 = ft_free(&s2);
	res = ft_strcat(res, " $");
	printf("res = >%s<", res);
	iv[xa] = fv[userkm] / 500;
	iv[ya] = fv[userprice] / 10;
	ft_originfix(iv);
	mlx_string_put(id[0], id[1], iv[xb] + 5, iv[yb] - 5, 0xa0cda1b6, res);
	res = ft_free(&res);
}

void	ft_usrlabel(void *id[2], int iv[4], long double fv[22])
{
	char	*s1;
	char	*s2;

	s1 = ft_itoa((int)fv[userkm]);
	s1 = ft_strcat(s1, " km, ");
	s2 = ft_itoa((int)fv[userprice]);
	s2 = ft_strcat(s2, " $");
	s1 = ft_strcat(s1, s2);
	s2 = ft_free(&s2);
	iv[xa] = fv[userkm] / 500;
	iv[ya] = fv[userprice] / 10;
	ft_originfix(iv);
	mlx_string_put(id[0], id[1], iv[xb] + 5, iv[yb] - 5, 0xa0cda1b6, s1);
	s1 = ft_free(&s1);
}
*/
void	ft_tr_line2(void *id[2], int iv[4], long double fv[22])
{
	ft_bzero(iv, sizeof(int) * 4);
	while (iv[xa] < 396271.0 && iv[ya] >= 0)
	{
		iv[ya] = (int)((fv[t0] + (fv[t1] * iv[xa] * 500)) / 10);
		ft_originfix(iv);
		mlx_pixel_put(id[0], id[1], iv[xb], iv[yb], 0xa009ae51);
		iv[xa] += 1;
	}
}
