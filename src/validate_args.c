/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:13:43 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/01 02:10:30 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	validate_args(int argc, char *argv[], t_fractol *f)
{
	if (argc == 2 && ft_strncmp(argv[1], MANDE, 9) == 0)
	{
		f->fractol_type = TYPE_MANDE;
		return (1);
	}
	if (argc <= 3 && ft_strncmp(argv[1], JULIA, 5) == 0)
	{
		f->fractol_type = TYPE_JULIA;
		if (argc == 2)
		{
			f->args.real = COMPLEX_R;
			f->args.imag = COMPLEX_I;
		}
		if (argc == 3)
			f->args = cal_complex(ft_atoi(argv[2]));
		return (1);
	}
	return (0);
}
