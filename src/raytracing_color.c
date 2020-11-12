/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:01:00 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 05:41:31 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		raytracing_color2(t_all *all, t_hit *hit, t_shade_var *var,
	t_light *l)
{
	if (var->light->spot_light)
		var->color = spot_lighting(all, *var, hit, l);
	else
	{
		if (hit->m.type == toon_shad)
			var->color = toon_shading(*var, all, hit);
		else
		{
			if (is_diffuse(all, hit))
				var->color = diffuse(*var, hit);
			if (hit->m.specular == 1)
				var->color = specular(*var, all, hit);
		}
	}
}

t_vector	raytracing_color(t_all *all, t_hit *hit)
{
	t_shade_var	var;
	t_vector	dist;

	var.light = all->lights;
	var.color = (t_vector){0.0, 0.0, 0.0};
	var.color = ambient(*hit, var.light);
	while (var.light)
	{
		var.r.start = hit->p;
		dist = vector_sub(var.light->pos, hit->p);
		if (vector_dot(dist, hit->n) <= 0)
		{
			var.light = var.light->next;
			continue;
		}
		hit->t = sqrt(vector_dot(dist, dist));
		var.r.dir = vector_scale(dist, 1.0 / hit->t);
		if (!ray_secondary_intersection(all, &(var.r), hit))
			raytracing_color2(all, hit, &var, var.light);
		var.light = var.light->next;
	}
	if (all->scene.filter != 0)
		var.color = filter(var.color, all->scene.filter);
	return (var.color);
}
