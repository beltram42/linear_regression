/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/07/07 15:54:09 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"
#include "myenums.h"

void	ft_1stpartprint(long double fdb[9][24], long double fv[22])
{
	printf("\n\n\n\n       ########################\n");
	printf("       #  GENUINE REGRESSION  #\n");
	printf("       ########################\n\n");
	printf("From classical linear regression calculus, we get:\n\n");
	printf("theta0: %Lf, theta1: %Lf\n", fv[t0], fv[t1]);
	printf("=> y = %Lfx + %Lf\n\n", fv[t1], fv[t0]);
	ft_corr_ratio(fdb, fv);
	printf("Correlation ratio [0,1]:\nrho = %Lf\n", ft_absld(fv[r]));
	printf("=> dependability = %Lf %%", (ft_absld(fv[r])) * 100);
	printf("\n\n\n\n            ##############\n");
	printf("            #  ML MODEL  #\n");
	printf("            ##############\n\n");
	printf("Before training:\n");
	printf("theta0: %Lf, theta1: %Lf\n\n", fv[tt0], fv[tt1]);
}

void	ft_2ndpartprint(void)
{
	printf("\n\n\n\n          ####################\n");
	printf("          #  MODEL TRAINING  #\n");
	printf("          ####################\n\n");
}

int	main(void)
{
	long double	fdb[9][24];
	long double	fv[22];
	void		*id[2];
	int			i;

	i = 0;
	ft_set0(fdb, fv);
	ft_getdata(fdb);
	ft_dset(fdb, fv);
	ft_1stpartprint(fdb, fv);
	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 1200, 1100, "LR_chart");
	ft_display0(id, fv, fdb);
	mlx_key_hook(id[1], ft_manage_input, id);
	ft_userprice(fv);
	ft_display1(id, fv);
	ft_2ndpartprint();
	ft_regr(fdb, fv);
	ft_display2(id, fv);
	ft_userprice(fv);
	printf("\n");
	ft_display3(id, fv);
	mlx_hook(id[1], 17, 0, ft_exit, id);
	mlx_loop(id[0]);
	return (0);
}
