/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:29:03 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:01:05 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	make_camera(t_all *all, t_xml_tag *tag)
{
	t_list	*nodes;

	nodes = tag->nodes;
	all->cam.lookfrom = make_vector(&nodes);
	all->cam.lookfrom.z += +1e-6;
	all->cam.lookat = make_vector(&nodes);
	all->cam.vfov = 60.0;
	all->cam.aspect = (double)WIN_WIDTH / (double)(WIN_HEIGHT - 100);
	all->cam.theta = all->cam.vfov * MPI / 180.0;
	all->cam.half_height = tan(all->cam.theta / 2);
	all->cam.half_width = all->cam.aspect * all->cam.half_height;
	all->cam.lookup.y = 1.0;
	all->scene.scene_type = make_enum(&nodes);
	if (ft_strequ("indirect_light", ((t_xml_tag *)nodes->content)->name))
		all->scene.indirect = make_enum(&nodes);
	all->scene.choices = make_enum(&nodes);
	if (nodes && ft_strequ("filter", ((t_xml_tag *)nodes->content)->name))
		all->scene.filter = make_enum(&nodes);
}

t_light	*make_light(t_list **nodes)
{
	t_light		*light;
	t_light		*head;
	t_light		*tail;
	t_xml_tag	*tag;
	t_list		*tag_nodes;

	tag = (*nodes)->content;
	head = NULL;
	while (ft_strequ("light", tag->name))
	{
		tag_nodes = tag->nodes;
		light = ft_memalloc(sizeof(t_light));
		light->pos = make_vector(&tag_nodes);
		light->color = divise_color(make_vector(&tag_nodes));
		if (ft_strequ("type", ((t_xml_tag *)tag_nodes->content)->name))
			light->spot_light = make_double(&tag_nodes);
		light->intensity = make_vector(&tag_nodes);
		light->amb_intens = make_double(&tag_nodes);
		head == NULL ? (tail = light) : 0;
		head == NULL ? (head = light) :
										(tail->next = light);
		*nodes = (*nodes)->next;
		tag = (*nodes)->content;
	}
	return (head);
}

t_all	*make_all(t_xml_tag *tag)
{
	t_all	*all;
	t_list	*nodes;
	t_obj	*obj;

	nodes = tag->nodes;
	all = ft_memalloc(sizeof(t_all));
	make_camera(all, nodes->content);
	nodes = nodes->next;
	all->lights = make_light(&nodes);
	all->obj = make_object(nodes->content);
	nodes = nodes->next;
	obj = all->obj;
	while (nodes)
	{
		obj->next = make_object(nodes->content);
		obj = obj->next;
		nodes = nodes->next;
	}
	return (all);
}

t_all	*read_make_obj(char *file)
{
	int				fd;
	t_xml_tag		*root;
	t_all			*all;
	t_hash_table	*rules;

	if ((fd = open(file, O_RDONLY)) > 0)
	{
		root = xml_modeling(read_and_tokenizexml(fd));
		if (root)
		{
			rules = get_rules(make_file_indicator());
			if (valide_tags(root, rules))
			{
				all = make_all(root);
				free_xml_dom((void **)&root);
				free_hash_table(&rules, free_rule);
				return (all);
			}
		}
	}
	return (NULL);
}
