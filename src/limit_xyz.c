/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_xyz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:02:43 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/02 19:06:33 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_limit_obj(t_ray *r, t_obj *obj, double t)
{
	t_vector ray;

	ray = vector_add(vector_scale(r->dir, t), r->start);
	if (ray.x > 0 && obj->limit_xyz1.x > 0 && ray.x > obj->limit_xyz1.x)
		return (1);
	if (ray.y > 0 && obj->limit_xyz1.y > 0 && ray.y > obj->limit_xyz1.y)
		return (1);
	if (ray.z > 0 && obj->limit_xyz1.z > 0 && ray.z > obj->limit_xyz1.z)
		return (1);
	if (ray.x < 0 && obj->limit_xyz2.x < 0 && ray.x < obj->limit_xyz2.x)
		return (1);
	if (ray.y < 0 && obj->limit_xyz2.y < 0 && ray.y < obj->limit_xyz2.y)
		return (1);
	if (ray.z < 0 && obj->limit_xyz2.z < 0 && ray.z < obj->limit_xyz2.z)
		return (1);
	return (0);
}

int	ft_limit_ray(t_intersect_var var, double *t, t_ray *r, t_obj *obj)
{
	if (var.t0 < var.t1 || var.t1 < MIN_DIS)
	{
		if (var.t0 > MIN_DIS && var.t0 < *t)
		{
			if (ft_limit_obj(r, obj, var.t0))
				return (0);
			*t = var.t0;
			return (1);
		}
	}
	else if (var.t1 < var.t0 || var.t0 < MIN_DIS)
	{
		if (var.t1 > MIN_DIS && var.t1 < *t)
		{
			if (ft_limit_obj(r, obj, var.t1))
				return (0);
			*t = var.t1;
			return (1);
		}
	}
	return (0);
}
