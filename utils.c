/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:43:47 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/06 18:11:44 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	assignb(t_data *img, float a, float b)
{
	img->x = a;
	img->y = b;
	return (0);
}

float	scaler(int x, float newmin, float oldmax, float newmax)
{
	float	xtemp;

	xtemp = x * ((newmax - newmin)) / (oldmax) + newmin;
	return (xtemp);
}

void	mover(t_data *img, int code)
{
	if (code == 123)
	{
		img->minx = img->minx + 0.1 * img->zoomscale;
		img->maxx = img->maxx + 0.1 * img->zoomscale;
	}
	else if (code == 124)
	{
		img->minx = img->minx - 0.1 * img->zoomscale;
		img->maxx = img->maxx - 0.1 * img->zoomscale;
	}
	else if (code == 125)
	{
		img->miny = img->miny - 0.1 * img->zoomscale;
		img->maxy = img->maxy - 0.1 * img->zoomscale;
	}
	else if (code == 126)
	{
		img->miny = img->miny + 0.1 * img->zoomscale;
		img->maxy = img->maxy + 0.1 * img->zoomscale;
	}
}

void	zoomer(t_data *img, int x, int y, float zoomscale)
{
	float	b4zoomx;
	float	b4zoomy;

	img->zoomscale = zoomscale;
	b4zoomx = scaler(x, img->minx, img->length -1, img->maxx);
	b4zoomy = scaler(y, img->miny, img->width -1, img->maxy);
	img->minx = b4zoomx + (img->minx - b4zoomx) * zoomscale;
	img->maxx = b4zoomx + (img->maxx - b4zoomx) * zoomscale;
	img->miny = b4zoomy + (img->miny - b4zoomy) * zoomscale;
	img->maxy = b4zoomy + (img->maxy - b4zoomy) * zoomscale;
}
