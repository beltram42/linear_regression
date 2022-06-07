/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:55:17 by alambert          #+#    #+#             */
/*   Updated: 2022/05/08 19:20:04 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		new->next = *alst;
		*alst = new;
	}
	*alst = new;
}
