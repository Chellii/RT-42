/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:45:01 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 04:17:15 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hit_sphere(t_hit *hit, t_obj *new, t_ray r)
{
	hit->hit = 1;
	hit->hit_point = 0;
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	hit->n = vector_sub(hit->p, new->pos);
	hit->n = vector_normalize(hit->n);
	if (new->material.texture_exist == 1 && new->material.type == normal_pert)
		hit->n.y += sin(r.i / 4) * (vector_norm(hit->n) / 4);
	hit->color = new->color;
	hit->m = new->material;
}

void	hit_plan(t_hit *hit, t_obj *new, t_ray r)
{
	hit->hit = 1;
	hit->hit_point = 0;
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	if (vector_dot(new->axis, r.dir) > 0.0)
		hit->n = vector_scale(new->axis, -1);
	else
		hit->n = new->axis;
	hit->color = new->color;
	hit->m = new->material;
}

void	hit_cylinder(t_hit *hit, t_obj *new, t_ray r)
{
	hit->hit = 1;
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	hit->hit_point = vector_dot(r.dir, new->axis) * hit->t +
		vector_dot(vector_sub(r.start, new->pos), new->axis);
	hit->n = vector_normalize(vector_sub(vector_sub(hit->p, new->pos),
		vector_scale(new->axis, hit->hit_point)));
	if (new->material.texture_exist && new->material.type == normal_pert)
		hit->n.y += sin(r.i / 4) * (vector_norm(hit->n) / 4);
	hit->color = new->color;
	hit->m = new->material;
}

void	hit_cone(t_hit *hit, t_obj *new, t_ray r)
{
	double k;

	hit->hit = 1;
	hit->hit_point = 0;
	k = tan((new->angle * M_PI / 180.0) / 2);
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	hit->hit_point = vector_dot(r.dir, new->axis) * hit->t +
		vector_dot(vector_sub(r.start, new->pos), new->axis);
	hit->n = vector_normalize(vector_sub(vector_sub(hit->p, new->pos),
		vector_scale(vector_scale(new->axis, hit->hit_point), (1 + k * k))));
	if (new->material.texture_exist && new->material.type == normal_pert)
		hit->n.y += sin(r.i / 4) * (vector_norm(hit->n) / 4);
	hit->color = new->color;
	hit->m = new->material;
}

void	hit_disk(t_hit *hit, t_obj *new, t_ray r)
{
	hit->hit = 1;
	hit->hit_point = 0;
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	if (vector_dot(new->axis, r.dir) > 0.0)
		hit->n = vector_scale(new->axis, -1);
	else
		hit->n = new->axis;
	hit->color = new->color;
	hit->m = new->material;
}
