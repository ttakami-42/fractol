/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:07:26 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 06:09:51 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	print_usage(void)
{
	ft_putendl_fd(USAGE_LINE1, STDOUT_FILENO);
	ft_putendl_fd(NULL, STDERR_FILENO);
	ft_putstr_fd("\x1b[31m", STDOUT_FILENO);
	ft_putendl_fd(USAGE_LINE2, STDOUT_FILENO);
	ft_putendl_fd(USAGE_LINE3, STDOUT_FILENO);
	ft_putstr_fd("\x1b[39m", STDOUT_FILENO);
}

void	puterr_and_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
