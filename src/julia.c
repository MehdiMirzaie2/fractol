// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:27:23 by lgaudin           #+#    #+#             */
/*   Updated: 2023/07/03 13:58:16 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

// real = a^2 - b^2 - 0.79
// complex = 2abi + 0.15

void	calculate_julia(t_fractal *fractal, double cx, double cy)
{
	int		i;
	double	x_temp;

	fractal->name = "julia";
	i = 0;
	fractal->offset_x = -1.5;
	fractal->zoom = 230;
	fractal->zx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->zy = (fractal->y / fractal->zoom) + fractal->offset_y;;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy - 0.79;
		fractal->zy = 2. * fractal->zx * fractal->zy + 0.15;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
				* i));
}
