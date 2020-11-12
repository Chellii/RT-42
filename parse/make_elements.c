/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:37:22 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:01:28 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_vector	make_vector(t_list **node)
{
	t_vector	ret;
	t_xml_tag	*tag;
	t_list		*val_node;

	tag = (*node)->content;
	val_node = tag->nodes;
	ret.x = make_double(&val_node);
	ret.y = make_double(&val_node);
	ret.z = make_double(&val_node);
	*node = (*node)->next;
	return (ret);
}

int			make_enum(t_list **node)
{
	t_xml_tag	*tag;
	char		*tmp;
	char		**tab;
	int			ret;

	ret = 0;
	tag = (*node)->content;
	if (ft_strequ("scene_type", tag->name))
		tmp = ft_strdup(E_SCENE_TYPE);
	else if (ft_strequ("algo_type", tag->name))
		tmp = ft_strdup(E_ALGO_TYPE);
	else if (ft_strequ("filter", tag->name))
		tmp = ft_strdup(E_FILTER);
	else if (ft_strequ("texture", tag->name))
		tmp = ft_strjoin(E_TEXTURE, E_TEXTURE2);
	else
		tmp = ft_strdup(E_ONE_ZERO);
	tab = ft_strsplit(tmp, ", ");
	free(tmp);
	tmp = get_val(tag, "")->value;
	while (tab[ret] && !ft_strequ(tab[ret], tmp))
		ret++;
	ft_free_2d_tab(tab);
	*node = (*node)->next;
	return (ret);
}

double		make_double(t_list **node)
{
	t_xml_tag	*tag;
	double		ret;

	tag = (*node)->content;
	ret = ft_atof(get_val(tag, "")->value);
	*node = (*node)->next;
	return (ret);
}

void		make_cut_exist(t_list **node, t_obj *obj)
{
	t_xml_tag	*tag;
	t_list		*val_node;

	tag = (*node)->content;
	val_node = tag->nodes;
	obj->cut_xyz = 1;
	obj->limit_xyz1 = make_vector(&val_node);
	obj->limit_xyz2 = make_vector(&val_node);
	*node = (*node)->next;
}
