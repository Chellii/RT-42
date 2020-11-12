/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:44:50 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/19 19:45:18 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		modulo(float f)
{
	return (f - floor(f));
}

t_vector	random_cos_vec(t_vector n)
{
	t_rand_cos_vec r_vec;

	r_vec.r1 = (rand() / (double)RAND_MAX);
	r_vec.r2 = (rand() / (double)RAND_MAX);
	r_vec.direct_rand_rep_loc = (t_vector){cos(2 * MPI * r_vec.r1) *
		sqrt(1 - r_vec.r2), sin(2 * MPI * r_vec.r1) * sqrt(1 - r_vec.r2),
		sqrt(r_vec.r2)};
	r_vec.random_vect = (t_vector){(rand() / (double)RAND_MAX) + 0.5,
		(rand() / (double)RAND_MAX) + 0.5,
		(rand() / (double)RAND_MAX) + 0.5};
	r_vec.tang1 = vector_cross(n, r_vec.random_vect);
	r_vec.tang1 = vector_normalize(r_vec.tang1);
	r_vec.tang2 = vector_cross(r_vec.tang1, n);
	r_vec.random_dir = vector_add(vector_scale(n, r_vec.direct_rand_rep_loc.z),
		vector_add(vector_scale(r_vec.tang1, r_vec.direct_rand_rep_loc.x),
		vector_scale(r_vec.tang2, r_vec.direct_rand_rep_loc.y)));
	return (r_vec.random_dir);
}

t_vector	global_lgt(t_all *all, int depth, t_hit hit)
{
	t_ray	random_ray;

	random_ray.dir = random_cos_vec(hit.n);
	random_ray.start = vector_add(hit.p, vector_scale(hit.n, 0.001));
	return (vector_mult(shade(all, random_ray, depth + 1),
		hit.color));
}

int			arret_shade(t_hit hit, int depth)
{
	if (hit.m.refraction != 0)
	{
		if (depth > hit.m.refraction)
			return (1);
	}
	else if (hit.m.reflection != 0)
	{
		if (depth > hit.m.reflection)
			return (1);
	}
	return (0);
}

t_vector	shade(t_all *all, t_ray ray, int depth)
{
	t_vector	color;
	t_hit		hit;

	ft_memset(&hit, 0, sizeof(hit));
	color = (t_vector){0.0, 0.0, 0.0};
	if (ray_primary_intersection(all, ray, &hit))
	{
		if ((all->scene.indirect == 0) && (arret_shade(hit, depth)))
			return (color);
		if (hit.m.texture_exist == 1.0)
			set_texture(&hit, ray);
		color = raytracing_color(all, &hit);
		if ((all->scene.indirect == 0) &&
			(hit.m.refraction != 0 || hit.m.reflection != 0))
			color = vector_add(color, refract_reflect(all, ray, depth, hit));
		if (all->scene.indirect != 0.0)
		{
			if (depth > 5)
				return (color);
			color = vector_add(color, global_lgt(all, depth, hit));
		}
	}
	return (color);
}
