/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:10:18 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 04:18:07 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	set_wood(t_ray ray)
{
	float ivalue;
	float jvalue;
	float dist_value;
	float sin_value;

	ivalue = (ray.i - 1000 / 2.) / 1000.;
	jvalue = (ray.j - 1000 / 2.) / 1000.;
	dist_value = sqrtf(ivalue * ivalue + jvalue * jvalue) + 0.012 *
		turbulence(ray.j, ray.i, 0, 32.);
	sin_value = (128. / 255.) * fabs(sin(2 * 12. * dist_value * M_PI));
	return ((t_vector){(80. / 255.) + sin_value, (30. / 255.) +
		sin_value, 30. / 255.});
}

t_vector	set_cloud(t_ray ray)
{
	float n;

	n = min_max(turbulence(ray.j, ray.i, 0.0, 50.)) / 4.;
	return ((t_vector){n + (183. / 255.), n + (186. / 255.), 1.0});
}

t_vector	set_marble(t_ray ray)
{
	float n;

	n = ray.i * 5. / 200. + ray.j * 8. / 8. +
		turbulence(ray.j, ray.i, 0, 32.) * 1.5;
	n = fabs(sin(n * M_PI));
	return ((t_vector){n, n, n});
}

t_vector	value_damier(t_hit hit)
{
	t_vector	color;
	float		sines;

	sines = sin(10 * hit.p.x) * sin(10 * hit.p.y) * sin(10 * hit.p.z);
	if (sines < 0)
		color = (t_vector){1.0, 1.0, 1.0};
	else
		color = (t_vector){0.0, 0.0, 0.0};
	return (color);
}

void		set_texture(t_hit *hit, t_ray ray)
{
	if ((hit->m.type != normal_pert) && (hit->m.type != xor__noise))
		hit->m.specular = 0.0;
	hit->m.reflection = 0.0;
	hit->m.refraction = 0.0;
	if (hit->m.type == wood)
		hit->color = set_wood(ray);
	else if (hit->m.type == cloud)
		hit->color = set_cloud(ray);
	else if (hit->m.type == marble)
		hit->color = set_marble(ray);
	else if (hit->m.type == damier)
		hit->color = value_damier(*hit);
	else if (hit->m.type == perlin_noise)
		hit->color = set_perlin_noise(ray);
	else if (hit->m.type == xor__noise)
		hit->color = xor_noise(hit->color, ray.j, ray.i);
}
