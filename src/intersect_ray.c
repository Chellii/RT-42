/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:56:12 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/19 13:56:14 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersect_ray_sphere(t_all *all, t_ray r, t_obj *s, double *t)
{
	t_intersect_var	var;
	double			t0;
	double			t1;
	int				verif;

	verif = 0;
	if (!(intersection_sphere(&(var.t0), &(var.t1), r, s)))
		return (0);
	verif = find_neg_intersection(r, all, &t0, &t1);
	if (verif == 1)
		intersect_neg_obj(t0, t1, var);
	else
	{
		if (s->cut_xyz != 0.0)
			var.min = ft_limit_ray(var, t, &r, s);
		else
			var.min = ft_min_ray(var.t0, var.t1, t);
		return (var.min);
	}
	return (0);
}

int		intersect_ray_cylinder(t_all *all, t_ray r, t_obj *cyl, double *t)
{
	t_intersect_var	var;
	double			t0;
	double			t1;

	if (!intersection_cylinder(&(var.t0), &(var.t1), r, cyl))
		return (0);
	if (find_neg_intersection(r, all, &t0, &t1) == 1)
		return (intersect_neg_obj(t0, t1, var));
	else
	{
		var.t_prec = *t;
		if (cyl->cut_xyz != 0.0)
			var.min = ft_limit_ray(var, t, &r, cyl);
		else
			var.min = ft_min_ray(var.t0, var.t1, t);
		var.hit_point = vector_dot(r.dir, cyl->axis) * *t +
			vector_dot(vector_sub(r.start, cyl->pos), cyl->axis);
		if ((cyl->cut_cyl != 0.0) && (fabs(var.hit_point) > cyl->cut_cyl))
		{
			*t = var.t_prec;
			return (0);
		}
		return (var.min);
	}
	return (0);
}

int		intersect_ray_plan(t_all *all, t_ray r, t_obj *p, double *t)
{
	double		m;
	double		t0;
	double		t0_neg;
	double		t1_neg;
	t_vector	dist;

	m = vector_dot(r.dir, p->axis);
	if (m != 0)
	{
		dist = vector_sub(r.start, p->pos);
		t0 = (-vector_dot(dist, p->axis)) / m;
		if (find_neg_intersection(r, all, &t0_neg, &t1_neg) == 1)
			return (intersect_neg_plan(t0_neg, t1_neg, t0, t));
		else
		{
			if (t0 > MIN_DIS && t0 < *t)
			{
				*t = t0;
				return (1);
			}
		}
	}
	return (0);
}

int		cut_cone(t_obj *cone, t_intersect_var var, double *t)
{
	if (cone->cut_var_cone1 == cone->cut_var_cone2)
	{
		if (fabs(var.hit_point) > cone->cut_var_cone1)
		{
			*t = var.t_prec;
			return (0);
		}
	}
	if (cone->cut_var_cone1 < cone->cut_var_cone2)
	{
		if ((var.hit_point < cone->cut_var_cone1) ||
			(var.hit_point > cone->cut_var_cone2))
		{
			*t = var.t_prec;
			return (0);
		}
	}
	return (1);
}

int		intersect_ray_cone(t_all *all, t_ray r, t_obj *cone, double *t)
{
	t_intersect_var	var;
	double			t0;
	double			t1;

	if (!(intersection_cone(&(var.t0), &(var.t1), r, cone)))
		return (0);
	if (find_neg_intersection(r, all, &t0, &t1) == 1)
		intersect_neg_obj(t0, t1, var);
	else
	{
		var.t_prec = *t;
		if (cone->cut_xyz != 0.0)
			var.min = ft_limit_ray(var, t, &r, cone);
		else
			var.min = ft_min_ray(var.t0, var.t1, t);
		var.hit_point = vector_dot(r.dir, cone->axis) * *t +
			vector_dot(vector_sub(r.start, cone->pos), cone->axis);
		if (!((cone->cut_var_cone1 == 0.0) && (cone->cut_var_cone2 == 0.0)))
		{
			if (!(cut_cone(cone, var, t)))
				return (0);
		}
		return (var.min);
	}
	return (0);
}
