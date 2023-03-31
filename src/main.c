/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:14:34 by ttakami           #+#    #+#             */
/*   Updated: 2023/03/31 15:56:37 by ttakami          ###   ########.fr       */
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
		print_usage();
		ft_putendl_fd(NULL, STDERR_FILENO);
		puterr_and_exit(ERR_MSG);
	}
	init_fractol(&f);
	set_mlx_hooks(&f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
