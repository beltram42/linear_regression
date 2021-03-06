/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:28:47 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:15:46 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

int	ft_iscntrl(char c)
{
	if (c <= 31 || c == 127)
		return (1);
	return (0);
}
