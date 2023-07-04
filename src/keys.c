#include "../fract.h"
#include <stdio.h>
void free_exit(t_fractal *fractal)
{
	free(fractal);
	exit(EXIT_SUCCESS);
}

void key_hook(int keycode, t_fractal *fractal)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		free_exit(fractal);
	if (keycode == UP)
		fractal->offset_y += 0.2;
	if (keycode == DOWN)
		fractal->offset_y -= 0.2;
	if (keycode == RIGHT)
		fractal->offset_x += 0.2;
	if (keycode == LEFT)
		fractal->offset_x -= 0.2;
	// if (keycode == SCROLL_DOWN)
	// 	fractal->zoom += 50;
	draw_fractal(fractal, fractal->name, 0, 0);
}

void mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
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
	draw_fractal(fractal, fractal->name, 0, 0);
}