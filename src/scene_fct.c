/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:19:46 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 05:38:56 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	scene_alias(t_all *all, int i, int j)
{
	int			k;
	t_ray		r;
	t_vector	color;

	k = 0;
	color = (t_vector){0.0, 0.0, 0.0};
	while (k < 80)
	{
		r = get_ray((double)(j + rand_double()) / (double)(WIN_WIDTH),
			(double)(i + rand_double()) /
			(double)(WIN_HEIGHT - 100), &all->cam);
		r.i = i;
		r.j = j;
		color = vector_add(color, shade(all, r, 0));
		k++;
	}
	color = vector_scale(color, (1. / 80.));
	return (color);
}

t_vector	scene_normal(t_all *all, int i, int j)
{
	t_ray		r;
	t_vector	color;
	int			indirect;

	indirect = 0;
	color = (t_vector){0.0, 0.0, 0.0};
	r = get_ray((double)j / (double)WIN_WIDTH, (double)i /
		(double)(WIN_HEIGHT - 100), &(all->cam));
	r.i = i;
	r.j = j;
	if (all->scene.indirect == 1.0)
	{
		while (indirect < 200)
		{
			color = vector_add(color,
				vector_scale(shade(all, r, 0), (1. / 200.)));
			indirect++;
		}
	}
	else
		color = shade(all, r, 0);
	return (color);
}

void		fill_dof(t_dof *dof, t_all *all, t_ray r)
{
	dof->dx_aperture = (rand() / (double)RAND_MAX - 0.5) * 2.0;
	dof->dy_aperture = (rand() / (double)RAND_MAX - 0.5) * 2.0;
	dof->destination = vector_add(all->cam.origin,
		vector_scale(r.dir, dof->focus_dist));
	dof->new_origin = vector_add(all->cam.origin, (t_vector){dof->dx_aperture,
		dof->dy_aperture, 0.0});
}

t_vector	scene_dof(t_all *all, int i, int j)
{
	t_ray		r;
	t_vector	color;
	t_dof		dof;

	color = (t_vector){0.0, 0.0, 0.0};
	dof.s = 0;
	dof.focus_dist = 5.0;
	while (dof.s < 100)
	{
		r = get_ray((double)j / (double)(WIN_WIDTH), (double)i /
				(double)(WIN_HEIGHT - 100), &all->cam);
		r.i = i;
		r.j = j;
		fill_dof(&dof, all, r);
		r.start = dof.new_origin;
		r.dir = vector_normalize(vector_sub(dof.destination, dof.new_origin));
		color = vector_add(color, vector_scale(shade(all, r, 0),
			(1. / 100.)));
		dof.s++;
	}
	return (color);
}

t_vector	call_scene(t_all *all, int i, int j)
{
	t_vector color;

	color = (t_vector){0.0, 0.0, 0.0};
	if (all->scene.scene_type == 1)
		color = scene_alias(all, i, j);
	else if (all->scene.scene_type == 0)
		color = scene_normal(all, i, j);
	else if (all->scene.scene_type == 2)
		color = scene_dof(all, i, j);
	return (color);
}
