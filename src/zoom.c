/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:33:04 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/11 12:20:00 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractol *f)
{
	double	scale;

	if (f->zoom_level == 10000)
		return ;
	f->zoom_level++;
	if (f->zoom_level == 0)
		scale = 1.0;
	else
		scale = pow(0.95, f->zoom_level);
	f->start_x = scale * -2.0;
	f->start_y = scale * 2.0;
	f->end_x = scale * 2.0;
	f->end_y = scale * -2.0;
}

void	zoom_out(t_fractol *f)
{
	double	scale;

	if (f->zoom_level == -100)
		return ;
	f->zoom_level--;
	if (f->zoom_level == 0)
		scale = 1.0;
	else
		scale = pow(0.95, f->zoom_level);
	f->start_x = scale * -2.0;
	f->start_y = scale * 2.0;
	f->end_x = scale * 2.0;
	f->end_y = scale * -2.0;
}