/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 02:28:55 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/21 02:28:56 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	intersect_ray_square(t_ray *r, t_obj *s, double *t)
{
	t_intersect_var	var;
	float			m;
	float			t0;

	var.v = vector_normalize(vector_cross(s->v1, s->v2));
	var.u = vector_normalize(vector_cross(s->v1, var.v));
	m = vector_dot(s->v1, r->dir);
	if (m == 0.0)
		return (1);
	var.dist = vector_sub(s->pos, r->start);
	t0 = vector_dot(var.dist, s->v1) / m;
	if (t0 >= 0.0001 && t0 < *t)
	{
		var.oc = vector_sub(s->pos, vector_add(r->start,
			vector_scale(r->dir, t0)));
		if (fabs(vector_dot(var.v, var.oc)) > s->h)
			return (0);
		if (fabs(vector_dot(var.u, var.oc)) > s->w)
			return (0);
		*t = t0;
		return (1);
	}
	return (0);
}

int		intersect_paraboloid(t_ray *r, t_obj *parab, double *t)
{
	t_intersect_var var;
	float			t0;
	float			t1;

	var.dist = vector_sub(r->start, parab->pos);
	var.a = vector_dot(r->dir, r->dir) -
		pow(vector_dot(r->dir, parab->axis), 2);
	var.b = 2 * (vector_dot(r->dir, var.dist) - vector_dot(r->dir, parab->axis)
		* (vector_dot(var.dist, parab->axis) + 2 * parab->radius));
	var.c = vector_dot(var.dist, var.dist) - vector_dot(var.dist, parab->axis)
		* (vector_dot(var.dist, parab->axis) + 4 * parab->radius);
	var.delta = var.b * var.b - 4 * var.a * var.c;
	if (var.delta < 0)
		return (0);
	var.sqrdelta = sqrtf(var.delta);
	t0 = (-var.b + var.sqrdelta) / (2 * var.a);
	t1 = (-var.b - var.sqrdelta) / (2 * var.a);
	var.min = ft_min_ray(t0, t1, t);
	return (var.min);
}

int		intersect_ray_hyper(t_ray *r, t_obj *hyper, double *t)
{
	t_intersect_var	var;
	t_vector		dist;
	double			t0;
	double			t1;
	int				min;

	var.a = r->dir.x * r->dir.x + r->dir.z * r->dir.z - r->dir.y * r->dir.y;
	dist = vector_sub(r->start, hyper->pos);
	var.b = 2 * (dist.x * r->dir.x + dist.z * r->dir.z - dist.y * r->dir.y);
	var.c = (dist.x * dist.x + dist.z * dist.z - dist.y * dist.y) -
		hyper->radius;
	var.delta = var.b * var.b - 4 * var.a * var.c;
	if (var.delta < 0)
		return (0);
	var.sqrdelta = sqrt(var.delta);
	t0 = (-var.b + var.sqrdelta) / (2 * var.a);
	t1 = (-var.b - var.sqrdelta) / (2 * var.a);
	min = ft_min_ray(t0, t1, t);
	return (min);
}

int		intersect_ray_disk(t_all *all, t_ray r, t_obj *d, double *t)
{
	t_vector	dist;
	t_vector	ray;
	double		t0;

	t0 = *t;
	if (intersect_ray_plan(all, r, d, t))
	{
		ray = vector_add(r.start, vector_scale(r.dir, *t));
		dist = vector_sub(ray, d->pos);
		if (vector_dot(dist, dist) <= pow(d->radius, 2))
			return (1);
		else
		{
			*t = t0;
			return (0);
		}
	}
	else
		return (0);
	return (0);
}
