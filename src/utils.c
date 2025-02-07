#include "../fract.h"

void	new_julia(double *cx)
{
	static double	i;

	i = 0.1;
	if (i < M_PI && (*cx < 3 && *cx > -1.5))
	{
		i += 0.02;
		*cx += i;
	}
	else
	{
		i = 0.1;
		*cx += i;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = -1;
		while (s[++i])
			write(fd, &s[i], 1);
		write(fd, "\n", 1);
	}
}

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	return (0);
}

void	change_iterations(t_fractal *fractal, int keycode)
{
	if (keycode == D)
	{
		if (fractal->max_iterations > 0)
			fractal->max_iterations -= 42;
	}
	else if (keycode == I)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}
