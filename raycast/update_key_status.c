/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_key_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:21 by taehkwon          #+#    #+#             */
/*   Updated: 2024/02/20 20:29:15 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_param *param)
{
	double	rot_angle;

	rot_angle = 0.1;
	if (key == W)
		param->key.w = 1;
	if (key == S)
		param->key.s = 1;
	if (key == A)
		param->key.a = 1;
	if (key == D)
		param->key.d = 1;
	if (key == LEFT)
	{
		param->key.left = 1;
		rotate(rot_angle, param->rc);
	}
	if (key == RIGHT)
	{
		param->key.right = 1;
		rotate(-rot_angle, param->rc);
	}
	if (key == ESC)
		param->key.esc = 1;
	return (0);
}

int	key_release(int key, t_param *param)
{
	if (key == W)
		param->key.w = 0;
	if (key == S)
		param->key.s = 0;
	if (key == A)
		param->key.a = 0;
	if (key == D)
		param->key.d = 0;
	if (key == LEFT)
		param->key.left = 0;
	if (key == RIGHT)
		param->key.right = 0;
	if (key == ESC)
		param->key.esc = 0;
	return (0);
}

int	exit_hook(t_param *param)
{
	mlx_destroy_window(param->mlx->mlx, param->mlx->win);
	exit(0);
}
