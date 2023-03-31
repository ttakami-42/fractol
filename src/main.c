/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:14:34 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/01 00:51:09 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	f;

	if (argc < 2)
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	if (!validate_args(argc, argv, &f))
	{
		print_usage();
		puterr_and_exit(ERR_MSG);
	}
	init_fractol(&f);
	set_mlx_hooks(&f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
