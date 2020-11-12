/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 20:35:09 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 03:32:16 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		solve(double sl[5], double *t)
{
	t_intersect_var	s;
	int				i;

	i = 0;
	s.t = INFINITY;
	if (!(s.res = ft_solve_quartic(sl, s.tab)))
		return (0);
	while (i < s.res)
	{
		if (s.tab[i] < s.t && s.tab[i] > MIN_DIS)
			s.t = s.tab[i];
		i++;
	}
	s.min = rt_min(s.t, t);
	return (s.min);
}

void	hit_cube(t_hit *hit, t_obj *new, t_ray r)
{
	hit->hit = 1;
	hit->p = vector_add(hit->start_cube, vector_scale(r.dir, hit->t));
	hit->n.x = 4 * pow(hit->p.x, 3) - 10 * hit->p.x;
	hit->n.y = 4 * pow(hit->p.y, 3) - 10 * hit->p.y;
	hit->n.z = 4 * pow(hit->p.z, 3) - 10 * hit->p.z;
	hit->n = vector_normalize(hit->n);
	hit->color = new->color;
	hit->m = new->material;
}

int		intersect_ray_cube(t_ray *r, t_obj *cube, t_hit *hit)
{
	t_intersect_var	var;

	hit->start_cube = vector_sub(r->start, (t_vector){0, 0, 0});
	var.sl[4] = pow(r->dir.x, 4) + pow(r->dir.y, 4) + pow(r->dir.z, 4);
	var.sl[3] = (4.0 * (pow(r->dir.x, 3) * hit->start_cube.x +
		pow(r->dir.y, 3) * hit->start_cube.y + pow(r->dir.z, 3) *
		hit->start_cube.z));
	var.sl[2] = (6.0 * (pow(r->dir.x, 2) * pow(hit->start_cube.x, 2)
		+ pow(r->dir.y, 2) * pow(hit->start_cube.y, 2) + pow(r->dir.z, 2) *
		pow(hit->start_cube.z, 2)) - 5.0 * vector_dot(r->dir, r->dir));
	var.sl[1] = (4.0 * (pow(hit->start_cube.x, 3) * r->dir.x +
		pow(hit->start_cube.y, 3) * r->dir.y + pow(hit->start_cube.z, 3) *
		r->dir.z) - 10.0 * vector_dot(r->dir, hit->start_cube));
	var.sl[0] = (pow(hit->start_cube.x, 4) + pow(hit->start_cube.y, 4) +
		pow(hit->start_cube.z, 4) - 5.0 *
		vector_dot(hit->start_cube, hit->start_cube) + cube->radius);
	var.min = solve(var.sl, &(hit->t));
	return (var.min);
}

int		intersect_ray_torus(t_ray *r, t_obj *tor, double *t)
{
	t_intersect_var var;

	var.r1 = pow(tor->radius1, 2);
	var.r2 = pow(tor->radius, 2);
	var.dist = vector_sub(r->start, tor->pos);
	var.s = vector_dot(var.dist, r->dir);
	var.sl[4] = pow(vector_dot(r->dir, r->dir), 2);
	var.p = pow(var.dist.x, 2) + pow(var.dist.y, 2) + pow(var.dist.z, 2);
	var.p = var.p - (var.r2 + var.r1);
	var.sl[3] = (4.0 * var.sl[4] * var.s);
	var.sl[2] = (2.0 * var.sl[4] * var.p + 4.0 * pow(var.s, 2) + 4.0 * var.r1
		* pow(r->dir.y, 2));
	var.sl[1] = (4.0 * var.p * var.s + 8.0 * var.r1 * var.dist.y * r->dir.y);
	var.sl[0] = (pow(var.p, 2) - 4.0 * var.r1 * (var.r2 - pow(var.dist.y, 2)));
	var.min = solve(var.sl, t);
	return (var.min);
}

void	hit_torus(t_hit *hit, t_obj *new, t_ray r)
{
	double k;
	double sub_r;

	hit->hit = 1;
	hit->p = vector_add(r.start, vector_scale(r.dir, hit->t));
	k = (pow(hit->p.x, 2) + pow(hit->p.y, 2) + pow(hit->p.z, 2));
	sub_r = (pow(new->radius, 2) - pow(new->radius1, 2));
	hit->n.x = 4.0 * hit->p.x * (k - sub_r);
	hit->n.y = 4.0 * hit->p.y * (k - sub_r + 2.0 * pow(new->radius1, 2));
	hit->n.z = 4.0 * hit->p.z * (k - sub_r);
	hit->n = vector_normalize(hit->n);
	hit->color = new->color;
	hit->m = new->material;
}
