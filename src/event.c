/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:51:00 by risasada          #+#    #+#             */
/*   Updated: 2023/11/20 18:29:08 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

int	key_event(int key, t_fractol *f);
int	mouse_event(int button, int x, int y, t_fractol *f);
int	destroy_window(int button, t_fractol *f);

void	init_hook(t_fractol *f)
{
	f->shift_x = 0;
	f->shift_y = 0;
	f->zoom = 1;
	mlx_key_hook(f->mlx_window, &key_event, f);
	mlx_mouse_hook(f->mlx_window, &mouse_event, f);
	mlx_hook(f->mlx_window, 17, 0, &destroy_window, f);
}

int	key_event(int key, t_fractol *f)
{
	if (key == LEFT_KEY)
		f->shift_x -= 0.5 * f->zoom;
	else if (key == RIGHT_KEY)
		f->shift_x += 0.5 * f->zoom;
	else if (key == UP_KEY)
		f->shift_y += 0.5 * f->zoom;
	else if (key == DOWN_KEY)
		f->shift_y -= 0.5 * f->zoom;
	else if (key == ESCAPE)
	{
		mlx_destroy_window(f->mlx_ptr, f->mlx_window);
		free(f->mlx_ptr);
		exit (0);
	}
	rendering_fractol(f);
	return (0);
}

int	mouse_event(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == ON_MOUSEDOWN)
		f->zoom *= 1.1;
	else if (button == ON_MOUSEUP)
		f->zoom *= 0.9;
	rendering_fractol(f);
	return (0);
}

int	destroy_window(int button, t_fractol *f)
{
	(void)button;
	(void)f;
	exit(EXIT_SUCCESS);
}
