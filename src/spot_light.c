/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:36:03 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 05:43:31 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			is_diffuse(t_all *all, t_hit *hit)
{
	if (hit->m.diffuse == 1)
	{
		if (hit->m.reflection != 0 || hit->m.refraction != 0)
		{
			if (all->scene.indirect != 0)
				return (1);
			else
				return (0);
		}
		else
			return (1);
	}
	return (0);
}

t_vector	spot_lighting(t_all *all, t_shade_var var, t_hit *hit, t_light *l)
{
	t_vector		color;
	t_spot_light	sl;

	sl.cutoff = cos(l->spot_light * MPI / 180);
	sl.outcutoff = cos((l->spot_light + 3) * MPI / 180.);
	sl.poslight = var.light->pos;
	sl.theta = vector_dot(var.r.dir, vector_normalize(sl.poslight));
	sl.epsilon = sl.cutoff - sl.outcutoff;
	sl.intensity = cmp((sl.theta - sl.outcutoff) / sl.epsilon, 0.0, 1.0);
	if (hit->m.type == toon_shad)
		color = vector_scale(toon_shading(var, all, hit), sl.intensity);
	else
	{
		if (is_diffuse(all, hit))
			color = vector_scale(diffuse(var, hit), sl.intensity);
		if (hit->m.specular == 1)
			color = vector_scale(specular(var, all, hit), sl.intensity);
	}
	return (color);
}
