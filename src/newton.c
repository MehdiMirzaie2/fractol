#include "../fract.h"

typedef struct {
    float x;
    float y;
} float2;

float2 next(float2 z)
{
	float2 new;
	float temp_deno;

	temp_deno = 3*pow((pow(z.x, 2) + pow(z.y, 2)), 2);
	new.x = (pow(z.x, 5) + 2*pow(z.x, 3)*pow(z.y, 2) - pow(z.x, 2) + z.x*pow(z.y, 4) + pow(z.y, 2)) / temp_deno;
	new.y = (z.y*(pow(z.x, 4) + 2*pow(z.x, 2)*pow(z.y, 2) + 2*z.x + pow(z.y, 4))) / temp_deno;
	return (new);
}

float2 find_diff(float2 z, float2 root)
{
	float2 new;

	new.x = z.x - root.x;
	new.y = z.y - root.y;
	return (new);
}

void calculate_newton(t_fractal *fractal)
{
	float2 z;
	float2 _next;
	float tolerance = 0.000001;
	int iterations = 0;
	int colors[3] = {0xFF0000, 0x00FF00, 0x0000FF};
	float2 roots[3] = {(float2){1, 0}, (float2){-0.5, sqrt(3)/2}, (float2){-0.5, -sqrt(3)/2}};

	z.x = (fractal->x / fractal->zoom) + fractal->offset_x;
	z.y = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (iterations < fractal->max_iterations)
	{
		_next = next(z);
		z.x -= _next.x;
		z.y -= _next.y;

		for (int i = 0; i < 3; i++)
		{
			float2 difference = find_diff(z, roots[i]);
			if (fabs(difference.x) < tolerance && fabs(difference.y) < tolerance)
			{
				// put_color_to_pixel(fractal, fractal->x, fractal->y, colors[i]);
				put_color_to_pixel(fractal, fractal->x, fractal->y, fractal->color * iterations/2);
				return ;
			}
		}
		iterations++;
	}
	put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
}


// float2 next(float2 z)
// {
// 	float2 new;
// 	// float tempx;
// 	float temp_deno;

// 	temp_deno = 3*pow((pow(z.x, 2) + pow(z.y, 2)), 2);
// 	new.x = (pow(z.x, 5) + 2*pow(z.x, 3)*pow(z.y, 2) - pow(z.x, 2) + z.x*pow(z.y, 4) + pow(z.y, 2)) / temp_deno;
// 	new.y = (z.y*(pow(z.x, 4) + 2*pow(z.x, 2)*pow(z.y, 2) + 2*z.x + pow(z.y, 4))) / temp_deno;
// 	// tempx = 3*pow(z.x, 5) + 5*pow(z.x,3)*pow(z.y, 2) + 3*z.x*pow(z.y, 4) - 3*pow(z.x, 2) + 4*pow(z.y, 2);
// 	// new.y = 3*pow(z.x, 4)*z.y + 5*pow(z.x, 2)*pow(z.y, 3) + 6*z.x*z.y + 3*pow(z.y, 5);
// 	// new.x = tempx / (9*pow(z.x, 4) + 54*pow(z.x, 2)*pow(z.y, 2) + 9*pow(z.y, 4));

// 	return (new);
// }

// typedef struct {
//     double x;
//     double y;
// } float2;

// float2 function(float2 z)
// {
// 	float2 new;
// 	new.x = (z.x*z.x*z.x - 3*(z.x*(z.y*z.y))) - 1.0;
// 	new.y = 3*(z.x*z.x*z.y) - (z.y*z.y*z.y);
// 	return (new);
// }

// float2 derivative(float2 z)
// {
// 	float2 new;

// 	new.x = 3*(z.x*z.x - z.y*z.y);
// 	new.y = 6*(z.x*z.y);
// 	return (new);
// }

// float2 find_diff(float2 z, float2 root)
// {
// 	float2 new;

// 	new.x = z.x - root.x;
// 	new.y = z.y - root.y;
// 	return (new);
// }

// void calculate_newton(t_fractal *fractal)
// {
// 	float2 z;
// 	float2 func;
// 	float2 deriv;
// 	long double tolerance = 0.0000001;
// 	int iterations = 0;
// 	int colors[3] = {0xFF0000, 0x00FF00, 0x0000FF};
// 	float2 roots[3] = {(float2){1, 0}, (float2){-0.5, sqrt(3)/2}, (float2){-0.5, -sqrt(3)/2}};

// 	z.x = (fractal->x / fractal->zoom) + fractal->offset_x;
// 	z.y = (fractal->y / fractal->zoom) + fractal->offset_y;
// 	while (iterations < fractal->max_iterations)
// 	{
// 		func = function(z);
// 		deriv = derivative(z);
// 		z.x -= func.x / deriv.x;
// 		z.y -= func.y / deriv.y;

// 		for (int i = 0; i < 3; i++)
// 		{
// 			float2 difference = find_diff(z, roots[i]);
// 			if (abs(difference.x) < tolerance && abs(difference.y) < tolerance)
// 			{
// 				put_color_to_pixel(fractal, fractal->x, fractal->y, colors[i]);
// 				return ;
// 			}
// 		}
// 		++iterations;
// 	}
// 	put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
// }
