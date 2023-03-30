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

static int	mandelbrot(t_complex c, int max);
static int	julia(t_complex z, t_complex c, int max);

void	draw_mandelbrot(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	complex_num;
	int			value;

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
			value = mandelbrot(complex_num, 100);
			pixel_put(value, f, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

void	draw_julia(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	complex_num;
	int			value;

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
			value = julia(complex_num, f->args, 100);
			pixel_put(value, f, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

static int	mandelbrot(t_complex c, int max)
{
	t_complex	z;
	int			i;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < max)
	{
		z = sum_complex(mul_complex(z, z), c);
		if (abs_complex(z) > 4.0)
			return (i);
		i++;
	}
	return (max);
}

static int	julia(t_complex z, t_complex c, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		z = sum_complex(mul_complex(z, z), c);
		if (abs_complex(z) > 4.0)
			return (i);
		i++;
	}
	return (max);
}