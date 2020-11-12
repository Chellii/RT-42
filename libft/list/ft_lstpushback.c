/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 03:52:13 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 14:30:51 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushback(t_list **blst, void const *content,
															size_t content_size)
{
	t_list	*list;

	if (!blst || !content_size)
		return (NULL);
	list = *blst;
	if (list)
	{
		while (list && list->next)
			list = list->next;
		list->next = ft_lstnew(content, content_size);
		return (list->next);
	}
	else
	{
		*blst = ft_lstnew(content, content_size);
		return (*blst);
	}
}
