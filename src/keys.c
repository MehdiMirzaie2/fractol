/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:31:34 by mmirzaie          #+#    #+#             */
/*   Updated: 2024/04/02 15:19:19 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	double	cx;
	double	cy;

	cx = fractal->cx;
	cy = fractal->cy;
	if (keycode == ESC)
	{
		exit_fractal(fractal);
		exit(0);
	}
	if (keycode == UP)
		fractal->offset_y += 0.2;
	else if (keycode == DOWN)
		fractal->offset_y -= 0.2;
	else if (keycode == RIGHT)
		fractal->offset_x += 0.2;
	else if (keycode == LEFT)
		fractal->offset_x -= 0.2;
	else if (keycode == C)
		fractal->color = (fractal->color * 2) / 5;
	else if (keycode == J)
		new_julia(&cx);
	else if (keycode == I || keycode == D)
		change_iterations(fractal, keycode);
	draw_fractal(fractal, cx, cy);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (mousecode == SCROLL_DOWN)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (mousecode == SCROLL_UP)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	draw_fractal(fractal, fractal->cx, fractal->cy);
	return (0);
}
