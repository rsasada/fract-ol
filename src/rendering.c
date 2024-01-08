/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:42:21 by risasada          #+#    #+#             */
/*   Updated: 2023/11/15 16:42:23 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "includes/ft_printf.h"
#include "libft/libft.h"

void	render_pixel(int x, int y, t_fractol *f);
double	scale(int num, double old_max, double new_min, double new_max);
void	check_julia(t_complex *z, t_complex *c, t_fractol *f);

void	rendering_fractol(t_fractol *f)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			render_pixel(x, y, f);
			y ++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->mlx_window, f->img.img, 0, 0);
}

void	render_pixel(int x, int y, t_fractol *f)
{
	int			i;
	double		tmp_real;
	t_complex	c;
	t_complex	z;
	int			color;

	c.real = (scale(x, WIDTH, -3, 3) * f->zoom) + f->shift_x;
	c.i = (scale(y, HEIGHT, 3, -3) * f->zoom) + f->shift_y;
	i = 0;
	z.real = 0;
	z.i = 0;
	check_julia(&z, &c, f);
	while (i ++ < 75)
	{
		tmp_real = z.real * z.real - z.i * z.i + c.real;
		z.i = 2 * z.real * z.i + c.i;
		z.real = tmp_real;
		if (z.i * z.i + z.real * z.real > 4)
		{
			color = scale(i, 50, 0xffffff, 0xfffaf0);
			my_mlx_pixel_put(&f->img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&f->img, x, y, 0xfffaf0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

double	scale(int num, double old_max, double new_min, double new_max)
{
	double	old_range;
	double	new_range;

	old_range = old_max - 0;
	new_range = new_max - new_min;
	return ((num / old_range) * new_range + new_min);
}

void	check_julia(t_complex *z, t_complex *c, t_fractol *f)
{
	if (!ft_strncmp(f->name, "Julia", sizeof("Julia")))
	{
		z->real = c->real;
		z->i = c->i;
		*c = f->julia_c;
	}
}
