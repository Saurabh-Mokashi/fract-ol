/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:48:45 by smokashi          #+#    #+#             */
/*   Updated: 2022/06/24 15:11:12 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<1, close, &vars);
// 	mlx_loop(vars.mlx);
// }
int xchange=0;
int ychange=0;
int zoomscale = 1;

typedef struct s_data
{
	void *img;
	void *win;
	void *mlx;
	char *addr;
	int bit_per_pixel;
	int ll;
	int endian;
}				t_data;

void	pixel_put(t_data *img, int x, int y, int clr)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bit_per_pixel / 8));
	*(unsigned int*)dst = clr;
}

// void temp(int code,t_data *img)
// {
// 	// printf("yellow color");
// 	if(code == 123)
// 		printf("scroll left\n");
// 	if(code == 124)
// 		printf("scroll right\n");
// 	if(code == 125)
// 		printf("scroll down\n");
// 	if(code == 126)
// 		printf("scroll up\n");
// }

void plot(t_data *img)
{
	int i;
	mlx_destroy_image(img->mlx,img->img);
	// (*img).win = mlx_new_window((*img).mlx,1920,1080,"Hello World!!");
	(*img).img = mlx_new_image((*img).mlx, 1920, 1080);
	(*img).addr = mlx_get_data_addr((*img).img, &(*img).bit_per_pixel, &(*img).ll, &(*img).endian);
		
	int x_width = 1920,y_width = 1080;
	for(i=150;i<=250;i++)
	{
		pixel_put(img, (i+xchange),(150+ychange), 0x0000FF00);
	}
	for(i = 0;i<=100;i++)
	{
		pixel_put(img,( 250 + i+xchange),(150 + i+ychange), 0x0000FF00);
	}
	for(i = 0;i<=100;i++)
	{
		pixel_put(img, (150 - i+xchange),(150 + i + ychange), 0x0000FF00);
	}
	for(i = 0;i<=100;i++)
	{
		pixel_put(img, (50+xchange),(250 + i+ychange), 0x0000FF00);
		pixel_put(img, (350+xchange),(250 + i+ychange), 0x0000FF00);
	}
	for(i = 0;i<=100;i++)
	{
		pixel_put(img, (350 - i+xchange),(350 + i+ychange), 0x0000FF00);
	}
	for(i = 0;i<=100;i++)
	{
		pixel_put(img, (50 + i+xchange),(350 + i+ychange), 0x0000FF00);
	}
	for(i = 0;i<=100;i++)
	{
		pixel_put(img, (150 +xchange+ i),(450 + ychange), 0x0000FF00);
	}
	// float x = 0, y = 0, x0, tempx, y0;
    // int count;
	// int px,py;
	// for(int px = 0 ; px < x_width;px++)
	// {
	// 	for(int py = 0;py < y_width;py++)
	// 	{
	// 		//cx=0.25,cy=-0.25, zx=(x/960.0) - 1.0,zy=(y/540.0) - 1.0 ,count = 0;
	// 		x0 = (px/ 999.0) * 2.47 - 2;
	// 		// printf("x0 is %f\n",x0);
	// 		y0 = (py / 999.0) * 2.24 - 1.12;
	// 		// printf("y0 is %f",y0);
	// 		x = 0,y = 0,count = 0;
	// 		while(x * x + y * y <= 4 && count < 1000)
	// 		{
	// 			tempx = x * x - y * y;
	// 			tempx = tempx + x0;
	// 			y = 2 * x * y + y0;
	// 			x = tempx;
	// 			count++;
	// 		}
	// 		// printf("px +x_change val is %d\n",px +x_change);
	// 		// printf("py +y_change val is %d\n",py +y_change);
	// 		// if(count < 500)
	// 		// 	my_pixel_put(img,px+x_change,py+y_change, 0x000000ff*4* count);
	// 		// if(count < 200)
	// 		// 	my_pixel_put(img,px+x_change,py+y_change, 0xfaff00ff *4* count );
	// 		// if(count < 300)
	// 		// 	my_pixel_put(img,px+x_change,py+y_change, 0x0000ff00*4* count);
	// 		// else
	// 		// 	my_pixel_put(img,px+x_change,py+y_change, 0x00000000*4* count);
	// 		pixel_put(img,px,py,0xf9abcdff * count);
	// 	}
	// 	mlx_put_image_to_window((*img).mlx, (*img).win, (*img).img, 0,0);
	// }
	
	mlx_put_image_to_window((*img).mlx, (*img).win, (*img).img, 0, 0);
}

// int key_hook(int code, t_data img)
// {
// 	if(code == 123)
// 	{
// 		printf("left move received\n");
// 		xchange-=30;
// 	}
// 	if(code == 124)
// 	{
// 		printf("right move received\n");
// 		xchange+=30;
// 	}
// 	if(code == 125)
// 	{
// 		printf("down move received\n");
// 		ychange+=30;
// 	}
// 	if(code == 126)
// 	{
// 		printf("up move received\n");
// 		ychange -=30;
// 	}
// 	return (0);
// }
int close(int code, t_data *img)
{
	printf("%d\n",code);
	if(code == 53)
	{
		printf("escaped\n");
		mlx_destroy_window(img->mlx,img->win);
		return (0);
	}
	if(code == 123)
	{
		printf("left move received\n");
		xchange-=20;
		plot(img);
	}
	if(code == 124)
	{
		printf("right move received\n");
		xchange+=20;
		plot(img);
	}
	if(code == 125)
	{
		printf("down move received\n");
		ychange+=20;
		plot(img);
	}
	if(code == 126)
	{
		printf("up move received\n");
		ychange-=20;
		plot(img);
	}
	return (0);
}
int mouse_hook(int code, t_data *img)
{
	int a,b;
	
	if(code == 4)
	{
		printf("zoom scaled\n");
		mlx_mouse_get_pos(img->win,a,b);
		zoomscale*=1.001;
	}
	else if(code == 5)
	{
		printf("zoom scaled out\n");
		zoomscale*=0.999;
	}
	plot(img);
	// mlx_mouse_get_pos(img->win,&a,&b);
	return (0);
}

int	main(void)
{
	t_data	img;

	int i = 50,a,b;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx,1000,1000,"Hello World!!");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.ll, &img.endian);
	plot(&img);
// 	// pixel_put(&img, 500, 500, 0x00FF0000);
// 	// pixel_put(&img, 50, 50, 0x0000FF00);
// 	// mlx_string_put(mlx,mlx_win,100,100,0x0000FF00,"hello world!!");
// 	// mlx_loop_hook(mlx,temp,&img);
	//mlx_hook(img.win,2,1L<<0,close,&img);
	mlx_key_hook(img.win,close,&img);
	mlx_mouse_hook(img.win,mouse_hook,&img);
	mlx_mouse_get_pos(img.win,&a,&b);
	// mlx_loop_hook(img.mlx,close);
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	//mlx_string_put(img.mlx,img.win, 500, 500, 0x00FF0000, "Hello World!!");
	mlx_loop(img.mlx);
	return (0);
}
