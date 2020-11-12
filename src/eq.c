/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:05:36 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/01 14:28:42 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	is_zero(double x)
{
	return ((x) > -EQN_EPS && (x) < EQN_EPS);
}

double	pow1(double x)
{
	return (pow((double)(x), 1.0 / 3.0));
}

double	pow2(double x)
{
	return (pow((double)-(x), 1.0 / 3.0));
}

double	cbrt(double x)
{
	if (x > 0.0)
		return (pow1(x));
	else
		return ((x) < 0.0 ? -pow2(x) : 0.0);
}
