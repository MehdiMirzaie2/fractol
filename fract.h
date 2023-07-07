/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirzaie <mmirzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:17:56 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/07/07 12:47:07 by mmirzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
#include <stdlib.h>
#include <unistd.h>

# define SIZE 700

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define C 8
# define J 38
# define I 34
# define D 2

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int	name;
	int		max_iterations;
	float	tolerance;
}			t_fractal;

// utils.c
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int			exit_fractal(t_fractal *fractal);
void		change_iterations(t_fractal *fractal, int keycode);
void		ft_putendl_fd(char *s, int fd);

// init.c
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal);

// julia.c
void		calculate_julia(t_fractal *fractal, double cx, double cy);
void		new_julia(double *cx);

// burning_ship.c
void		calculate_burning_ship(t_fractal *fractal);

// newton fractal
void		calculate_newton(t_fractal *fractal);

// triangle mandelbrot
void		calculate_tri(t_fractal *fractal);

// main.c
int			draw_fractal(t_fractal *fractal, double cx, double cy);
// int			draw_fractal(t_fractal *fractal, char *query, double cx, double cy);
// int			draw_fractal(t_fractal *fractal, int query, double cx, double cy);

// hooks
void		key_hook(int keycode, t_fractal *fractal);
void		mouse_hook(int mousecode, int x, int y, t_fractal *fractal);

#endif
