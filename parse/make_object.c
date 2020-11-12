/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:14:00 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:12:09 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_vector	divise_color(t_vector color)
{
	color.x /= 255.;
	color.y /= 255.;
	color.z /= 255.;
	return (color);
}

t_list		*make_material(t_obj *obj, char *name, t_list *node)
{
	if (ft_strequ("diffuse", name))
		obj->material.diffuse = make_enum(&node);
	if (ft_strequ("specular", name))
		obj->material.specular = make_enum(&node);
	if (ft_strequ("reflection", name))
		obj->material.reflection = make_double(&node);
	if (ft_strequ("refraction", name))
		obj->material.refraction = make_double(&node);
	if (ft_strequ("texture", name))
	{
		obj->material.texture_exist = 1;
		obj->material.type = make_enum(&node);
	}
	return (node);
}

t_list		*make_vectors(t_obj *obj, char *name, t_list *node)
{
	if (ft_strequ("cut_exist", name))
		make_cut_exist(&node, obj);
	else if (ft_strequ("position", name))
		obj->pos = make_vector(&node);
	else if (ft_strequ("rotation", name))
	{
		obj->rot = make_vector(&node);
		if (obj->rot.x == 0 || obj->rot.y == 0 || obj->rot.z == 0)
			rotation(&obj->axis, obj->rot);
	}
	else if (ft_strequ("translation", name))
	{
		obj->trans = make_vector(&node);
		if (obj->trans.x != 0 && obj->trans.y != 0 && obj->trans.z != 0)
			translation(&obj->axis, obj->trans);
	}
	else if (ft_strequ("color", name))
		obj->color = divise_color(make_vector(&node));
	else if (ft_strequ("axis", name))
		obj->axis = make_vector(&node);
	else if (ft_strequ(VAL1, name) && ((obj->v1 = make_vector(&node)).x || 1))
		obj->v3 = obj->v1;
	else if (ft_strequ(VAL2, name) && ((obj->v2 = make_vector(&node)).x || 1))
		obj->v4 = obj->v2;
	return (node);
}

t_list		*make_doubles(t_obj *obj, char *name, t_list *node)
{
	if (ft_strequ("radius", name))
		obj->radius = make_double(&node);
	else if (ft_strequ("radius1", name))
		obj->radius1 = make_double(&node);
	else if (ft_strequ("angle", name))
		obj->angle = make_double(&node);
	else if (ft_strequ("cut_limit", name))
		obj->cut_cyl = make_double(&node);
	else if (ft_strequ("value_of_w", name))
		obj->w = make_double(&node);
	else if (ft_strequ("value_of_h", name))
		obj->h = make_double(&node);
	else if (ft_str_in_arr(name, (char*[]){"sphere_negatif", "cyl_negatif", 0}))
		obj->negative = make_enum(&node);
	else if (ft_strequ("cut_limit1", name))
		obj->cut_var_cone1 = make_double(&node);
	else if (ft_strequ("cut_limit2", name))
		obj->cut_var_cone2 = make_double(&node);
	return (node);
}

t_obj		*make_object(t_xml_tag *tag)
{
	t_list				*nodes;
	t_obj				*obj;
	static const char	*tab[] = {"sphere", "plane", "cylinder", "cone", "disk",
	"triangle", "square", "paraboloid", "hyperboloid", "cube", "torus", NULL};
	int					type;

	nodes = tag->nodes;
	obj = ft_memalloc(sizeof(t_obj));
	type = 0;
	while (!ft_strequ(tab[type], tag->name))
		type++;
	obj->type = type;
	while (nodes)
	{
		tag = nodes->content;
		nodes = make_doubles(obj, tag->name, nodes);
		if (nodes)
			nodes = make_vectors(obj, tag->name, nodes);
		if (nodes)
			nodes = make_material(obj, tag->name, nodes);
	}
	return (obj);
}
