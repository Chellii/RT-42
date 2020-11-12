/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refl_refr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:14:02 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/19 14:15:02 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	refract(t_vector rdir, t_vector normal, float ior)
{
	float r_dot_n;
	float n1;
	float n2;
	float n;
	float c2;

	n1 = 1;
	n2 = ior;
	r_dot_n = max_min(-1, 1, vector_dot(rdir, normal));
	if (r_dot_n < 0)
		r_dot_n = -r_dot_n;
	else
	{
		swap_f(&n1, &n2);
		normal = vector_scale(normal, -1);
	}
	n = n1 / n2;
	c2 = 1 - n * n * (1 - r_dot_n * r_dot_n);
	if (c2 < 0)
		return ((t_vector){0.0, 0.0, 0.0});
	return (vector_add(vector_scale(rdir, n),
				vector_scale(normal, (n * r_dot_n - sqrtf(c2)))));
}

t_vector	reflection(t_all *all, t_hit hit, t_ray ray, int depth)
{
	t_ray		re_ray;
	t_vector	reflection_color;

	reflection_color = (t_vector){0.0, 0.0, 0.0};
	re_ray.dir = reflect(ray.dir, hit.n);
	re_ray.dir = vector_normalize(re_ray.dir);
	re_ray.start = vector_add(hit.p, vector_scale(hit.n, 0.001));
	reflection_color = shade(all, re_ray, depth);
	return (reflection_color);
}

t_vector	refract_reflect(t_all *all, t_ray ray, int depth, t_hit hit)
{
	int			outside;
	t_ray		ref_ray;
	t_vector	refraction_color;
	t_vector	color;

	color = (t_vector){0, 0, 0};
	if (hit.m.refraction != 0)
	{
		if (vector_dot(ray.dir, hit.n) > 0)
			outside = 1;
		else
			outside = 0;
		ref_ray.dir = refract(ray.dir, hit.n, 1.5);
		ref_ray.dir = vector_normalize(ref_ray.dir);
		if (outside == 1)
			ref_ray.start = vector_add(hit.p, vector_scale(hit.n, 0.001));
		else
			ref_ray.start = vector_sub(hit.p, vector_scale(hit.n, 0.001));
		refraction_color = shade(all, ref_ray, depth + 1);
		color = vector_scale(refraction_color, 1);
	}
	else if (hit.m.reflection != 0 && hit.m.refraction == 0)
		color = vector_scale(reflection(all, hit, ray, depth + 1),
			hit.m.reflection);
	return (color);
}
