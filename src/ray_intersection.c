/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:44:55 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/02/26 23:44:56 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray		get_ray(double u, double v, t_camera *c)
{
	t_ray		r;
	t_vector	dir;

	c->origin = c->lookfrom;
	c->k = vector_normalize(vector_sub(c->lookfrom, c->lookat));
	c->i = vector_normalize(vector_cross(c->lookup, c->k));
	c->j = vector_cross(c->k, c->i);
	c->w = vector_sub(c->origin, vector_add(vector_add(vector_scale(c->i,
						c->half_width),
					vector_scale(c->j, c->half_height)), c->k));
	c->horizontal = vector_scale(c->i, 2.0 * c->half_width);
	c->vertical = vector_scale(c->j, 2.0 * c->half_height);
	dir = vector_add(vector_add(vector_scale(c->horizontal, u),
				vector_scale(c->vertical, v)), c->w);
	r.start = c->origin;
	dir = vector_sub(dir, r.start);
	r.dir = vector_normalize(dir);
	r.i = 0;
	r.j = 0;
	return (r);
}

void		ray_primary2(t_all *all, t_ray ray, t_hit *hit, t_obj *new)
{
	if (new->type == SPHERE && intersect_ray_sphere(all, ray, new, &(hit->t)))
		hit_sphere(hit, new, ray);
	else if (new->type == PLANE && intersect_ray_plan(all, ray, new, &(hit->t)))
		hit_plan(hit, new, ray);
	else if (new->type == CYLINDER &&
		intersect_ray_cylinder(all, ray, new, &(hit->t)))
		hit_cylinder(hit, new, ray);
	else if (new->type == CONE && intersect_ray_cone(all, ray, new, &(hit->t)))
		hit_cone(hit, new, ray);
	else if (new->type == DISK && intersect_ray_disk(all, ray, new, &(hit->t)))
		hit_disk(hit, new, ray);
	else if (new->type == TRIG && intersect_ray_triangle(&ray, new, &(hit->t)))
		hit_trig(hit, new, ray);
	else if (new->type == HYPER && intersect_ray_hyper(&ray, new, &(hit->t)))
		hit_hyper(hit, new, ray);
	else if (new->type == SQUARE && intersect_ray_square(&ray, new, &(hit->t)))
		hit_square(hit, new, ray);
	else if (new->type == PARAB && intersect_paraboloid(&ray, new, &(hit->t)))
		hit_parab(hit, new, ray);
	else if (new->type == TORUS && intersect_ray_torus(&ray, new, &(hit->t)))
		hit_torus(hit, new, ray);
	else if (new->type == CUBE && intersect_ray_cube(&ray, new, hit))
		hit_cube(hit, new, ray);
}

int			ray_primary_intersection(t_all *all, t_ray ray, t_hit *hit)
{
	t_obj *new;

	new = all->obj;
	hit->hit = 0;
	hit->t = INFINITY;
	while (new)
	{
		if (new->negative != 1)
		{
			hit->type = new->type;
			ray_primary2(all, ray, hit, new);
		}
		new = new->next;
	}
	if (hit->hit == 1)
		return (1);
	else
		return (0);
}

int			ray_secondary2(t_all *all, t_ray r, t_hit *hit, t_obj *new)
{
	if (new->type == SPHERE && intersect_ray_sphere(all, r, new, &(hit->t)))
		return (1);
	else if (new->type == PLANE && intersect_ray_plan(all, r, new, &(hit->t)))
		return (1);
	else if (new->type == CYLINDER && intersect_ray_cylinder(all, r, new,
		&(hit->t)))
		return (1);
	else if (new->type == CONE && intersect_ray_cone(all, r, new, &(hit->t)))
		return (1);
	else if (new->type == DISK && intersect_ray_disk(all, r, new, &(hit->t)))
		return (1);
	else if (new->type == TRIG && intersect_ray_triangle(&r, new, &(hit->t)))
		return (1);
	else if (new->type == SQUARE && intersect_ray_square(&r, new, &(hit->t)))
		return (1);
	else if (new->type == HYPER && intersect_ray_hyper(&r, new, &(hit->t)))
		return (1);
	else if (new->type == PARAB && intersect_paraboloid(&r, new, &(hit->t)))
		return (1);
	else if (new->type == TORUS && intersect_ray_torus(&r, new, &(hit->t)))
		return (1);
	else if (new->type == CUBE && intersect_ray_cube(&r, new, hit))
		return (1);
	return (0);
}

int			ray_secondary_intersection(t_all *all, t_ray *ray, t_hit *hit)
{
	t_obj	*new;
	t_ray	r;

	r = *ray;
	new = all->obj;
	while (new)
	{
		if (new->negative != 1)
		{
			r.start = vector_add(hit->p, vector_scale(hit->n, 0.0001));
			if (ray_secondary2(all, r, hit, new))
				return (1);
		}
		new = new->next;
	}
	return (0);
}
