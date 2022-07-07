/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:35:28 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/07 12:32:04 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia_plot(t_data *img, int px, int py, float tempx)
{
	float	zx;
	float	zy;
	int		count;

	zx = scaler(px, img->minx, img->length -1, img->maxx);
	zy = scaler(py, img->maxy, img->width -1, img->miny);
	count = 0;
	while (zx * zx + zy * zy < 4 && count < img->iterations)
	{
		tempx = (zx * zx - zy * zy);
		zy = 2 * zx * zy + img->jy;
		zx = tempx + img->jx;
		count++;
	}
	if (count != img->iterations)
		draw(img, px, py, count);
}

void	julia(t_data	*img, int px, int py)
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
		{
			julia_plot(img, px, py, tempx);
		}
	}
	mlx_put_image_to_window((*img).mlx, (*img).win, (*img).img, 0, 0);
}
