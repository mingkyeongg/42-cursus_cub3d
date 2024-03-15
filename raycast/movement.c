/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:31 by taehkwon          #+#    #+#             */
/*   Updated: 2024/02/16 17:26:58 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate(double rot_ang, t_rc *rc)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = rc->dir_x;
	old_plane_x = rc->plane_x;
	rc->dir_x = rc->dir_x * cos(rot_ang) - rc->dir_y * sin(rot_ang);
	rc->dir_y = old_dir_x * sin(rot_ang) + rc->dir_y * cos(rot_ang);
	rc->plane_x = rc->plane_x * cos(rot_ang) - rc->plane_y * sin(rot_ang);
	rc->plane_y = old_plane_x * sin(rot_ang) + rc->plane_y * cos(rot_ang);
}

void	move(double x, double y, t_param *param)
{
	double	move_speed;

	move_speed = 0.137;
	x *= move_speed;
	y *= move_speed;
	if (param->world_map[(int)(param->rc->pos_x + x)][(int)(param->rc->pos_y)] \
		== '0')
		param->rc->pos_x += x;
	if (param->world_map[(int)(param->rc->pos_x)][(int)(param->rc->pos_y + y)] \
		== '0')
		param->rc->pos_y += y;
}

void	check_inputs(t_param *param)
{
	t_key	*key;

	key = &(param->key);
	if (key->w)
		move(param->rc->dir_x, param->rc->dir_y, param);
	if (key->s)
		move(-(param->rc->dir_x), -(param->rc->dir_y), param);
	if (key->a)
		move(-param->rc->dir_y, param->rc->dir_x, param);
	if (key->d)
		move(param->rc->dir_y, -param->rc->dir_x, param);
	if (key->esc)
	{
		mlx_destroy_window(param->mlx->mlx, param->mlx->win);
		exit(0);
	}
}
