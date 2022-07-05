/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myenums.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:29:34 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:11:42 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYENUMS_H
# define MYENUMS_H

typedef enum e_fdb
{
	km,
	price,
	prod,
	sqkm,
	sqprice,
	k,
	p,
	sqxmgap,
	sqymgap
}		t_fdb;

typedef enum e_fvar
{
	sumkm,
	sumprice,
	sumprod,
	sumsqkm,
	sumsqprice,
	k_predict,
	learning_rate,
	meank,
	meanp,
	r,
	userkm,
	userprice,
	costa,
	costb,
	costc,
	final_b,
	dtt0,
	dtt1,
	t0,
	t1,
	tt0,
	tt1
}		t_fvar;
#endif