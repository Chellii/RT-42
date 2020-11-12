/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:04:22 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/20 21:14:29 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_max(int *tab, size_t size)
{
	int	max;

	max = size > 0 ? tab[--size] : 0;
	while (size-- > 0)
		if (max < tab[size])
			max = tab[size];
	return (max);
}
