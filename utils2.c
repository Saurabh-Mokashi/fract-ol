/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:54:08 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/07 17:45:03 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	getfrac(t_data *img)
{
	img->px = -1;
	img->py = -1;
	if (img->choice[0])
		mandelbrot(img, -1, -1);
	else if (img->choice[1])
		bship(img, -1, -1);
	else
		julia(img, -1, -1);
}

void	init(t_data *img, float a, float b)
{
	img->length = 500;
	img->width = 500;
	img->zoomscale = 1;
	img->iterations = 100;
	img->mlx = mlx_init();
	img->img = mlx_new_image(img->mlx, img->length, img->width);
	img->clr = 0;
	img->addr = mlx_get_data_addr(img->img, &img->bit_per_pixel, \
	&img->ll, &img->endian);
	img->choice[0] = 0;
	img->choice[1] = 0;
	img->choice[2] = 0;
	img->maxx = 2;
	img->minx = -2;
	img->maxy = 2;
	img->miny = -2;
	img->jx = a;
	img->jy = b;
}

int	getmin(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	getmax(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
