/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:15:27 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/03 23:45:25 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <X11/keysym.h>
# include <string.h>
# include "libft.h"
# include "stdbool.h"
# include "mlx.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif


# define WIDTH 800
# define HIGHT 800
# define WINDOW_TITLE "fract-ol --ttakami xD"
# define MANDE "Mandelbrot"
# define JULIA "Julia"
# define TYPE_MANDE 0
# define TYPE_JULIA 1
# define USAGE_L1 "usage: ./fractol <name> <option>"
# define USAGE_L2 "| name | Mandelbrot | Julia |"
# define USAGE_L3 "if you choose Julia, you can add option (int, 0 <= n <= 360)"
# define ERR_MSG "invalid arguments!"
# define DEFAULT_DEG 90
# define IMAX 100
# define LIMIT 4.0
# define WAIT 5000

typedef struct s_complex_number
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol_asset
{
	bool		need_draw;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			fractol_type;
	int			extra_param;
	t_complex	c;
	double		start_x;
	double		start_y;
	double		end_x;
	double		end_y;
	double		dx;
	double		dy;
	int			zoom_level;
}	t_fractol;

void		print_usage(void);
void		puterr_and_exit(char *err_msg);
int			validate_args(int argc, char *argv[], t_fractol *f);
void		init_fractol(t_fractol *f);
int			deinit_fractol(t_fractol *f);
t_complex	cal_complex(int degree);
t_complex	sum_complex(t_complex num1, t_complex num2);
t_complex	mul_complex(t_complex num1, t_complex num2);
double		abs_complex(double square);
void		pixel_put(int value, t_fractol *f, int x, int y);
void		draw_fractol(t_fractol *f);
void		set_mlx_hooks(t_fractol *f);
void		zoom_in(t_fractol *f);
void		zoom_out(t_fractol *f);
int			expose_hook(t_fractol *f);
int			key_hook(int keycode, t_fractol *f);
int			mouse_hook(int mousecode, int x, int y, t_fractol *f);
int			loop_hook(t_fractol *f);

#endif
