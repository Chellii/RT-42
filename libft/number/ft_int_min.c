/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:56:52 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/20 21:15:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_min(int *tab, size_t size)
{
	int	min;

	min = size > 0 ? tab[--size] : 0;
	while (size-- > 0)
		if (min > tab[size])
			min = tab[size];
	return (min);
}
