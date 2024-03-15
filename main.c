/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:30:10 by minkylee          #+#    #+#             */
/*   Updated: 2024/02/20 21:26:49 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(char *txt)
{
	write(2, "Error\n", 6);
	while (*txt)
		write(2, txt++, 1);
	write(2, "\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_param	*param;
	t_img	img;

	if (argc != 2)
		ft_exit("Invalid arguments");
	param = malloc(sizeof(t_param));
	param->rc = malloc(sizeof(t_rc));
	param->mlx = malloc(sizeof(t_mlx));
	param->img = &img;
	init_param(param);
	init_key_status(param);
	param->map_file_name = argv[1];
	parse(param);
	param->mlx->mlx = mlx_init();
	param->mlx->win = mlx_new_window(param->mlx->mlx, \
		WIN_WIDTH, WIN_HEIGHT, "cub3D");
	mlx_do_key_autorepeaton(param->mlx->mlx);
	mlx_hook(param->mlx->win, 2, 1L << 0, key_press, param);
	mlx_hook(param->mlx->win, 3, 1L << 1, key_release, param);
	mlx_hook(param->mlx->win, 17, 0, exit_hook, param);
	mlx_loop_hook(param->mlx->mlx, &run_3d, param);
	mlx_loop(param->mlx->mlx);
}
