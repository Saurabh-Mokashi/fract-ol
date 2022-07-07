/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:24:38 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/07 18:12:28 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	close_window(void)
{
	exit(0);
}

int	key_hook(int code, t_data *img)
{
	if (code == 53)
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	else if (code == 123 || code == 124 || code == 125 || code == 126)
		mover(img, code);
	else if (code == 24)
		img->iterations = getmin(img->iterations + 10, 500);
	else if (code == 27)
		img->iterations = getmax(img->iterations - 10, 10);
	else if (code == 18)
		img->clr = 0;
	else if (code == 19)
		img->clr = 1;
	else if (code == 20)
		img->clr = 2;
	else if (code == 21)
		img->clr = 3;
	else if (code == 23)
		img->clr = 4;
	getfrac(img);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_data *img)
{
	if (code == 4)
		img->zoomscale = 1.2;
	else if (code == 5)
		img->zoomscale = 0.8;
	else
		img->zoomscale = 1;
	zoomer(img, x, y, img->zoomscale);
	img->px = -1;
	img->py = -1;
	if (img->choice[0])
		mandelbrot(img, -1, -1);
	else if (img->choice[1])
		bship(img, -1, -1);
	else
		julia(img, -1, -1);
	return (0);
}

void	window_mgmt(char *s, float a, float b)
{
	t_data	img;

	init(&img, a, b);
	img.win = mlx_new_window(img.mlx, img.length, img.width, s);
	if (ft_strncmp(s, "mbrot", ft_strlen(s)) == 0)
	{
		img.choice[0] = 1;
		mandelbrot(&img, -1, -1);
	}
	else if (ft_strncmp(s, "bship", ft_strlen(s)) == 0)
	{
		img.choice[1] = 1;
		bship(&img, -1, -1);
	}
	else if (ft_strncmp(s, "julia", ft_strlen(s)) == 0)
	{
		img.choice[2] = 1;
		if (img.jx > 2 || img.jx < -2 || img.jy > 2 || img.jy < -2)
			return ;
		julia(&img, -1, -1);
	}
	mlx_key_hook(img.win, key_hook, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_hook(img.win, 17, 1L << 17, close_window, NULL);
	mlx_loop(img.mlx);
}

int	main(int ac, char **agv)
{
	if (ac > 4)
		write(1, "invlid no. of args. with exec, add mbrot/julia/bship\n", 54);
	if (ac == 2)
	{
		if (ft_strncmp(agv[1], "mbrot", ft_strlen(agv[1])) == 0)
			window_mgmt("mbrot", 0, 0);
		else if (ft_strncmp(agv[1], "bship", ft_strlen(agv[1])) == 0)
			window_mgmt("bship", 0, 0);
		else if (ft_strncmp(agv[1], "julia", ft_strlen(agv[1])) == 0)
			write(1, "missing real and imag coordinates\n", 35);
		else
			write(1, "invalid bship/mbrot retry\n", 27);
	}
	if (ac == 4)
	{
		if (ft_strncmp(agv[1], "julia", ft_strlen(agv[1])) == 0)
			window_mgmt("julia", ft_atof(agv[2]), ft_atof(agv[3]));
		else
			write(1, "only julia is allowed 3 args\n", 30);
	}
	return (0);
}
