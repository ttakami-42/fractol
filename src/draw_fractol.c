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

static int	create_tone_value(t_complex z, t_complex c);

void	draw_fractol(t_fractol *f)
{
	int			x;
	int			y;
	t_complex	z;
	int			tone_value;

	tone_value = 0;
	f->dx = (f->end_x - f->start_x) / (WIDTH);
	f->dy = (f->end_y - f->start_y) / (HIGHT);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HIGHT)
		{
			z.real = f->start_x + x * f->dx;
			z.imag = f->start_y + y * f->dy;
			if (f->fractol_type == TYPE_MANDE)
				tone_value = create_tone_value(f->c, z);
			else if (f->fractol_type == TYPE_JULIA)
				tone_value = create_tone_value(z, f->c);
			pixel_put(tone_value, f, x, y);
			y++;
		}
		x++;
	}
}

static int	create_tone_value(t_complex z, t_complex c)
{
	int	i;

	i = 0;
	while (i < IMAX)
	{
		z = sum_complex(mul_complex(z, z), c);
		if (abs_complex(z) > LIMIT)
			return (i);
		i++;
	}
	return (IMAX);
}
