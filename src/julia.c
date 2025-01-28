#include "../fract.h"

// real = a^2 - b^2 - 0.79
// complex = 2abi + 0.15

void	calculate_julia(t_fractal *fractal, double cx, double cy)
{
	size_t	i;
	double	x_temp;

	fractal->cx = cx;
	fractal->cy = cy;
	i = 0;
	fractal->zx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->zy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy
			* fractal->zy + fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
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
