/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:37:10 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 06:09:32 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HIGHT, WINDOW_TITLE);
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HIGHT);
	f->data_addr = mlx_get_data_addr(f->img_ptr, &f->bits_per_pixel, \
	&f->size_line, &f->endian);
	f->start_x = -2.0;
	f->start_y = 2.0;
	f->end_x = 2.0;
	f->end_y = -2.0;
}

int	deinit_fractol(t_fractol *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_display(f->mlx_ptr);
	exit(EXIT_SUCCESS);
}
