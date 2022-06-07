/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by alambert          #+#    #+#             */
/*   Updated: 2022/06/07 17:59:03 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

enum e_fr
{
	l,
	m,
	n,
	o
};

void	ft_grad_dsc(long double fdb[9][24], long double fv[24])
{
	int	j;

	fv[dtt0] = 0.0;
	fv[dtt1] = 0.0;
	fv[costa] = 0.0;
	j = 0;
	while (j < 24)
	{
		fv[costa] += ((fv[tt0] * fdb[k][j] + fv[tt1]) \
				- fdb[p][j] * (fv[tt0] * fdb[k][j] + fv[tt1]) \
				- fdb[p][j]) / (2 * 24);
		fv[dtt1] += ((fv[tt0] * fdb[k][j] + fv[tt1]) \
				- fdb[p][j]) / 24;
		fv[dtt0] += (((fv[tt0] * fdb[k][j] + fv[tt1]) \
		- fdb[p][j]) * fdb[k][j]) / 24;
		j++;
	}
	fv[tt0] = fv[tt0] - (fv[learning_rate] * fv[dtt0]);
	fv[tt1] = fv[tt1] - (fv[learning_rate] * fv[dtt1]);
}

void	ft_regr(long double fdb[9][24], long double fv[24])
{
	int		j;
	long double	diff;

	j = 0;
	ft_grad_dsc(fdb, fv);
	fv[costc] = fv[costa];
	ft_grad_dsc(fdb, fv);
	fv[costb] = fv[costa];
	diff = ft_absld(fv[costb] - fv[costc]);
	printf("diff0 = %Lf\n", diff);
	while (diff > 0.0000000001)
	{
		ft_grad_dsc(fdb, fv);
		if (j % 2 == 0)
			fv[costc] = fv[costa];
		if (j % 2 == 1)
			fv[costb] = fv[costa];
		diff = ft_absld(fv[costb] - fv[costc]);
		printf("iteration# = %d\n", j);
		printf("diff = %LE\n", diff);
		printf("fv[costa] = %Lf\n", fv[costa]);
		printf("fv[dtt0] = %LE\n", fv[dtt0]);
		printf("fv[dtt1] = %LE\n", fv[dtt1]);
		printf("fv[tt0] = %LE\n", fv[tt0]);
		printf("fv[tt1] = %LE\n", fv[tt1]);
		j++;
	}
	printf("diffn = %LE\n", diff);
	printf("iteration# = %d\n", j);
}

void	ft_corr_rate(long double fv[24], long double fdb[9][24])
{
	long double	fr[4];
	int		j;

	ft_bzero(fr, sizeof(long double) * 4);
	j = 0;
	while (j < 24)
	{
		fr[l] += (fdb[km][j] - fv[meank]) * (fdb[price][j] - fv[meanp]);
		fr[m] += (fdb[km][j] - fv[meank]) * (fdb[km][j] - fv[meank]);
		fr[n] += (fdb[price][j] - fv[meanp]) * (fdb[price][j] - fv[meanp]);
	}
	fr[o] = sqrtf(fr[m] * fr[n]);
	fv[r] = fr[l] / fr[o];
}