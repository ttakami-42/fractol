/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:15:27 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 12:48:25 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <X11/keysym.h>
# include <string.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 600
# define HIGHT 600
# define WINDOW_TITLE "fract-ol --ttakami xD"
# define MANDE "Mandelbrot"
# define JULIA "Julia"
# define TYPE_MANDE 0
# define TYPE_JULIA 1
# define USAGE_LINE1 "usage: ./fractol <name> | Mandelbrot | Julia |"
# define USAGE_LINE2 "if you want to create other julia set..."
# define USAGE_LINE3 "change COMPLEX_R and COMPLEX_I value in fractol.h, just compile it!"
# define ERR_MSG "invalid arguments."
# define UNUSED(x) ((void)x)
# define COMPLEX_R -0.3
# define COMPLEX_I -0.63
# define IMAX 400
# define CONVERGENCE 4.0

typedef struct	s_complex_number
{
	double	real;
	double	imag;
}	t_complex;

typedef struct	s_fractol_asset
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractol_type;
	t_complex	args;
	double		start_x;
	double		start_y;
	double		end_x;
	double		end_y;
	double		dx;
	double		dy;
	void		*img_ptr;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}	t_fractol;

void		print_usage(void);
void		puterr_and_exit(char *err_msg);
int			validate_args(int argc, char *argv[], t_fractol *f);
void		init_fractol(t_fractol *f);
int			deinit_fractol(t_fractol *f);
t_complex	sum_complex(t_complex num1, t_complex num2);
t_complex	mul_complex(t_complex num1, t_complex num2);
double		abs_complex(t_complex num);
void		pixel_put(int value, t_fractol *f, int x, int y);
void		draw_mandelbrot(t_fractol *f);
void		draw_julia(t_fractol *f);
void		set_mlx_hooks(t_fractol *f);
int			key_hook(int keycode, t_fractol *f);
int			expose_hook(t_fractol *f);
int			mouse_hook(int mousecode, int x, int y, t_fractol *f);

#endif
