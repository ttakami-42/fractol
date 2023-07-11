/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:17:02 by ttakami           #+#    #+#             */
/*   Updated: 2023/07/11 14:03:59 by ttakami          ###   ########.fr       */
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
	else if (keycode == XK_w || keycode == XK_W)
		pan_up(f);
	else if (keycode == XK_a || keycode == XK_A)
		pan_left(f);
	else if (keycode == XK_d || keycode == XK_D)
		pan_right(f);
	else if (keycode == XK_s || keycode == XK_S)
		pan_down(f);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	f->need_draw = true;
	if (mousecode == 4)
		zoom_in(f);
	if (mousecode == 5)
		zoom_out(f);
	return (0);
}

int	loop_hook(t_fractol *f)
{	
	static int	count = 1;
	static bool	is_drawing = false;

	count++;
	if (count % WAIT != 0)
		return (0);
	if (!f->need_draw)
		return (0);
	if (is_drawing)
		return (0);
	is_drawing = true;
	draw_fractol(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	f->need_draw = false;
	is_drawing = false;
	count = 1;
	return (0);
}
