/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:27:33 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 03:32:06 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	wrong_format(int v)
{
	if (v == 0)
	{
		ft_putendl("Wrong format file.");
		return (0);
	}
	return (1);
}

int	ft_min_ray(double t1, double t2, double *t)
{
	if (((t1 < t2 || t2 < MIN_DIS) && t1 > MIN_DIS) && (t1 <= *t))
	{
		*t = t1;
		return (1);
	}
	else if (((t2 < t1 || t1 < MIN_DIS) && t2 > MIN_DIS) && (t2 <= *t))
	{
		*t = t2;
		return (1);
	}
	else
		return (0);
}

int	rt_min(double t1, double *t)
{
	if (t1 > MIN_DIS && t1 < *t)
	{
		*t = t1;
		return (1);
	}
	else
		return (0);
}
