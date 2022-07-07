/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbrot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:36:31 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/07 12:32:21 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mbrot_plot(t_data *img, int px, int py, float tempx)
{
	float	x0;
	float	y0;
	int		count;

	x0 = scaler(px, img->minx, img->length -1, img->maxx);
	y0 = scaler(py, img->maxy, img->width -1, img->miny);
	count = assignb(img, 0, 0);
	while (img->x * img->x + img->y * img->y <= 4 \
	&& count < img->iterations)
	{
		tempx = (img->x * img->x - img->y * img->y) + x0;
		img->y = 2 * img->x * img->y + y0;
		img->x = tempx;
		count++;
	}
	if (count != img->iterations)
		draw(img, px, py, count);
}

void	mandelbrot(t_data *img, int px, int py)
{
	float	tempx;

	tempx = 0.0;
	(*img).img = mlx_new_image((*img).mlx, img->length, img->width);
	(*img).addr = mlx_get_data_addr((*img).img, &(*img).bit_per_pixel, \
	&(*img).ll, &(*img).endian);
	while (px++ < img->length)
	{
		py = -1;
		while (py++ < img->width - 1)
			mbrot_plot(img, px, py, tempx);
	}
	mlx_put_image_to_window((*img).mlx, (*img).win, (*img).img, 0, 0);
}
