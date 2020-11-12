/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:51:57 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/19 13:51:59 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		find_neg_intersection(t_ray ray, t_all *all, double *t0, double *t1)
{
	t_obj *obj;

	obj = all->obj;
	while (obj)
	{
		if (obj->type == SPHERE && obj->negative == 1)
		{
			if ((intersection_sphere(t0, t1, ray, obj)) == 1)
				return (1);
		}
		else if (obj->type == CYLINDER && obj->negative == 1)
		{
			if ((intersection_cylinder(t0, t1, ray, obj)) == 1)
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}

double	intersect_neg_obj2(double t0, double t1, t_intersect_var var)
{
	if ((var.t0 >= t1) && (var.t0 <= t0))
	{
		if ((var.t1 < t1) || (var.t1 > t0))
			return (var.t1);
	}
	else if ((var.t1 >= t1) && (var.t1 <= t0))
	{
		if ((var.t0 < t1) || (var.t0 > t0))
			return (var.t0);
	}
	else if ((var.t0 >= t1) && (var.t0 <= t0) && (var.t1 >= t1) &&
		(var.t1 <= t0))
		return (0);
	else
		return (0);
	return (0);
}

double	intersect_neg_obj(double t0, double t1, t_intersect_var var)
{
	if (t0 < t1)
	{
		if ((var.t0 >= t0) && (var.t0 <= t1))
		{
			if ((var.t1 < t0) || (var.t1 > t1))
				return (var.t1);
		}
		else if ((var.t1 >= t0) && (var.t1 <= t1))
		{
			if ((var.t0 < t0) || (var.t0 > t1))
				return (var.t0);
		}
		else if ((var.t0 >= t0) && (var.t0 <= t1) && (var.t1 >= t0) &&
			(var.t1 <= t1))
			return (0);
		else
			return (0);
	}
	else
		return (intersect_neg_obj2(t0, t1, var));
	return (0);
}

int		intersect_neg_plan2(double t0_neg, double t1_neg, double t0, double *t)
{
	if (t0 < t1_neg || t0 > t0_neg)
	{
		if (t0 > MIN_DIS && t0 < *t)
		{
			*t = t0;
			return (1);
		}
	}
	else
		return (0);
	return (0);
}

int		intersect_neg_plan(double t0_neg, double t1_neg, double t0, double *t)
{
	if (t0_neg < t1_neg)
	{
		if (t0 < t0_neg || t0 > t1_neg)
		{
			if (t0 > MIN_DIS && t0 < *t)
			{
				*t = t0;
				return (1);
			}
		}
		else
			return (0);
	}
	else
		intersect_neg_plan2(t0_neg, t1_neg, t0, t);
	return (0);
}
