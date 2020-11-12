/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:43:12 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/14 19:43:14 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	max_min(float d1, float d2, float d3)
{
	if (d2 < d3)
	{
		if (d2 > d1)
			return (d2);
		else
			return (d1);
	}
	else
	{
		if (d3 > d1)
			return (d3);
		else
			return (d1);
	}
}

float	max(float f1, float f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

void	swap_f(float *xp, float *yp)
{
	float temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}
