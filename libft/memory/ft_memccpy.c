/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:04:51 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/19 22:18:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*sc;
	unsigned char	*des;
	size_t			i;

	i = 0;
	sc = (unsigned char *)src;
	des = (unsigned char *)dest;
	while (i < n)
	{
		des[i] = sc[i];
		if (sc[i++] == (unsigned char)c)
			return ((void *)(des + i));
	}
	return (0);
}
