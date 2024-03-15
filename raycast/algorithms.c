/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:26 by taehkwon          #+#    #+#             */
/*   Updated: 2024/02/16 16:42:01 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda(t_rc *rc, t_param *param)
{
	while (1)
	{
		if (rc->sidedist_x < rc->sidedist_y)
		{
			rc->sidedist_x += rc->delta_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->sidedist_y += rc->delta_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (param->world_map[rc->map_x][rc->map_y] && \
			(param->world_map[rc->map_x][rc->map_y] == '1'))
			break ;
	}
}

double	calc_perpdist(double sidedist, double deltadist)
{
	return (sidedist - deltadist);
}
