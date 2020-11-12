/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:17:31 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 05:43:11 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	ambient(t_hit hit, t_light *light)
{
	if (hit.m.type == toon_shad)
		return (vector_scale(hit.color, 0.6));
	else
		return (vector_scale(hit.color, light->amb_intens));
}

t_vector	diffuse(t_shade_var var, t_hit *hit)
{
	double		lambert;
	t_vector	diff;

	lambert = vector_dot(var.r.dir, hit->n);
	diff = vector_scale(hit->color, lambert);
	return (vector_add(vector_mult(var.light->color,
		vector_mult(diff, var.light->intensity)), var.color));
}

t_vector	reflect(t_vector rdir, t_vector n)
{
	return (vector_sub(rdir, vector_scale(vector_scale(n,
		vector_dot(rdir, n)), 2.0)));
}

t_vector	specular(t_shade_var var, t_all *all, t_hit *hit)
{
	t_vector	view_dir;
	t_vector	light_reflect;
	double		spec_ref;

	view_dir = vector_normalize(vector_sub(all->cam.lookfrom, var.r.start));
	var.r.dir = vector_scale(var.r.dir, -1);
	light_reflect = reflect(var.r.dir, hit->n);
	spec_ref = vector_dot(light_reflect, view_dir);
	if (spec_ref > 0)
	{
		spec_ref = pow(spec_ref, 40);
		return (vector_add(vector_mult(var.light->color,
			vector_scale(var.light->intensity, spec_ref)), var.color));
	}
	return (var.color);
}
