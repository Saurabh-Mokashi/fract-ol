/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:31:22 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/06 18:11:15 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	fn(int cnt)
{
	int		ret;

	ret = 1;
	while (cnt > 0)
	{
		ret = ret * 10;
		cnt--;
	}
	return (ret);
}

float	atof_continue(char *s, int i, int sign)
{
	float	ret;
	int		place;

	ret = 0;
	place = 0;
	while ((s[i] >= '0' && s[i] <= '9' && s[i]) || s[i] == '.')
	{
		if (s[i] >= '0' && s[i] <= '9')
			ret = ret * 10 + (s[i] - '0');
		else if (s[i] == '.')
			place++;
		if (place > 0)
			place++;
		i++;
	}
	if (place)
		return (sign * (ret / fn(place - 2)));
	return (sign * ret);
}

float	ft_atof(char *s)
{
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	return (atof_continue(s, i, sign));
}
