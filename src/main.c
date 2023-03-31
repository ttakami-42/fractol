/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:14:34 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 14:23:13 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	f;

	if (argc < 2)
	{
		print_usage();
		return (1);
	}
	if (!validate_args(argc, argv, &f))
	{
		puterr_and_exit(ERR_MSG);
		print_usage();
	}
	init_fractol(&f);
	set_mlx_hooks(&f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
