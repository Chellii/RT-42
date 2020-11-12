/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:15:27 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/02/27 00:15:28 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vector_scale(t_vector v, double s)
{
	t_vector r;

	r.x = v.x * s;
	r.y = v.y * s;
	r.z = v.z * s;
	return (r);
}

t_vector	vector_cross(t_vector v0, t_vector v1)
{
	t_vector r;

	r.x = v0.y * v1.z - v0.z * v1.y;
	r.y = v0.z * v1.x - v0.x * v1.z;
	r.z = v0.x * v1.y - v0.y * v1.x;
	return (r);
}

double		vector_norm(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector	vector_normalize(t_vector v)
{
	double norme;

	norme = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x /= norme;
	v.y /= norme;
	v.z /= norme;
	return (v);
}

double		vector_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
