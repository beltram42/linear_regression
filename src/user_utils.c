/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:48:14 by alambert          #+#    #+#             */
/*   Updated: 2022/06/08 15:08:50 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

int	ft_up_shell(long double fv[22])
{
	ft_userprice(fv);
	return (0);
}

void	ft_userprice(long double fv[22])
{
	char	*str;
	char	*endptr;

	printf("please enter #km from 0 to 396270:\n");
	str = ft_malgets(6);
	endptr = str;
	fv[userkm] = ft_strtol(str, &endptr, 10);
	if (endptr == str || fv[userkm] > 396270)
	{
		printf("#km should be less than 396270\n");
		fv[userkm] = 396271;
		str = ft_free(&str);
		fv[userprice] = 0;
		printf("car price for more than 396270km is: 0\n");
		return ;
	}
	else
	{
		printf("#km is in the range\n");
		str = ft_free(&str);
		fv[userprice] = fv[t0] + (fv[t1] * fv[userkm]);
		printf("price for %Lf km: %Lf\n", fv[userkm], fv[userprice]);
	}
}
