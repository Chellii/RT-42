/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_fct2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:46:08 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/14 19:46:19 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hit_hyper(t_hit *hit, t_obj *new, t_ray r)
{
	hit->hit = 1;
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	hit->n.x = 2 * hit->p.x;
	hit->n.y = -2 * hit->p.y;
	hit->n.z = 2 * hit->p.z;
	hit->n = vector_normalize(hit->n);
	hit->color = new->color;
	hit->m = new->material;
}

void	hit_trig(t_hit *hit, t_obj *new, t_ray r)
{
	hit->hit = 1;
	hit->hit_point = 0;
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	hit->n = vector_normalize(vector_cross(vector_sub(new->v1, new->pos),
		vector_sub(new->v2, new->pos)));
	if (vector_dot(hit->n, r.dir) > 0.0)
		hit->n = vector_scale(hit->n, -1);
	else
		hit->n = hit->n;
	hit->color = new->color;
	hit->m = new->material;
}

void	hit_square(t_hit *hit, t_obj *new, t_ray r)
{
	hit->type = new->type;
	hit->hit = 1;
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	if (vector_dot(new->axis, r.dir) > 0.0)
		hit->n = vector_scale(new->axis, -1);
	else
		hit->n = new->axis;
	hit->color = new->color;
	hit->m = new->material;
}

void	hit_parab(t_hit *hit, t_obj *new, t_ray r)
{
	float k;

	hit->hit = 1;
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	k = vector_dot(vector_sub(hit->p, new->pos), new->axis);
	hit->n = vector_sub(vector_sub(hit->p, new->pos),
		vector_scale(new->axis, (k + new->radius)));
	hit->n = vector_normalize(hit->n);
	hit->color = new->color;
	hit->m = new->material;
}
