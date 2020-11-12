/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 20:19:17 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/23 20:19:18 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		perlin(int *p, int *permutation)
{
	int i;

	i = 0;
	while (i < 512)
	{
		p[i] = permutation[i % 256];
		i++;
	}
}

double		fade(double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

double		lerp(double t, double a, double b)
{
	return (a + t * (b - a));
}

double		grad2(int h, double x, double y, double z)
{
	if (h == 8)
		return (y + z);
	else if (h == 9)
		return (-y + z);
	else if (h == 10)
		return (y - z);
	else if (h == 11)
		return (-y - z);
	else if (h == 12)
		return (y + x);
	else if (h == 13)
		return (-x + y);
	else if (h == 14)
		return (-y + z);
	else if (h == 15)
		return (-y - z);
	return (0.0);
}

double		grad(int hash, double x, double y, double z)
{
	int h;

	h = hash & 15;
	if (h == 0)
		return (x + y);
	else if (h == 1)
		return (-x + y);
	else if (h == 2)
		return (x - y);
	else if (h == 3)
		return (-x - y);
	else if (h == 4)
		return (x + z);
	else if (h == 5)
		return (-x + z);
	else if (h == 6)
		return (x - z);
	else if (h == 7)
		return (-x - z);
	else
		return (grad2(h, x, y, z));
}
