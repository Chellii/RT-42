/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 20:36:20 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/27 11:31:13 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	swap_vect(t_ray *r, t_obj *tri)
{
	if (vector_dot(vector_cross(tri->v3, tri->v4), r->dir) < 0)
	{
		tri->v1 = tri->v3;
		tri->v2 = tri->v4;
	}
	else
	{
		tri->v1 = tri->v4;
		tri->v2 = tri->v3;
	}
}

int		intersect_ray_triangle(t_ray *r, t_obj *tri, double *t)
{
	t_intersect_var var;

	swap_vect(r, tri);
	var.det = vector_dot(tri->v1, vector_cross(r->dir, tri->v2));
	if (var.det != 0)
	{
		var.dist = vector_sub(r->start, tri->pos);
		var.beta = vector_dot(var.dist, vector_cross(r->dir, tri->v2))
			/ var.det;
		if (var.beta < MIN_DIS || var.beta > 1)
			return (0);
		var.gamma = vector_dot(r->dir, vector_cross(var.dist, tri->v1))
			/ var.det;
		if (var.gamma < MIN_DIS || var.gamma > 1 || var.beta + var.gamma > 1.0)
			return (0);
		var.t0 = vector_dot(tri->v2, vector_cross(var.dist, tri->v1))
			/ var.det;
		if (var.t0 > MIN_DIS && var.t0 < *t)
		{
			*t = var.t0;
			return (1);
		}
	}
	return (0);
}
