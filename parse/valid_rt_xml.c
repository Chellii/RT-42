/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_rt_xml.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:43:50 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:21:49 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool		valid_rule_by_type(t_xml_tag *tag, char *type, char *dep)
{
	if (ft_strequ("vec", type))
		return (rt_valid_vec(tag));
	if (ft_strequ("enum", type))
		return (rt_valid_enum(tag, dep));
	if (ft_strequ("cut_exist", type))
		return (rt_valid_cut_exist(tag));
	if (ft_strequ("double", type) || ft_strequ("uint", type))
		return (rt_valid_number(tag, type));
	return (0);
}

t_list		*valid_cam_light_error(t_list *nodes, int i)
{
	t_xml_tag *tag;

	if (i == 0 && !nodes)
	{
		ft_printf(TAG_NOTFOUND, "light");
		return (NULL);
	}
	if (i == 0)
	{
		tag = nodes->content;
		ft_printf(TAG_NOTFOUND_AT, "light", tag->name, tag->line, tag->col);
		return (NULL);
	}
	return (nodes);
}

t_list		*valid_cam_light(t_list *nodes, t_hash_table *rules)
{
	t_tag_rule	*rule;
	int			i;

	i = 0;
	rule = hash_find(rules, "camera");
	if (!valide_rule(nodes->content, rule))
		return (0);
	nodes = nodes->next;
	rule = hash_find(rules, "light");
	while (nodes)
	{
		if (!ft_strequ("light", ((t_xml_tag *)nodes->content)->name))
			break ;
		if (!valide_rule(nodes->content, rule))
			return (0);
		nodes = nodes->next;
		i++;
	}
	return (valid_cam_light_error(nodes, i));
}

bool		valide_tags(t_xml_tag *root, t_hash_table *rules)
{
	t_list		*node;
	t_tag_rule	*rule;

	if (!ft_strequ(root->name, "RT"))
	{
		ft_printf(TAG_EXCEPT_FOUND, "RT", root->name, root->line, root->col);
		return (0);
	}
	if (!(node = valid_cam_light(root->nodes, rules)))
		return (ft_printf("No object found\n") * 0);
	while (node)
	{
		root = node->content;
		if (!(rule = hash_find(rules, root->name)))
			return (ft_printf(INVALID_TAG, root->line, root->col) * 0);
		if (!valide_rule(node->content, rule))
			return (0);
		node = node->next;
	}
	return (1);
}
