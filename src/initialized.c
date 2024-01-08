/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialized.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:57:42 by risasada          #+#    #+#             */
/*   Updated: 2023/11/15 15:57:43 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "includes/ft_printf.h"
#include "libft/libft.h"

void	handle_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	init_fractol(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	if (f->mlx_ptr == NULL)
		handle_error("mlx_initialization failed ...");
	f->mlx_window = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "test");
	if (f->mlx_window == NULL)
		handle_error("Failed to create a new window");
	f->img.img = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	if (f->img.img == NULL)
		handle_error("Failed to create a new image");
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	init_hook(f);
}
