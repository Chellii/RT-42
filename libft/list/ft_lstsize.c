/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:14:23 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:23:42 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *begin, int all)
{
	int	i;

	i = 0;
	while (begin)
	{
		i += (begin->content != NULL || all);
		begin = begin->next;
	}
	return (i);
}
