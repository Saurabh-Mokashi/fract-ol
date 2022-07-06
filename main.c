/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:24:38 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/06 18:28:10 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	key_hook(int code, t_data *img)
{
	if (code == 53)
	{
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
	img->px = -1;
	img->py = -1;
	getfrac(img);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_data *img)
{
	float	b4zoomx;
	float	b4zoomy;

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
	if (strcmp(s, "mbrot") == 0)
	{
		img.choice[0] = 1;
		mandelbrot(&img, -1, -1);
	}
	else if (strcmp(s, "bship") == 0)
	{
		img.choice[1] = 1;
		bship(&img, -1, -1);
	}
	else if (strcmp(s, "julia") == 0)
	{
		img.choice[2] = 1;
		if (img.jx > 2 || img.jx < -2 || img.jy > 2 || img.jy < -2)
			return ;
		julia(&img, -1, -1);
	}
	mlx_key_hook(img.win, key_hook, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_loop(img.mlx);
}

int	main(int ac, char **agv)
{
	if (ac > 4)
		printf("invlid no. of args. with exec, add mbrot/julia/bship\n");
	if (ac == 2)
	{
		if (strcmp(agv[1], "mbrot") == 0)
			window_mgmt("mbrot", 0, 0);
		else if (strcmp(agv[1], "bship") == 0)
			window_mgmt("bship", 0, 0);
		else if (strcmp(agv[1], "julia") == 0)
			printf("missing real and imag coordinates\n");
		else
			printf("invalid bship/mbrot retry\n");
	}
	if (ac == 4)
	{
		if (strcmp(agv[1], "julia") == 0)
			window_mgmt("julia", ft_atof(agv[2]), ft_atof(agv[3]));
		else
			printf("only julia is allowed 3 args\n");
	}
	return (0);
}
