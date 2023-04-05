/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 03:07:14 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/06 03:09:58 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		create_rgb(double h, double s, double l);
static double	create_lightness(int value);
static void		my_mlx_pixel_put(t_fractol *f, int x, int y, int color);

void	pixel_put(int value, t_fractol *f, int x, int y)
{
	int		color;
	double	hue;
	double	saturation;
	double	lightness;

	/*
	hue = create_hue(value);
	saturation = create_saturation(value);
	*/
	hue = 0.0;
	saturation = 1.0;
	lightness = create_lightness(value);
	color = create_rgb(hue, saturation, lightness);
	my_mlx_pixel_put(f, x, y, color);
}

static double	create_lightness(int value)
{
	double	div;

	div = IMAX / 2;
	if (value <= IMAX / 2)
		return ((double)(value / div));
	else
		return ((double)((IMAX - value) / div));
	//hue = 240 - (hue - 120) * l;
	//hue = 120 + (hue - 120) * l;
}

static int	create_rgb(double h, double s, double l)
{
	double	c;
	double	x;
	double	m;

	c = (1.0 - fabs(2.0 * l - 1.0)) * s;
	x = c * (1.0 - fabs(fmod(h / 60.0, 2.0) - 1.0));
	m = l - c / 2.0;
	if (h >= 0.0 && h < 60.0)
		return ((int)round((c + m) * 255.0) << 16 | (int)round((x + m) * 255.0) << 8 | (int)round(m * 255.0));
	else if (h >= 60.0 && h < 120.0)
		return ((int)round((x + m) * 255.0) << 16 | (int)round((c + m) * 255.0) << 8 | (int)round(m * 255.0));
	else if (h >= 120.0 && h < 180.0)
		return ((int)round(m * 255.0) << 16 | (int)round((c + m) * 255.0) << 8 | (int)round((x + m) * 255.0));
	else if (h >= 180.0 && h < 240.0)
		return ((int)round(m * 255.0) << 16 | (int)round((x + m) * 255.0) << 8 | (int)round((c + m) * 255.0));
	else if (h >= 240.0 && h < 300.0)
		return ((int)round((x + m) * 255.0) << 16 | (int)round(m * 255.0) << 8 | (int)round((c + m) * 255.0));
	else
		return ((int)round((c + m) * 255.0) << 16 | (int)round(m * 255.0) << 8 | (int)round((x + m) * 255.0));
}

static void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->data_addr + (y * f->size_line + x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
