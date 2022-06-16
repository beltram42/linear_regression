/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:34:35 by alambert          #+#    #+#             */
/*   Updated: 2022/06/16 22:39:50 by alambert         ###   ########.fr       */
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

void	ft_display0(void *id[2], long double fv[22], long double fdb[9][24])
{
	int		iv[4];

	ft_bzero(iv, sizeof(int) * 4);
	ft_tr_landmark(id, iv);
	ft_labels(id, iv);
	ft_tr_dots(id, iv, fdb);
	ft_tr_line(id, iv, fv);
}

void	ft_display1(void *id[2], long double fv[22])
{
	int		iv[4];
	int		max[2];

	ft_bzero(iv, sizeof(int) * 4);
	ft_bzero(max, sizeof(int) * 2);
	ft_tr_userparam(id, iv, max, fv);
	ft_usrlabel(id, iv, fv);
}
