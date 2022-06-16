/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:59:44 by anthonylamb       #+#    #+#             */
/*   Updated: 2022/06/16 21:21:36 by alambert         ###   ########.fr       */
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
		mlx_pixel_put(id[0], id[1], iv[xb], iv[yb], 0xa0ffffff);
		if (iv[ya] > 0 && iv[yb] == (iv[yb] / 100) * 100)
		{
			mlx_pixel_put(id[0], id[1], iv[xb] - 1, iv[yb], 0xa0ffffff);
			mlx_pixel_put(id[0], id[1], iv[xb] + 1, iv[yb], 0xa0ffffff);
		}
		iv[ya] += 1;
	}
	ft_bzero(iv, sizeof(int) * 4);
	while (iv[xa] <= 1000)
	{
		ft_originfix(iv);
		mlx_pixel_put(id[0], id[1], iv[xb], iv[yb], 0xa0ffffff);
		if (iv[xa] > 0 && iv[xb] == (iv[xb] / 100) * 100)
		{
			mlx_pixel_put(id[0], id[1], iv[xb], iv[yb] - 1, 0xa0ffffff);
			mlx_pixel_put(id[0], id[1], iv[xb], iv[yb] + 1, 0xa0ffffff);
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
		iv[xa] = (int)(fdb[km][j] / 500);
		iv[ya] = (int)(fdb[price][j] / 10);
		ft_originfix(iv);
		d = -1;
		while (d <= 1)
		{
			mlx_pixel_put(id[0], id[1], iv[xb] + d, iv[yb], 0xa0ff1a00);
			mlx_pixel_put(id[0], id[1], iv[xb], iv[yb] + d, 0xa0ff1a00);
			d++;
		}
		j++;
	}
}

void	ft_labels(void *id[2], int iv[4])
{
	char	*str;
	int		i;

	ft_bzero(iv, sizeof(int) * 4);
	i = 0;
	while (i < 10)
	{
		iv[xa] = i * 50000;
		str = ft_itoa(iv[xa]);
		iv[xa] /= 500;
		ft_originfix(iv);
		mlx_string_put(id[0], id[1], iv[xb], 1040, 0xa0ffffff, str);
		str = ft_free(&str);
		iv[ya] = i * 1000;
		str = ft_itoa(iv[ya]);
		iv[ya] /= 10;
		ft_originfix(iv);
		mlx_string_put(id[0], id[1], 70, iv[yb], 0xa0ffffff, str);
		str = ft_free(&str);
		i++;
	}
}

void	ft_tr_line(void *id[2], int iv[4], long double fv[22])
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

