/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:48:14 by alambert          #+#    #+#             */
/*   Updated: 2022/07/07 16:16:21 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

void	ft_useroutofrangekm(long double fv[22], int sw[1])
{
	if (fv[userkm] < 0)
	{
		printf("\nkm# should be more than 0\n");
		fv[userkm] = 0;
		fv[userprice] = 8499;
		printf("\nCar price for 0 km is: 8499 $");
		sw[0] = 1;
	}
	else
	{
		printf("\nkm# should be less than 396271\n");
		fv[userkm] = 396271;
		fv[userprice] = 0;
		printf("\nCar price for more than 396271 km is: 0 $");
		sw[0] = 1;
	}
	return ;
}

void	ft_usermaincase(long double fv[22], int sw[1])
{
	printf("\nkm# is in the range\n\n");
	fv[userprice] = fv[tt0] + (fv[tt1] * fv[userkm]);
	printf("Price for %d km is: %d $", (int)fv[userkm], (int)fv[userprice]);
	sw[0] = 1;
}

void	ft_priceshell(long double fv[22], int sw[1])
{
	char	*str;
	char	*endptr;

	printf("Please enter km# from 0 to 396270:\n");
	str = ft_malgets(7);
	endptr = str;
	fv[userkm] = ft_strtol(str, &endptr, 10);
	if (endptr == str)
	{
		printf("\033[\n0;31mWrong format. Only digits please.\033[0m\n\n");
		str = ft_free(&str);
		sw[0] = 0;
	}
	else if ((fv[userkm] < 0 || fv[userkm] > 396270) && (fv[tt1] != 0))
	{
		ft_useroutofrangekm(fv, sw);
		str = ft_free(&str);
	}
	else
	{
		ft_usermaincase(fv, sw);
		str = ft_free(&str);
	}
}

void	ft_userprice(long double fv[22])
{
	int	sw[1];

	sw[0] = 0;
	while (sw[0] == 0)
		ft_priceshell(fv, sw);
}
