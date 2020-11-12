/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:27:44 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/19 22:18:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	buble_sort(int *t, size_t size, bool asc)
{
	int		i;
	size_t	j;

	i = -1;
	while ((size_t)++i < size - 1)
	{
		j = i;
		while (++j < size)
			if (asc && t[i] > t[j])
				ft_swap(&t[i], &t[j]);
			else if (!asc && t[i] < t[j])
				ft_swap(&t[i], &t[j]);
	}
}
