/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:27:44 by taehkwon          #+#    #+#             */
/*   Updated: 2024/02/20 21:16:20 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_rc(t_param *param)
{
	param->rc->pos_x = -1;
	param->rc->pos_y = -1;
	param->rc->dir_x = 0.0;
	param->rc->dir_y = 0.0;
	param->rc->plane_x = 0.0;
	param->rc->plane_y = 0.0;
}

void	init_texs(t_param *param)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		param->texs[i].img = NULL;
		param->texs[i].w = 64;
		param->texs[i].h = 64;
		i++;
	}
}

void	init_param(t_param *param)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		param->f_color[i] = -1;
		param->c_color[i] = -1;
		i++;
	}
	init_texs(param);
	param->img->img = NULL;
	param->map_width = -1;
	param->map_height = -1;
	param->map_file_name = NULL;
	init_rc(param);
}

void	init_key_status(t_param *param)
{
	param->key.w = 0;
	param->key.a = 0;
	param->key.s = 0;
	param->key.d = 0;
	param->key.left = 0;
	param->key.right = 0;
	param->key.esc = 0;
}

void	init_img(t_mlx *mlx, t_img *img)
{
	img->w = WIN_WIDTH;
	img->h = WIN_HEIGHT;
	img->img = mlx_new_image(mlx->mlx, img->w, img->h);
	img->addr = mlx_get_data_addr \
		(img->img, &(img->bpp), &(img->len), &(img->endian));
}
