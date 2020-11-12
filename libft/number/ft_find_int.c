/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 18:17:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/20 21:12:54 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_find_int(int *t, int n, size_t size, size_t *index)
{
	while (size-- > 0)
		if (t[size] == n)
		{
			if (index)
				*index = size;
			return (1);
		}
	return (0);
}
