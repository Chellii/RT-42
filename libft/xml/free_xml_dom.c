/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_xml_dom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:38:21 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:44:14 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml.h"

void	free_xml_dom(void **elm)
{
	t_xml_tag	**tag;

	if (!elm || !*elm)
		return ;
	tag = (t_xml_tag **)elm;
	ft_memdel((void **)&(*tag)->attributes);
	ft_memdel((void **)&(*tag)->name);
	ft_memdel((void **)&(*tag)->value);
	if ((*tag)->nodes)
		ft_lstdel_s(&(*tag)->nodes, free_xml_dom);
	ft_memdel(elm);
	*tag = NULL;
}
