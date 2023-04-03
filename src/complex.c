/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:15:41 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/03 03:30:23 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	cal_complex(int degree)
{
	t_complex	num;
	double 		rad;

	if (degree == -1)
	{
		num.real = 0.0;
		num.imag = 0.0;
	}
	else
	{
		rad = degree * M_PI / 180;
		num.real = sin(rad);
		num.imag = cos(rad);
	}
	return (num);
}

t_complex	sum_complex(t_complex num1, t_complex num2)
{
	t_complex	sum;

	sum.real = num1.real + num2.real;
	sum.imag = num1.imag + num2.imag;
	return (sum);
}

t_complex	mul_complex(t_complex num1, t_complex num2)
{
	t_complex	mul;

	mul.real = (num1.real * num2.real) - (num1.imag * num2.imag);
	mul.imag = (num1.real * num2.imag) + (num2.real * num1.imag);
	return (mul);
}

double	abs_complex(t_complex num)
{
	return (sqrt((num.real * num.real) + (num.imag * num.imag)));
}
