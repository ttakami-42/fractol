/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:35 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/30 02:37:37 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(t_complex c, int imax);
static int	julia(t_complex z, t_complex c, int imax);

void	draw_mandelbrot(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	complex_num;
	int			tone_value;

	f->dx = (f->end_x - f->start_x) / (WIDTH);
	f->dy = (f->end_y - f->start_y) / (HIGHT);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HIGHT)
		{
			complex_num.real = f->start_x + x * f->dx;
			complex_num.imag = f->start_y + y * f->dy;
			tone_value = mandelbrot(complex_num, IMAX);
			if (tone_value > 255)
				tone_value = 255;
			pixel_put(tone_value, f, x, y);
			y++;
		}
		x++;
	}
}

void	draw_julia(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	complex_num;
	int			tone_value;

	f->dx = (f->end_x - f->start_x) / (WIDTH);
	f->dy = (f->end_y - f->start_y) / (HIGHT);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HIGHT)
		{
			complex_num.real = f->start_x + x * f->dx;
			complex_num.imag = f->start_y + y * f->dy;
			tone_value = julia(complex_num, f->args, IMAX);
			if (tone_value > 255)
				tone_value = 255;
			pixel_put(tone_value, f, x, y);
			y++;
		}
		x++;
	}
}

static int	mandelbrot(t_complex c, int imax)
{
	t_complex	z;
	int			i;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < imax)
	{
		z = sum_complex(mul_complex(z, z), c);
		if (abs_complex(z) > LIMIT)
			return (i);
		i++;
	}
	return (imax);
}

static int	julia(t_complex z, t_complex c, int imax)
{
	int	i;

	i = 0;
	while (i < imax)
	{
		z = sum_complex(mul_complex(z, z), c);
		if (abs_complex(z) > LIMIT)
			return (i);
		i++;
	}
	return (imax);
}
