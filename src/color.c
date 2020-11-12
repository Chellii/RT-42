/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:48:15 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 05:31:20 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	cmp(double value, double min, double max)
{
	if (value > max)
		return (max);
	if (value < min)
		return (min);
	return (value);
}

int		rgb_color(t_vector clr)
{
	unsigned char color[4];

	color[0] = cmp(clr.z * 255, 0, 255);
	color[1] = cmp(clr.y * 255, 0, 255);
	color[2] = cmp(clr.x * 255, 0, 255);
	color[3] = 0;
	return (*((int *)color));
}
