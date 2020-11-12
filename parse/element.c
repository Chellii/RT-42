/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:16:02 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 18:59:22 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_xml_tag	*get_val(t_xml_tag *parent, const char *except)
{
	t_xml_tag	*tag;

	if (!parent->nodes)
	{
		ft_printf(INVALID_VAL, except, parent->line, parent->col);
		return (NULL);
	}
	tag = parent->nodes->content;
	if (parent->nodes->next || !tag->value)
	{
		ft_printf(INVALID_VAL, except, tag->line, tag->col);
		return (NULL);
	}
	return (tag);
}

bool		rt_valid_vec(t_xml_tag *t)
{
	static const char	*s[] = {"x", "y", "z", NULL};
	t_list				*nodes;
	t_xml_tag			*tmp;
	t_xml_tag			*tm;
	int					i;

	nodes = t->nodes;
	i = -1;
	while ((++i || 1) && nodes)
	{
		tmp = nodes->content;
		if (i == 3)
			return (ft_printf(ADDITIONAL_TAG, tmp->line, tmp->col) * 0);
		if (!ft_strequ(s[i], tmp->name))
			return (ft_printf(TAG_EXCEPT_FOUND, s[i], tmp->name,
													tmp->line, tmp->col) * 0);
			if (!(tm = get_val(tmp, "double")))
			return (0);
		if (!ft_isdouble(tm->value))
			return (ft_printf(INVALID_VAL, "double", tm->line, tm->col) * 0);
		nodes = nodes->next;
	}
	if (i < 3)
		return (ft_printf(TAG_NOTFOUND_AT, s[i], t->name, t->line, t->col) * 0);
	return (1);
}

bool		rt_valid_enum(t_xml_tag *tag, const char *enums)
{
	char		**tab;
	bool		is_in_arr;
	t_xml_tag	*tmp;

	if (!(tmp = get_val(tag, enums)))
		return (0);
	tab = ft_strsplit(enums, ", ");
	is_in_arr = ft_str_in_arr(tmp->value, tab);
	ft_free_2d_tab(tab);
	if (!is_in_arr)
		ft_printf(INVALID_VAL, enums, tmp->line, tmp->col);
	return (is_in_arr);
}

bool		rt_valid_cut_exist(t_xml_tag *tag)
{
	t_list		*nodes;
	t_xml_tag	*tmp;
	int			i;

	nodes = tag->nodes;
	i = 0;
	while (nodes)
	{
		tmp = nodes->content;
		if (i == 2)
			return (ft_printf(ADDITIONAL_TAG, tmp->line, tmp->col) * 0);
		if (!ft_strequ("limit_xyz", tmp->name))
			return (ft_printf(TAG_EXCEPT_FOUND, "limit_xyz", tmp->name,
													tmp->line, tmp->col) * 0);
			if (!rt_valid_vec(tmp))
			return (0);
		nodes = nodes->next;
		i++;
	}
	if (i < 2)
		return (ft_printf(TAG_NOTFOUND_AT, "limit_xyz",
										tag->name, tag->line, tag->col) * 0);
		return (1);
}

bool		rt_valid_number(t_xml_tag *tag, char *type)
{
	if (!(tag = get_val(tag, type)))
		return (0);
	if (ft_strequ(type, "double"))
	{
		if (!ft_isdouble(tag->value))
			return (ft_printf(INVALID_VAL, "test2", tag->line, tag->col) * 0);
	}
	else if (*tag->value == '-' || !ft_isnbr(tag->value))
		return (ft_printf(INVALID_VAL, type, tag->line, tag->col) * 0);
	return (1);
}
