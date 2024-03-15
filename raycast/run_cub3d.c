/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:24 by taehkwon          #+#    #+#             */
/*   Updated: 2024/02/16 17:26:47 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pre_processing_run_3d(t_param *param, t_img *img, t_mlx *mlx)
{
	check_inputs(param);
	init_img(mlx, img);
	clear_screen(param);
}

int	run_3d(t_param *param)
{
	t_mlx	*mlx;
	t_img	*img;
	t_rc	*rc;
	int		x;

	mlx = param->mlx;
	img = param->img;
	rc = param->rc;
	pre_processing_run_3d(param, img, mlx);
	x = 0;
	while (x < WIN_WIDTH)
	{
		set_rc(x, rc);
		dda(rc, param);
		if (rc->side == 0)
			rc->perpdist = calc_perpdist(rc->sidedist_x, rc->delta_x);
		else
			rc->perpdist = calc_perpdist(rc->sidedist_y, rc->delta_y);
		print_tex(x, rc, param->texs, param->img);
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	mlx_destroy_image(mlx->mlx, img->img);
	return (0);
}
