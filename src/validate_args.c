/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:13:43 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 04:03:11 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	validate_args(int argc, char *argv[], t_fractol *f)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], MANDE, 9) == 0)
		{
			f->fractol_type = TYPE_MANDE;
			return (1);
		}
		if (ft_strncmp(argv[1], JULIA, 5) == 0)
		{
			f->fractol_type = TYPE_JULIA;
			f->args.real = COMPLEX_R;
			f->args.imag = COMPLEX_I;
			return (1);
		}
	}
	return (0);
}
