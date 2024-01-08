/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:53:56 by risasada          #+#    #+#             */
/*   Updated: 2023/11/15 15:53:58 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define DESTROY 17
# define ESCAPE 53

# define LEFT_KEY 123
# define RIGHT_KEY 124
# define UP_KEY 126
# define DOWN_KEY 125

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include <mlx.h>
# include <math.h> 

typedef struct s_complex {
	double	real;
	double	i;
}				t_complex;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fractol {
	void		*mlx_ptr;
	void		*mlx_window;
	t_img		img;
	char		*name;
	double		zoom;
	double		shift_y;
	double		shift_x;
	t_complex	julia_c;
}				t_fractol;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	rendering_fractol(t_fractol *f);
void	init_fractol(t_fractol *f);
void	init_hook(t_fractol *f);
void	handle_error(char *msg);

#endif
