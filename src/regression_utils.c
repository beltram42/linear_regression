/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:09:09 by alambert          #+#    #+#             */
/*   Updated: 2022/07/07 15:37:18 by alambert         ###   ########.fr       */
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

void	ft_iterationprint(long double fv[22], int j, long double diff)
{
	printf("iteration #%d\n", j);
	printf("cost delta #%d = %LE\n", j, diff);
	printf("theta0: %Lf, theta1: %Lf\n\n", fv[tt0] * 10000.0, fv[tt1]);
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
	ft_iterationprint(fv, j++, diff);
	while (diff > 0.00000000005)
	{
		ft_grad_dsc(fdb, fv);
		if (j % 2 == 0)
			fv[costc] = fv[costa];
		if (j % 2 == 1)
			fv[costb] = fv[costa];
		diff = ft_absld(fv[costb] - fv[costc]);
		if (j == (j / 1000) * 1000)
			ft_iterationprint(fv, j, diff);
		j++;
	}
	ft_iterationprint(fv, j, diff);
	printf("=> y = %Lfx + %Lf\n\n", fv[tt1], fv[tt0] * 10000.0);
	ft_precision_eval(fv);
}

void	ft_precision_eval(long double fv[22])
{
	long double	sum1;
	long double	sum2;
	long double	precision;
	int			i;

	fv[t1] = ((fv[meank] * fv[sumprice]) - fv[sumprod]) \
			/ ((fv[meank] * fv[sumkm]) - fv[sumsqkm]);
	fv[t0] = (fv[meanp] - (fv[t1] * fv[meank]));
	printf("\n\nCompared with classical LR equation\n");
	printf("(y = %Lfx + %Lf)\n\n", fv[t1], fv[t0]);
	i = 0;
	sum1 = 0.0;
	sum2 = 0.0;
	fv[tt0] *= 10000.0;
	printf("temp theta 0 = %Lf\n", fv[tt0]);
	while (i < 396271)
	{
		sum1 += (fv[t1] * i + fv[t0]);
		sum2 += (fv[tt1] * i + fv[tt0]);
		i++;
	}
	precision = (1 - ft_absld((sum2 - sum1) / sum1));
	printf("Our ML model:\ny = %Lfx + %Lf\n", fv[tt1], fv[tt0]);
	printf("has a precision of: %Lf %%\n\n\n", precision * 100);
}
