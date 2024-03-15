/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:15 by taehkwon          #+#    #+#             */
/*   Updated: 2024/02/14 12:43:46 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	calc_step(double ray)
{
	if (ray < 0)
		return (-1);
	else
		return (1);
}

double	cal_sidedist(double ray, double pos, double map, double deltadist)
{
	if (ray < 0)
		return ((pos - map) * deltadist);
	else
		return ((map + 1.0 - pos) * deltadist);
}

void	set_rc(int x, t_rc *rc)
{
	rc->cam_x = 2 * x / (double)WIN_WIDTH - 1;
	rc->ray_x = rc->dir_x + rc->plane_x * rc->cam_x;
	rc->ray_y = rc->dir_y + rc->plane_y * rc->cam_x;
	rc->map_x = (int)rc->pos_x;
	rc->map_y = (int)rc->pos_y;
	rc->delta_x = fabs(1 / rc->ray_x);
	rc->delta_y = fabs(1 / rc->ray_y);
	rc->step_x = calc_step(rc->ray_x);
	rc->step_y = calc_step(rc->ray_y);
	rc->sidedist_x = cal_sidedist(rc->ray_x, rc->pos_x, rc->map_x, rc->delta_x);
	rc->sidedist_y = cal_sidedist(rc->ray_y, rc->pos_y, rc->map_y, rc->delta_y);
}
