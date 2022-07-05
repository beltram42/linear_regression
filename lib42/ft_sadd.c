/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:57:26 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:14:19 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

long double	ft_sald(long double a, long double b)
{
	long double	ret;

	if ((a + b) > -LDBL_MIN && (a + b) < LDBL_MIN && (a + b) != 0)
	{
		if ((a + b) > 0)
			ret = LDBL_MIN;
		else
			ret = -LDBL_MIN;
		errno = ERANGE;
		return (ret);
	}
	else if ((a + b) > LDBL_MAX || (a + b) < -LDBL_MAX)
	{
		if (a > 0)
			ret = LDBL_MAX;
		else
			ret = -LDBL_MAX;
		errno = ERANGE;
		return (ret);
	}
	else
		return (a + b);
}

double	ft_sad(double a, double b)
{
	double	ret;

	if ((a + b) > -DBL_MIN && (a + b) < DBL_MIN && (a + b) != 0)
	{
		if ((a + b) > 0)
			ret = DBL_MIN;
		else
			ret = -DBL_MIN;
		errno = ERANGE;
		return (ret);
	}
	else if ((a + b) > DBL_MAX || (a + b) < -DBL_MAX)
	{
		if (a > 0)
			ret = DBL_MAX;
		else
			ret = -DBL_MAX;
		errno = ERANGE;
		return (ret);
	}
	else
		return (a + b);
}

float	ft_saf(float a, float b)
{
	float	ret;

	if ((a + b) > -FLT_MIN && (a + b) < FLT_MIN && (a + b) != 0)
	{
		if ((a + b) > 0)
			ret = FLT_MIN;
		else
			ret = -FLT_MIN;
		errno = ERANGE;
		return (ret);
	}
	else if ((a + b) > FLT_MAX || (a + b) < -FLT_MAX)
	{
		if (a > 0)
			ret = FLT_MAX;
		else
			ret = -FLT_MAX;
		errno = ERANGE;
		return (ret);
	}
	else
		return (a + b);
}
