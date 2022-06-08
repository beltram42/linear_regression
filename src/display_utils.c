/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:59:44 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/06/07 22:10:40 by alambert         ###   ########.fr       */
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

void	ft_originfix(int iv[4])
{
	iv[xb] = iv[xa] + 100;
	iv[yb] = 1000 - iv[ya];
}

void	ft_tr_landmark(void *id[2], int iv[4])
{
	ft_bzero(iv, sizeof(int) * 4);
	while (iv[ya] <= 900)
	{
		ft_originfix(iv);
		mlx_pixel_put(id[0], id[1], iv[xb], iv[yb], 0xa009ae51);
		if (iv[ya] > 0 && iv[yb] == (iv[yb] / 100) * 100)
		{
			mlx_pixel_put(id[0], id[1], iv[xb] - 1, iv[yb], 0xa009ae51);
			mlx_pixel_put(id[0], id[1], iv[xb] + 1, iv[yb], 0xa009ae51);
		}
		iv[ya] += 1;
	}
	ft_bzero(iv, sizeof(int) * 4);
	while (iv[xa] <= 1000)
	{
		ft_originfix(iv);
		mlx_pixel_put(id[0], id[1], iv[xb], iv[yb], 0xa009ae51);
		if (iv[xa] > 0 && iv[xb] == (iv[xb] / 100) * 100)
		{
			mlx_pixel_put(id[0], id[1], iv[xb], iv[yb] - 1, 0xa009ae51);
			mlx_pixel_put(id[0], id[1], iv[xb], iv[yb] + 1, 0xa009ae51);
		}
		iv[xa] += 1;
	}
}

void	ft_tr_dots(void *id[2], int iv[4], long double fdb[9][24])
{
	int	j;
	int	d;

	j = 0;
	while (j < 24)
	{
		iv[xa] = (int)(fdb[km][j] / 400);
		iv[ya] = (int)(fdb[price][j] / 10);
		ft_originfix(iv);
		d = -1;
		while (d <= 1)
		{
			mlx_pixel_put(id[0], id[1], iv[xb] + d, iv[yb], 0xa009ae51);
			mlx_pixel_put(id[0], id[1], iv[xb], iv[yb] + d, 0xa009ae51);
			d++;
		}
		j++;
	}
}

void	ft_tr_line(void *id[2], int iv[4], long double fv[22])
{
	ft_bzero(iv, sizeof(int) * 4);
	while (iv[ya] >= 0)
	{
		iv[ya] = (int)(fv[t0] + (fv[t1] * iv[xa]));
		ft_originfix(iv);
		mlx_pixel_put(id[0], id[1], iv[xb], iv[yb], 0xa009ae51);
		iv[xa] += 1;
	}
}

void	ft_tr_userparam(void *id[2], int iv[4], int max[2], long double fv[22])
{
	iv[xa] = fv[userkm] / 400;
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
