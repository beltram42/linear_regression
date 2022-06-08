/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:18:37 by alambert          #+#    #+#             */
/*   Updated: 2022/06/08 16:55:56 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

enum e_fr
{
	a,
	b,
	c,
	d,
	e
};

void	ft_splitandconvert(char *str, long double fdb[9][24])
{
	char	*token;
	char	*ptr;
	int		i;

	ptr = NULL;
	token = ft_strtok_r(str, ",\n", &ptr);
	token = ft_strtok_r(NULL, ",\n", &ptr);
	i = 0;
	while (i < 24)
	{
		token = ft_strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		fdb[km][i] = ft_strtol(token, (char **) NULL, 10);
		token = ft_strtok_r(NULL, ",\n", &ptr);
		if (!token)
			break ;
		fdb[price][i] = ft_strtol(token, (char **) NULL, 10);
		i++;
	}
}

void	ft_getdata(long double fdb[9][24])
{
	int			fd;
	char		*save;
	int			len;
	struct stat	sb;

	if (stat("data.csv", &sb) == -1)
		return ;
	len = sb.st_size;
	fd = open("data.csv", O_RDONLY);
	if (fd == -1)
		return ;
	save = malloc(sizeof(char) * (len + 1));
	if (!save)
		return ;
	len = read(fd, save, len);
	save[len] = '\0';
	close(fd);
	ft_splitandconvert(save, fdb);
	save = ft_free(&save);
}

void	ft_set0(long double fdb[9][24], long double fv[22])
{
	ft_bzero(fdb, sizeof(long double) * 9 * 24);
	ft_bzero(fv, sizeof(long double) * 22);
}

void	ft_dset(long double fdb[9][24], long double fv[22])
{
	int	j;

	j = 0;
	while (j < 24)
	{
		fv[sumkm] += fdb[km][j];
		fv[meank] = fv[sumkm] / 24.0;
		fv[sumprice] += fdb[price][j];
		fv[meanp] = fv[sumprice] / 24.0;
		fdb[sqkm][j] = cpowf(fdb[km][j], 2);
		fdb[sqprice][j] = cpowf(fdb[price][j], 2);
		fv[sumsqkm] += fdb[sqkm][j];
		fv[sumsqprice] += fdb[sqprice][j];
		fdb[prod][j] = fdb[km][j] * fdb[price][j];
		fv[sumprod] += fdb[prod][j];
		fdb[k][j] = fdb[km][j] / 10000.0;
		fdb[p][j] = fdb[price][j] / 10000.0;
		j++;
	}
	fv[t1] = ((fv[meank] * fv[sumprice]) - fv[sumprod]) \
			/ ((fv[meank] * fv[sumkm]) - fv[sumsqkm]);
	fv[t0] = (fv[meanp] - (fv[t1] * fv[meank]));
	fv[learning_rate] = 0.015;
}

void	ft_corr_coeff(long double fv[22], long double fdb[9][24])
{
	long double	fr[5];
	int			j;

	ft_bzero(fr, sizeof(long double) * 5);
	j = 0;
	while (j < 24)
	{
		fdb[sqxmgap][j] = cpowl(fdb[km][j] - fv[meank], 2.0);
		fdb[sqymgap][j] = cpowl(fdb[price][j] - fv[meanp], 2.0);
		j++;
	}
	j = 0;
	while (j < 24)
	{
		fr[a] += (fdb[km][j] - fv[meank]) * (fdb[price][j] - fv[meanp]);
		fr[b] += fdb[sqxmgap][j];
		fr[c] += fdb[sqymgap][j];
		j++;
	}
	fr[d] = fr[b] * fr[c];
	fr[e] = sqrtl(fr[d]);
	fv[r] = fr[a] / fr[e];
}
