#include "../fract.h"

typedef struct s_float2{
	double	x;
	double	y;
}	t_float2;

static t_float2	next(t_float2 z)
{
	t_float2	new;
	double		temp_deno;

	temp_deno = 3 * (z.x * z.x + z.y * z.y) * (z.x * z.x + z.y * z.y);
	new.x = ((z.x * z.x * z.x * z.x * z.x + 2 * z.x * z.x * z.x * z.y * z.y
				- z.x * z.x + z.x * z.y * z.y * z.y * z.y + z.y * z.y)
			/ temp_deno);
	new.y = ((z.y * (z.x * z.x * z.x * z.x + 2 * z.x * z.x
					* z.y * z.y + 2 * z.x + z.y * z.y * z.y * z.y))
			/ temp_deno);
	z.x -= new.x;
	z.y -= new.y;
	return (z);
}

static t_float2	find_diff(t_float2 z, t_float2 root)
{
	t_float2	new;

	new.x = z.x - root.x;
	new.y = z.y - root.y;
	return (new);
}

void	init_roots(t_float2 *roots)
{
	static unsigned int	flag;

	if (!flag)
	{
		roots[0] = (t_float2){1, 0};
		roots[1] = (t_float2){-0.5, 0.866025403784438};
		roots[2] = (t_float2){-0.5, -0.866025403784438};
		flag = 1;
	}
}

static unsigned int	checker_tolerance(t_fractal *fractal, t_float2 z)
{
	t_float2		difference;
	static t_float2	roots[3];

	init_roots(roots);
	difference = find_diff(z, roots[0]);
	if (fabs(difference.x) < fractal->tolerance
		&& fabs(difference.y) < fractal->tolerance)
		return (1);
	difference = find_diff(z, roots[1]);
	if (fabs(difference.x) < fractal->tolerance
		&& fabs(difference.y) < fractal->tolerance)
		return (1);
	difference = find_diff(z, roots[2]);
	if (fabs(difference.x) < fractal->tolerance
		&& fabs(difference.y) < fractal->tolerance)
		return (1);
	return (0);
}

void	calculate_newton(t_fractal *fractal)
{
	t_float2		z;
	size_t			iterations;

	iterations = 0;
	z.x = (fractal->x / fractal->zoom) + fractal->offset_x;
	z.y = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (iterations < fractal->max_iterations)
	{
		z = next(z);
		if (checker_tolerance(fractal, z) == 1)
			return (put_color_to_pixel(fractal, fractal->x, fractal->y,
					fractal->color * iterations / 2));
		++iterations;
	}
	put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
}
