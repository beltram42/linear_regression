/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:48:14 by alambert          #+#    #+#             */
/*   Updated: 2022/06/07 17:59:30 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lr.h"
#include "../myenums.h"

int	ft_up_shell(long double fv[24])
{
	ft_userprice(fv);
	return (0);
}

void	ft_userprice(long double fv[24])
{
	char	*str;
	char	*endptr;

	printf("please enter #km from 0 to 397134:\n");
	str = ft_malgets(6);
	endptr = str;
	fv[userkm] = ft_strtol(str, &endptr, 10);
	if (endptr == str || fv[userkm] > 397134)
	{
		printf("#km should be less than 397134\n");
		fv[userkm] = 397135;
		str = ft_free(&str);
		fv[userprice] = 0;
		printf("car price for more than 397134km is: 0\n");
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
