/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:34:35 by alambert          #+#    #+#             */
/*   Updated: 2022/06/06 21:09:53 by alambert         ###   ########.fr       */
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

void	ft_display0(void *id[2], long double fv[24], long double fdb[9][24])
{
	int		iv[4];

	ft_bzero(iv, sizeof(int) * 4);
	ft_tr_landmark(id, iv);
	ft_tr_dots(id, iv, fdb);
	ft_tr_line(id, iv, fv);
}

void	ft_display1(void *id[2], long double fv[24])
{
	int		iv[4];
	int		max[2];
	int		len;
	char	*s1;
	char	*s2;

	s1 = ft_itoa(fv[userkm]);
	len = strlen(s1);
	*(s1 + len) = ',';
	*(s1 + len +1) = ' ';
	*(s1 + len + 2) = '\0';
	s2 = ft_itoa(fv[userprice]);
	s1 = ft_strjoin(s1, s2);
	ft_bzero(iv, sizeof(int) * 4);
	ft_tr_userparam(id, iv, max, fv);
	mlx_string_put(id[0], id[1], max[x], iv[yb], 0xa009ae51, s1);
	s1 = ft_free(&s1);
}
