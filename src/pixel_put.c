/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:27:13 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 16:55:21 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_trgb(int t, int r, int g, int b);
static void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color);

void	pixel_put(int value, t_fractol *f, int x, int y)
{
	int	color;

	if (value >= 97)
		color = create_trgb(8, 40, value * 2, value);
	else if (value >= 85)
		color = create_trgb(8, 40, value * 2, value * 2);
	else if (value >= 80)
		color = create_trgb(64, 40, value * 2, 20);
	else if (value >= 70)
		color = create_trgb(64, 40, value * 2, 20);
	else if (value >= 60)
		color = create_trgb(64, 40, value * 2, 20);
	else if (value >= 50)
		color = create_trgb(64, 40, value * 2, 20);
	else if (value >= 40)
		color = create_trgb(64, 40, value * 2, 20);
	else if (value >= 30)
		color = create_trgb(64, 40, value * 2, 20);
	else if (value >= 10)
		color = create_trgb(64, value, value * 2, 20);
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
