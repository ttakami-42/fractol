/* ************************************************************************** */
/*			*/
/*		:::	  ::::::::   */
/*   pixel_put.c		:+:	  :+:	:+:   */
/*			+:+ +:+		 +:+	 */
/*   By: ttakami <ttakami@student.42tokyo.jp>	   +#+  +:+	   +#+		*/
/*		+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/31 01:27:13 by ttakami		   #+#	#+#			 */
/*   Updated: 2023/03/31 16:55:21 by ttakami		  ###   ########.fr	   */
/*			*/
/* ************************************************************************** */

#include "fractol.h"

static int	create_color(int value);
static void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color);

void	pixel_put(int value, t_fractol *f, int x, int y)
{
	int		color;

	color = create_color(value);
	my_mlx_pixel_put(f, x, y, color);
}

static int create_color(int value)
{
	int hue = 0;
	double s = 1.0;
	double l;
	double val = value * 2.550;
	if (val <= 128.0) {
		l = val / 128.0;
		//hue = 240 - (hue - 120) * l;
	} else {
		l = (255.0 - val) / 127.0;
		//hue = 120 + (hue - 120) * l;
	}
	double c = (1 - fabs(2 * l - 1)) * s;
	double x = c * (1 - fabs(fmod(hue / 60, 2) - 1));
	double m = l - c / 2;
	double r1, g1, b1;
	if (hue >= 0 && hue < 60) {
		r1 = c;
		g1 = x;
		b1 = 0;
	} else if (hue >= 60 && hue < 120) {
		r1 = x;
		g1 = c;
		b1 = 0;
	} else if (hue >= 120 && hue < 180) {
		r1 = 0;
		g1 = c;
		b1 = x;
	} else if (hue >= 180 && hue < 240) {
		r1 = 0;
		g1 = x;
		b1 = c;
	} else if (hue >= 240 && hue < 300) {
		r1 = x;
		g1 = 0;
		b1 = c;
	} else {
		r1 = c;
		g1 = 0;
		b1 = x;
	}
	int r = round((r1 + m) * 255);
	int g = round((g1 + m) * 255);
	int b = round((b1 + m) * 255);
	return (r << 16 | g << 8 | b);
}

static void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->data_addr + (y * f->size_line + x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
