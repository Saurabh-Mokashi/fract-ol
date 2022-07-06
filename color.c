/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:34:01 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/06 18:10:55 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	getcolor(int count)
{
	if (count == 0)
		return (create_trgb(0, 254, 0, 0));
	else if (count == 1)
		return (create_trgb(0, 255, 121, 1));
	else if (count == 2)
		return (create_trgb(0, 255, 255, 11));
	else if (count == 3)
		return (create_trgb(0, 34, 219, 19));
	else if (count == 4)
		return (create_trgb(0, 36, 48, 255));
	else if (count == 5)
		return (create_trgb(0, 102, 0, 146));
	else if (count == 6)
		return (create_trgb(0, 200, 0, 249));
	return (create_trgb(0, 0, 0, 0));
}

int	getcolor2(int count)
{
	if (count == 0)
		return (create_trgb(0, 0, 7, 100));
	else if (count == 1)
		return (create_trgb(0, 32, 107, 203));
	else if (count == 2)
		return (create_trgb(0, 237, 255, 255));
	else if (count == 3)
		return (create_trgb(0, 255, 170, 0));
	else
		return (create_trgb(0, 0, 2, 0));
}

void	my_pixel_put(t_data *img, int x, int y, int clr)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bit_per_pixel / 8));
	*(unsigned int *)dst = clr;
}

void	draw(t_data *img, int px, int py, int count)
{
	if (img->clr == 0)
		my_pixel_put(img, px, py, 0x00ff789A * count);
	else if (img->clr == 1)
		my_pixel_put(img, px, py, 0x00ff5678 * count / log(2));
	else if (img->clr == 2)
		my_pixel_put(img, px, py, getcolor((count + img->clr) % 7));
	else if (img->clr == 3)
		my_pixel_put(img, px, py, getcolor2((count + img->clr) % 5));
	else
		my_pixel_put(img, px, py, 0x00001200 * count);
}
