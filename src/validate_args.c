/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:13:43 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/03 03:29:36 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	validate_args(int argc, char *argv[], t_fractol *f)
{
	if (argc == 2 && ft_strncmp(argv[1], MANDE, 9) == 0)
	{
		f->fractol_type = TYPE_MANDE;
		f->extra_param = -1;
		return (1);
	}
	if (argc <= 3 && ft_strncmp(argv[1], JULIA, 5) == 0)
	{
		f->fractol_type = TYPE_JULIA;
		if (argc == 3)
		{
			f->extra_param = ft_atoi(argv[2]);
			if (0 > f->extra_param || f->extra_param > 360)
				return (0);
		}
		else
			f->extra_param = DEFAULT_DEG;
		return (1);
	}
	return (0);
}
