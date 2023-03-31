/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:56:29 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 14:21:12 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mlx_hooks(t_fractol *f)
{
	mlx_hook(f->win_ptr, 17, 1L << 2, deinit_fractol, f);
	mlx_expose_hook(f->win_ptr, expose_hook, f);
	mlx_key_hook(f->win_ptr, key_hook, f);
	mlx_mouse_hook(f->win_ptr, mouse_hook, f);
}
