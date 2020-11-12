/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 00:20:42 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:56:18 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	if (dest && src)
	{
		while (src[i] && i < n)
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
			dest[i++] = 0;
	}
	return (dest);
}
