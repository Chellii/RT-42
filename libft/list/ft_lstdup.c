/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 06:02:24 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 14:29:59 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list **lst)
{
	t_list	*cur;
	t_list	*dup;
	t_list	**next;

	dup = NULL;
	next = &dup;
	if (lst)
	{
		cur = *lst;
		while (cur)
		{
			*next = ft_lstnew(cur->content, cur->content_size);
			next = *next ? &(*next)->next : next;
			cur = cur->next;
		}
	}
	return (dup);
}
