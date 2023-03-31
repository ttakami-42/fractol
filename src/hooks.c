/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:17:02 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 12:41:14 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in(t_fractol *f);
static void	zoom_out(t_fractol *f);

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		deinit_fractol(f);
	return (0);
}

int	expose_hook(t_fractol *f)
{
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	UNUSED(x);
	UNUSED(y);
	if (mousecode == 4)
		zoom_in(f);
	else if (mousecode == 5)
		zoom_out(f);
	return (0);
}

static void	zoom_in(t_fractol *f)
{
	f->start_x += 0.10;
	f->start_y -= 0.10;
	f->end_x -= 0.10;
	f->end_y += 0.10;
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HIGHT);
	f->data_addr = mlx_get_data_addr(f->img_ptr, &f->bits_per_pixel, \
	&f->size_line, &f->endian);
	if (f->fractol_type == TYPE_MANDE)
		draw_mandelbrot(f);
	else if (f->fractol_type == TYPE_JULIA)
		draw_julia(f);
}

static void	zoom_out(t_fractol *f)
{
	f->start_x -= 0.10;
	f->start_y += 0.10;
	f->end_x += 0.10;
	f->end_y -= 0.10;
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HIGHT);
	f->data_addr = mlx_get_data_addr(f->img_ptr, &f->bits_per_pixel, \
	&f->size_line, &f->endian);
	if (f->fractol_type == TYPE_MANDE)
		draw_mandelbrot(f);
	else if (f->fractol_type == TYPE_JULIA)
		draw_julia(f);
}
