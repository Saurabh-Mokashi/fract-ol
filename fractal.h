/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:02:23 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/12 11:10:26 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_data
{
	int		iterations;
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bit_per_pixel;
	int		ll;
	int		endian;
	int		choice[3];
	float	x;
	float	y;
	int		px;
	int		py;
	float	jx;
	float	jy;
	int		length;
	int		width;
	float	zoomscale;
	int		clr;
	float	minx;
	float	miny;
	float	maxx;
	float	maxy;
}	t_data;

void	bship_plot(t_data *img, int px, int py, float tempx);
void	bship(t_data	*img, int px, int py);
int		create_trgb(int t, int r, int g, int b);
int		getcolor(int count);
int		getcolor2(int count);
void	my_pixel_put(t_data *img, int x, int y, int clr);
void	draw(t_data *img, int px, int py, int count);
double	fn(int cnt);
double	atof_continue(char *s, int i, int sign);
double	ft_atof(char *s);
void	julia_plot(t_data *img, int px, int py, float tempx);
void	julia(t_data	*img, int px, int py);
void	mbrot_plot(t_data *img, int px, int py, float tempx);
void	mandelbrot(t_data *img, int px, int py);
int		assignb(t_data *img, float a, float b);
float	scaler(int x, float newmin, float oldmax, float newmax);
void	mover(t_data *img, int code);
void	zoomer(t_data *img, int x, int y, float zoomscale);
void	getfrac(t_data *img);
void	init(t_data *img, float a, float b);
int		getmin(int a, int b);
int		getmax(int a, int b);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif