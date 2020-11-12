/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:45:19 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/02/20 00:19:40 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersection_sphere(double *t0, double *t1, t_ray r, t_obj *s)
{
	t_intersect_var var;

	var.a = vector_dot(r.dir, r.dir);
	var.dist = vector_sub(r.start, s->pos);
	var.b = 2 * vector_dot(r.dir, var.dist);
	var.c = vector_dot(var.dist, var.dist) - (s->radius * s->radius);
	var.delta = var.b * var.b - 4 * var.a * var.c;
	if (var.delta < 0)
		return (0);
	var.sqrdelta = sqrtf(var.delta);
	*t1 = (-var.b + var.sqrdelta) / (2 * var.a);
	*t0 = (-var.b - var.sqrdelta) / (2 * var.a);
	return (1);
}

int		intersection_cylinder(double *t0, double *t1, t_ray r, t_obj *cyl)
{
	t_intersect_var var;

	var.dist = vector_sub(r.start, cyl->pos);
	var.a = vector_dot(r.dir, r.dir) - (vector_dot(r.dir, cyl->axis) *
			vector_dot(r.dir, cyl->axis));
	var.b = 2 * (vector_dot(r.dir, var.dist) - vector_dot(r.dir, cyl->axis) *
			vector_dot(var.dist, cyl->axis));
	var.c = vector_dot(var.dist, var.dist) - (vector_dot(var.dist, cyl->axis) *
			vector_dot(var.dist, cyl->axis)) - cyl->radius * cyl->radius;
	var.delta = var.b * var.b - 4 * var.a * var.c;
	var.sqrdelta = sqrt(var.delta);
	if (var.delta < 0.0)
		return (0);
	*t0 = (-var.b - var.sqrdelta) / (2 * var.a);
	*t1 = (-var.b + var.sqrdelta) / (2 * var.a);
	return (1);
}

int		intersection_cone(double *t0, double *t1, t_ray r, t_obj *cone)
{
	t_intersect_var var;

	var.dist = vector_sub(r.start, cone->pos);
	var.k = tan((cone->angle * MPI / 180.0) / 2);
	var.a = vector_dot(r.dir, r.dir) -
		(1 + (var.k * var.k)) * (vector_dot(r.dir, cone->axis) *
				vector_dot(r.dir, cone->axis));
	var.b = 2 * (vector_dot(r.dir, var.dist) - (1 + var.k * var.k) *
			(vector_dot(r.dir, cone->axis)
			* vector_dot(var.dist, cone->axis)));
	var.c = vector_dot(var.dist, var.dist) - ((1 + var.k * var.k) *
			(vector_dot(var.dist, cone->axis) * vector_dot(var.dist,
			cone->axis)));
	var.delta = var.b * var.b - 4 * var.a * var.c;
	var.sqrdelta = sqrt(var.delta);
	if (var.delta < 0.0)
		return (0);
	*t0 = (-var.b - var.sqrdelta) / (2 * var.a);
	*t1 = (-var.b + var.sqrdelta) / (2 * var.a);
	return (1);
}
