/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:49:00 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/30 14:41:27 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "ft_printf.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include <time.h>

# define NB_BUFF 8
# define ZOOM_FACTOR 1.1

typedef struct	s_point2d
{
	int			x;
	int			y;
	int			height;
}				t_point2d;

typedef struct	s_line
{
	int			dx;
	int			dy;
	t_point2d	*p1;
	t_point2d	*p2;
}				t_line;

typedef struct	s_ipoint
{
	double			real;
	double			imag;
}				t_ipoint;

typedef struct	s_fractal
{
	t_ipoint	start;
	double		zoom;
	int			max_iter;
	int			min_iter;
	int			**color_scale;
}				t_fractal;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	void		*ptr_image;
	char		*str_image;
	t_fractal	*fractal;
	char		zoomin;
}				t_mlx;

typedef struct	s_buffer
{
	char		*buff;
	int			buff_id; //inutile?
	pthread_t	thread;
	int			start_pixel;
	int			size;
	t_fractal	*fractal;
	int			win_height;
	int			win_width;
	int			min_iter;
}				t_buffer;

void			*mandelbrot(void *buffer);
int				**scale(int color, int val);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *tmlx);
int				generate_imgstr(t_mlx *tmlx, t_fractal *fractal);
void			fill_string(t_buffer *buff, t_point2d *p, int color);
void			display(t_mlx *tmlx, t_fractal *fractal);

void			fill_image(t_mlx *tmlx, t_point2d *p, int color);
int				get_color(int value, int **color_scale);
int				ft_tsv2rgb(int t, int s, int v);
int				ft_rgb2tsv(int rgb, int *t, int *s, int *v);
void			pixel_put(t_mlx *tmlx, t_point2d *p, int height, char option);
void			trace_line(t_mlx *tmlx, t_point2d p1, t_point2d p2,
		char option);
void			twd_right_line(t_mlx *tmlx, t_line line, char option);
void			octant_1(t_mlx *tmlx, t_line line, char option);
void			octant_2(t_mlx *tmlx, t_line line, char option);
void			octant_8(t_mlx *tmlx, t_line line, char option);
void			octant_7(t_mlx *tmlx, t_line line, char option);
void			twd_left_line(t_mlx *tmlx, t_line line, char option);
void			octant_4(t_mlx *tmlx, t_line line, char option);
void			octant_3(t_mlx *tmlx, t_line line, char option);
void			octant_5(t_mlx *tmlx, t_line line, char option);
void			octant_6(t_mlx *tmlx, t_line line, char option);
void			horizontal_rh_line(t_mlx *tmlx, t_line line, char option);
void			horizontal_lh_line(t_mlx *tmlx, t_line line, char option);
void			vertical_up_line(t_mlx *tmlx, t_line line, char option);
void			vertical_dw_line(t_mlx *tmlx, t_line line, char option);

#endif
