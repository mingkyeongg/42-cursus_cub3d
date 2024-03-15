/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkylee <minkylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:19 by taehkwon          #+#    #+#             */
/*   Updated: 2024/02/16 16:46:13 by minkylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mlx_pixel_input(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + y * img->len + x * (img->bpp / 8);
	*(unsigned int *)dst = color;
}

int	get_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + y * img->len + x * (img->bpp / 8);
	return (*(unsigned int *)dst);
}

void	clear_screen(t_param *param)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
			*(int *)(param->img->addr + (y * param->img->len + x++ *\
				(param->img->bpp / 8))) = param->ceiling_color;
		y++;
	}
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			*(int *)(param->img->addr + (y * param->img->len + x++ *\
				(param->img->bpp / 8))) = param->floor_color;
		y++;
	}
}

void	print_tex(int x, t_rc *rc, t_img *texs, t_img *img)
{
	int		line_height;
	int		color;
	int		y;

	line_height = (int)(WIN_HEIGHT / rc->perpdist);
	put_draw_start_end(rc, line_height);
	decision_tex_num(rc);
	return_wall_x(rc);
	rc->step = 1.0 * TH / line_height;
	rc->tex_pos = \
		(rc->draw_start - WIN_HEIGHT / 2 + line_height / 2) * rc->step;
	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		rc->tex_y = (int)rc->tex_pos & (texs[rc->tex_num].h - 1);
		rc->tex_pos += rc->step;
		decision_x_and_y(rc, texs);
		color = get_color(&(texs[rc->tex_num]), rc->tex_x, rc->tex_y);
		mlx_pixel_input(img, x, y, color);
		y++;
	}
}
