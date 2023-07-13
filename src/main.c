/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirzaie <mmirzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:31:42 by mmirzaie          #+#    #+#             */
/*   Updated: 2023/07/07 13:43:22 by mmirzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"
#include <string.h>

// if they want to see more.
// else if (strncmp(query, "ship", 4) == 0)
// 	calculate_burning_ship(fractal);
// else if (strncmp(query, "tri", 3) == 0)
// 	calculate_burning_ship(fractal);

static void	free_and_explain(t_fractal *fractal)
{
	ft_putendl_fd("Available fractals: a = mandel, b = julia, c = newton\
	\n\033[1;31mASK FOR EXTRA!\033[0m", 1);
	exit_fractal(fractal);
}

int	draw_fractal(t_fractal *fractal, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			if (fractal->name == 'a')
				calculate_mandelbrot(fractal);
			else if (fractal->name == 'b')
				calculate_julia(fractal, cx, cy);
			else if (fractal->name == 'c')
				calculate_newton(fractal);
			else
				free_and_explain(fractal);
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

	if (argc != 2 || argv[1][1] != NULL)
	{
		ft_putendl_fd("Available fractals: a = mandel, b = julia, c = newton\
		\n\033[1;31mASK FOR EXTRA!\033[0m", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	fractal->name = argv[1][0];
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, -0.79, 0.15);
	mlx_loop(fractal->mlx);
	return (0);
}
