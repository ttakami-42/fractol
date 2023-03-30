/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:27:13 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 04:04:20 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color);

void	pixel_put(int value, t_fractol *f, int x, int y)
{
	if (value > 90)
		my_mlx_pixel_put(f, x, y, 0xE00000);
	else if (value > 70)
		my_mlx_pixel_put(f, x, y, 0x0E0000);
	else if (value > 50)
		my_mlx_pixel_put(f, x, y, 0xAA0000);
	else if (value > 30)
		my_mlx_pixel_put(f, x, y, 0x6E0000);
	else if (value > 10)
		my_mlx_pixel_put(f, x, y, 0x550000);
	else if (value > 5)
		my_mlx_pixel_put(f, x, y, 0x400000);
	else if (value > 4)
		my_mlx_pixel_put(f, x, y, 0x300000);
	else if (value > 3)
		my_mlx_pixel_put(f, x, y, 0x200000);
	else if (value > 2)
		my_mlx_pixel_put(f, x, y, 0x100000);
	else if (value > 1)
		my_mlx_pixel_put(f, x, y, 0x050000);
	else
		my_mlx_pixel_put(f, x, y, 0x000000);
}

static void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->data_addr + (y * f->size_line + x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
