/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:40:12 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/16 17:52:08 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	decision_tex_num(t_rc *rc)
{
	if (rc->side == 0 && rc->ray_x < 0)
		rc->tex_num = 3;
	else if (rc->side == 0 && rc->ray_x >= 0)
		rc->tex_num = 2;
	else if (rc->side == 1 && rc->ray_y > 0)
		rc->tex_num = 0;
	else if (rc->side == 1 && rc->ray_y <= 0)
		rc->tex_num = 1;
	else
		rc->tex_num = 0;
}

void	return_wall_x(t_rc *rc)
{
	double	wall_x;

	if (rc->side == 0)
		wall_x = rc->pos_y + rc->perpdist * rc->ray_y;
	else
		wall_x = rc->pos_x + rc->perpdist * rc->ray_x;
	wall_x -= floor((wall_x));
	rc->tex_x = (int)(wall_x * (double)TW);
	if (rc->side == 0 && rc->ray_x > 0)
		rc->tex_x = TW - rc->tex_x - 1;
	if (rc->side == 1 && rc->ray_y < 0)
		rc->tex_x = TW - rc->tex_x - 1;
}

void	put_draw_start_end(t_rc *rc, int line_height)
{
	rc->draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (rc->draw_end >= WIN_HEIGHT)
		rc->draw_end = WIN_HEIGHT - 1;
}

void	decision_x_and_y(t_rc *rc, t_img *texs)
{
	if (rc->tex_x < 0)
			rc->tex_x = 0;
	else if (rc->tex_x >= texs[rc->tex_num].w)
		rc->tex_x = texs[rc->tex_num].w - 1;
	if (rc->tex_y < 0)
		rc->tex_y = 0;
	else if (rc->tex_y >= texs[rc->tex_num].h)
		rc->tex_y = texs[rc->tex_num].h - 1;
}
