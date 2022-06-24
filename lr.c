/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:14 by alambert          #+#    #+#             */
/*   Updated: 2022/06/24 16:11:17 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lr.h"
#include "myenums.h"

int	ft_exit(void *id[2])
{
	mlx_clear_window(id[0], id[1]);
	mlx_destroy_window(id[0], id[1]);
	mlx_destroy_display(id[0]);
	free(id[0]);
	exit(EXIT_SUCCESS);
	return (0);
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
	printf("fv[t0] = %Lf\n", fv[t0]);
	printf("fv[t1] = %Lf\n", fv[t1]);
	printf("\n");
	ft_corr_coeff(fdb, fv);
	printf("fv[r] = %Lf\n", fv[r]);
	printf("\n");
	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 1200, 1100, "LR_chart");
	ft_display0(id, fv, fdb);
	ft_userprice(fv);
	ft_display1(id, fv);
	mlx_hook(id[1], 17, 0, ft_exit, id);
	//mlx_key_hook(id[1], ft_exit, id);
	mlx_loop(id[0]);
	return (0);
}

	//ft_42lr(fdb, fv);
	/*
	ft_regr(fdb, fv);
	fv[final_b] = fv[tt1] * 10000.0;
	fv[k_predict] = 10.0;
	printf("fv[costa] = %Lf\n", fv[costa]);
	printf("fv[costb] = %Lf\n", fv[costb]);
	printf("fv[costc] = %Lf\n", fv[costc]);
	printf("fv[final_b] = %Lf\n", fv[final_b]);
	printf("fv[dtt0] = %Lf\n", fv[dtt0]);
	printf("fv[dtt1] = %Lf\n", fv[dtt1]);
	printf("fv[tt0] = %Lf\n", fv[tt0]);
	printf("fv[tt1] = %Lf\n", fv[tt1]);
	printf("lf[userkm] = %Lf\n", fv[userkm]);
	printf("lf[userprice] = %Lf\n", fv[userprice]);

	
	id[0] = mlx_init();
	id[1] = mlx_new_window(id[0], 1200, 1100, "LR_chart");
	ft_display0(id, fv, fdb);
	mlx_key_hook(id[1], ft_up_shell, fv);
	ft_display1(id, fv);
	mlx_hook(id[1], 17, 0, ft_exit, id);
	mlx_key_hook(id[1], ft_exit, id);
	mlx_loop(id[0]);
	*/

/*while (i < 24)
	{
		printf("fdb[km][%d] = %Lf\n", i, fdb[km][i]);
		printf("fdb[price]][%d] = %Lf\n", i, fdb[price][i]);
		printf("fdb[k][%d] = %Lf\n", i, fdb[k][i]);
		printf("fdb[p][%d] = %Lf\n", i, fdb[p][i]);
		printf("fdb[prod][%d] = %Lf\n", i, fdb[prod][i]);
		printf("fdb[sqkm][%d] = %Lf\n", i, fdb[sqkm][i]);
		printf("fdb[sqprice]][%d] = %Lf\n", i, fdb[sqprice][i]);
		printf("fdb[sqxmgap]][%d] = %Lf\n", i, fdb[sqxmgap][i]);
		printf("fdb[sqymgap]][%d] = %Lf\n", i, fdb[sqymgap][i]);
		printf("\n");
		i++;
	}
	printf("\n");
	printf("fv[sumkm] = %Lf\n", fv[sumkm]);
	printf("fv[sumprice] = %Lf\n", fv[sumprice]);
	printf("fv[sumprod] = %Lf\n", fv[sumprod]);
	printf("fv[sumsqkm] = %Lf\n", fv[sumsqkm]);
	printf("fv[sumsqprice] = %Lf\n", fv[sumsqprice]);
	printf("\n");
	printf("fv[k_predict] = %Lf\n", fv[k_predict]);
	printf("fv[learning_rate] = %Lf\n", fv[learning_rate]);
	printf("fv[meank] = %Lf\n", fv[meank]);
	printf("fv[meanp] = %Lf\n", fv[meanp]);
	*/

/*
int	ft_exit_shell(void *id[2])
{
	
	return (0);
}

int	esc_singleton(void);


void	*ft_mlx(void)
{
	static void	*mlx_ptr = (void *)0;

	if (!mlx_ptr)
	{
		id[0] = mlx_init();
		id[1] = mlx_new_window(id[0], 1200, 1100, "LR_chart");
	}
	return (mlx_ptr);
}
*/