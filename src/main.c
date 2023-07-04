/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:55:04 by lgaudin           #+#    #+#             */
/*   Updated: 2023/07/04 20:13:52 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"
#include <string.h>

int	draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			if (strncmp(query, "mandel", 7) == 0)
				calculate_mandelbrot(fractal);
			else if (strncmp(query, "julia", 6) == 0)
				calculate_julia(fractal, cx, cy);
			else if (strncmp(query, "newton", 6) == 0)
				// calculate_burning_ship(fractal);
				calculate_newton(fractal);
				// newtonFractal(fractal);
			else
			{
				// ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
				exit_fractal(fractal);
			}
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
	{
		// ft_putendl_fd("Usage: ./fractol <fractal>", 1);
		// ft_putendl_fd("Available fractals: mandelbrot, julia, burningship", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	// mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1], -0.745429, 0.05);
	mlx_loop(fractal->mlx);
	return (0);
}
