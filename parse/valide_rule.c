/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:10:41 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:25:47 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	additional_tag(t_list *node)
{
	t_xml_tag	*tag;

	if (node)
	{
		tag = (t_xml_tag *)node->content;
		return (ft_printf(ADDITIONAL_TAG, tag->line, tag->col) * 0);
	}
	return (1);
}

int		is_identic_tag(t_list *node, t_xml_tag *tag, t_tag_rule *rule, int *i)
{
	if (node == NULL)
	{
		if (rule->rule_tags[*i].optional)
		{
			*i = *i + 1;
			return (2);
		}
		return (ft_printf(TAG_NOTFOUND_AT, rule->rule_tags[*i].name,
										tag->name, tag->line, tag->col) * 0);
	}
	tag = (t_xml_tag *)node->content;
	if (!ft_strequ(tag->name, rule->rule_tags[*i].name))
	{
		if (rule->rule_tags[*i].optional)
		{
			*i = *i + 1;
			return (2);
		}
		return (ft_printf(TAG_EXCEPT_FOUND, rule->rule_tags[*i].name,
										tag->name, tag->line, tag->col) * 0);
	}
	return (1);
}

bool	valide_rule(t_xml_tag *tag, t_tag_rule *rule)
{
	t_list	*node;
	int		i;
	int		valid_tag;

	i = 0;
	if (!ft_strequ(tag->name, rule->name))
		return (ft_printf(TAG_EXCEPT_FOUND, rule->name, tag->name,
													tag->line, tag->col) * 0);
		node = tag->nodes;
	while (rule->rule_tags[i].name)
	{
		valid_tag = is_identic_tag(node, tag, rule, &i);
		if (valid_tag == 2)
			continue;
		if (!valid_tag)
			return (0);
		if (!valid_rule_by_type(node->content, rule->rule_tags[i].type,
														rule->rule_tags[i].dep))
			return (0);
		i++;
		node = node->next;
	}
	return (additional_tag(node));
}
