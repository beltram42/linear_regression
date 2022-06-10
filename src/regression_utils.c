/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by alambert          #+#    #+#             */
/*   Updated: 2022/06/10 19:24:39 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

void	ft_grad_dsc(long double fdb[9][24], long double fv[22])
{
	int	j;

	fv[dtt0] = 0.0;
	fv[dtt1] = 0.0;
	fv[costa] = 0.0;
	j = 0;
	while (j < 24)
	{
		fv[costa] += ((fv[tt1] * fdb[k][j] + fv[tt0]) \
				- fdb[p][j] * (fv[tt1] * fdb[k][j] + fv[tt0]) \
				- fdb[p][j]) / (2 * 24);
		fv[dtt1] += ((fv[tt1] * fdb[k][j] + fv[tt0]) \
				- fdb[p][j]) / 24;
		fv[dtt0] += (((fv[tt1] * fdb[k][j] + fv[tt0]) \
		- fdb[p][j]) * fdb[k][j]) / 24;
		j++;
	}
	fv[tt1] = fv[tt1] - (fv[learning_rate] * fv[dtt0]);
	fv[tt0] = fv[tt0] - (fv[learning_rate] * fv[dtt1]);
}

void	ft_regr(long double fdb[9][24], long double fv[22])
{
	int			j;
	long double	diff;

	j = 0;
	ft_grad_dsc(fdb, fv);
	fv[costc] = fv[costa];
	ft_grad_dsc(fdb, fv);
	fv[costb] = fv[costa];
	diff = ft_absld(fv[costb] - fv[costc]);
	printf("diff0 = %Lf\n", diff);
	while (diff > 0.00000000005)
	{
		ft_grad_dsc(fdb, fv);
		if (j % 2 == 0)
			fv[costc] = fv[costa];
		if (j % 2 == 1)
			fv[costb] = fv[costa];
		diff = ft_absld(fv[costb] - fv[costc]);
		j++;
	}
	printf("diffn = %LE\n", diff);
	printf("iteration# = %d\n", j);
}

void	ft_42lr(long double fdb[9][24], long double fv[22])
{
	long double	tmpt0;
	long double	tmpt1;
	long double	tmp0;
	long double	tmp1;
	long double	lr;
	int			i;

	i = 0;
	tmp0 = 0.0;
	tmp1 = 0.0;
	while (i < 24)
	{
		tmp0 += fv[t1] * fdb[km][i] + fv[t0] - fdb[price][i];
		tmp1 += (fv[t1] * fdb[km][i] + fv[t0] - fdb[price][i]) * fdb[km][i];
		i++;
	}
	lr = (24 * fv[tt0]) / tmp0;
	printf("42 formula lr (via tt0) = %Lf\n", lr);
	lr = (24 * fv[tt1]) / tmp1;
	printf("42 formula lr (via tt1) = %Lf\n", lr);
	tmpt0 = fv[learning_rate] * (1/ 24) * tmp0;
	printf("tempt0 = %Lf\n", tmpt0 * 100000000.0);
	tmpt1 = fv[learning_rate] * (1/ 24) * tmp1;
	printf("tempt1 = %Lf\n", tmpt1 * 100000000.0);
}

/*
		printf("iteration# = %d\n", j);
		printf("diff = %LE\n", diff);
		printf("fv[costa] = %Lf\n", fv[costa]);
		printf("fv[dtt0] = %LE\n", fv[dtt0]);
		printf("fv[dtt1] = %LE\n", fv[dtt1]);
		printf("fv[tt0] = %LE\n", fv[tt0]);
		printf("fv[tt1] = %LE\n", fv[tt1]);*/