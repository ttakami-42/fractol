/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:07:26 by ttakami           #+#    #+#             */
/*   Updated: 2023/04/03 04:02:18 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putendl_fd(USAGE_L1, STDOUT_FILENO);
	ft_putendl_fd(NULL, STDERR_FILENO);
	ft_putendl_fd(USAGE_L2, STDOUT_FILENO);
	ft_putstr_fd("\x1b[31m", STDOUT_FILENO);
	ft_putendl_fd(USAGE_L3, STDOUT_FILENO);
	ft_putstr_fd("\x1b[39m", STDOUT_FILENO);
	ft_putendl_fd(NULL, STDERR_FILENO);
}

void	puterr_and_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
