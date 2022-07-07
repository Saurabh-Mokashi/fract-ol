/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:31:22 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/07 18:11:22 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	temp(char *s, int i)
{
	double	ans;
	int		ten;

	ans = 0.0;
	ten = 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		ans += (s[i] - '0') / pow(10, ten);
		i++;
		ten++;
	}
	return (ans);
}

double	atof_continue(char *s, int i, int sign)
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
			break ;
		i++;
	}
	if (s[i] == '.')
		ret += temp(s, i + 1);
	return (sign * ret);
}

double	ft_atof(char *s)
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
