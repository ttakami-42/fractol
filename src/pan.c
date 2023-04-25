/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:01:46 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/26 02:30:04 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pan_up(t_fractol *f)
{
	if (f->need_draw)
		return ;
	f->need_draw = true;
	f->centre_y += 0.02;
	f->start_y += 0.02;
	f->end_y += 0.02;
}

void	pan_down(t_fractol *f)
{
	if (f->need_draw)
		return ;
	f->need_draw = true;
	f->centre_y -= 0.02;
	f->start_y -= 0.02;
	f->end_y -= 0.02;
}

void	pan_left(t_fractol *f)
{
	if (f->need_draw)
		return ;
	f->need_draw = true;
	f->centre_x -= 0.02;
	f->start_x -= 0.02;
	f->end_x -= 0.02;
}

void	pan_right(t_fractol *f)
{
	if (f->need_draw)
		return ;
	f->need_draw = true;
	f->centre_x += 0.02;
	f->start_x += 0.02;
	f->end_x += 0.02;
}