/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 23:16:17 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/15 23:16:35 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	sepia(t_vector c)
{
	c.x = (c.x * 0.393) + (c.y * 0.769) + (c.z * 0.189);
	c.y = (c.x * 0.349) + (c.y * 0.686) + (c.z * 0.168);
	c.z = (c.x * 0.272) + (c.y * 0.534) + (c.z * 0.131);
	return (c);
}

t_vector	gray_scale(t_vector c)
{
	float k;

	k = (0.2126 * c.x) + (0.7152 * c.y) + (0.0722 * c.z);
	c.x = k;
	c.y = k;
	c.z = k;
	return (c);
}

t_vector	filter(t_vector color, int filter_var)
{
	if (filter_var == 1)
		color = sepia(color);
	if (filter_var == 2 || filter_var == 3)
		color = gray_scale(color);
	return (color);
}
