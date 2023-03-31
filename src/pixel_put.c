/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:27:13 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 15:51:02 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_trgb(int t, int r, int g, int b);
static void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color);

void	pixel_put(int value, t_fractol *f, int x, int y)
{
	int	color;
	int	n;

	n = 255 - value;
	if (value == 255)
		color = create_trgb(8, 0, 0, 0);
	else if (value >= 192)
		color = create_trgb(64, n / 10, n, n / 5);
	else if (value >= 128)
		color = create_trgb(64, n / 8, n, n / 4);
	else if (value >= 64)
		color = create_trgb(64, n / 6, n, n / 3);
	else if (value >= 32)
		color = create_trgb(64, n / 4, n, n / 2);
	else if (value >= 24)
		color = create_trgb(64, n / 2, n, 0);
	else if (value >= 16)
		color = create_trgb(128, 250, 178, 102);
	else
		color = create_trgb(128, 255, 178, 102);
	my_mlx_pixel_put(f, x, y, color);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->data_addr + (y * f->size_line + x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
