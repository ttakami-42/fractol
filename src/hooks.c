/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:17:02 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/01 02:57:19 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	expose_hook(t_fractol *f)
{
	f->need_draw = true;
	return (0);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		deinit_fractol(f);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	if (mousecode == 4)
		zoom_in(f);
	else if (mousecode == 5)
		zoom_out(f);
	expose_hook(f);
	return (0);
}

int	loop_hook(t_fractol *f)
{	
	static int	count = 0;
	static bool	is_drawing = false;

	count++;
	if (count % 1000 != 0)
		return (0);
	if (!f->need_draw)
		return (0);
	if (is_drawing)
		return (0);
	is_drawing = true;
	if (f->fractol_type == TYPE_MANDE)
		draw_mandelbrot(f);
	else if (f->fractol_type == TYPE_JULIA)
		draw_julia(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	f->need_draw = false;
	is_drawing = false;
	return (0);
}
