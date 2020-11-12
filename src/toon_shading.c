/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toon_shading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:19:12 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 14:48:10 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		clamp(float x, float lowerlimit, float upperlimit)
{
	if (x < lowerlimit)
		x = lowerlimit;
	if (x > upperlimit)
		x = upperlimit;
	return (x);
}

float		smoothstep(float edge0, float edge1, float x)
{
	x = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
	return (x * x * (3 - 2 * x));
}

void		toon_specular(t_toon_shading *toon, t_all *all, t_shade_var var,
	t_hit *hit)
{
	toon->specular_color = (t_vector){0.4, 0.4, 0.4};
	toon->view_dir = vector_normalize(vector_sub(all->cam.lookfrom,
		var.r.start));
	var.r.dir = vector_scale(var.r.dir, -1);
	toon->light_reflect = reflect(var.r.dir, hit->n);
	toon->spec_ref = vector_dot(toon->light_reflect, toon->view_dir);
	toon->spec_ref = pow(toon->spec_ref * toon->light_intens, 20 * 20);
	toon->spec_ref = smoothstep(0.005, 0.01, toon->spec_ref);
	toon->specular_color = vector_scale(toon->specular_color, toon->spec_ref);
}

void		rim_lighting(t_toon_shading *toon, t_hit *hit)
{
	toon->rim_dot = 1 - vector_dot(toon->view_dir, hit->n);
	toon->rim_intensity = toon->rim_dot * pow(toon->ndotl, 0.1);
	toon->rim_intensity = smoothstep(0.716 - 0.01, 0.716 + 0.01,
		toon->rim_intensity);
	toon->rim = vector_scale((t_vector){0.3, 0.3, 0.3},
		toon->rim_intensity);
}

t_vector	toon_shading(t_shade_var var, t_all *all, t_hit *hit)
{
	t_toon_shading toon;

	toon.ndotl = vector_dot(var.r.dir, hit->n);
	toon.light_intens = smoothstep(0.0, 0.01, toon.ndotl);
	toon.light_color = vector_scale(var.light->color, toon.light_intens);
	toon.ret_color = vector_mult(hit->color,
		vector_add(toon.light_color, var.color));
	toon_specular(&toon, all, var, hit);
	rim_lighting(&toon, hit);
	return (vector_add(toon.ret_color,
		vector_add(toon.rim, toon.specular_color)));
}
