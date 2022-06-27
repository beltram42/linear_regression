/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:48:14 by alambert          #+#    #+#             */
/*   Updated: 2022/06/27 22:02:51 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

void	ft_userkmparsing(long double fv[22])
{
	if (fv[userkm] < 0)
	{
		printf("\nkm# should be more than 0\n");
		fv[userkm] = 0;
		fv[userprice] = 8499;
		printf("\nCar price for 0 km is: 8499 $");
	}
	else
	{
		printf("\nkm# should be less than 396271\n");
		fv[userkm] = 396271;
		fv[userprice] = 0;
		printf("\nCar price for more than 396271 km is: 0 $");
	}
	return ;
}

void	ft_userprice(long double fv[22])
{
	char	*str;
	char	*endptr;

	printf("Please enter km# from 0 to 396270:\n");
	str = ft_malgets(7);
	endptr = str;
	fv[userkm] = ft_strtol(str, &endptr, 10);
	if (endptr == str || fv[userkm] < 0 || fv[userkm] > 396270)
	{
		ft_userkmparsing(fv);
		str = ft_free(&str);
	}
	else
	{
		printf("\nkm# is in the range\n\n");
		str = ft_free(&str);
		fv[userprice] = fv[t0] + (fv[t1] * fv[userkm]);
		printf("Price for %d km is: %d $", (int)fv[userkm], (int)fv[userprice]);
	}
}
