/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:11:02 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/19 22:18:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int				i;
	int				j;
	const size_t	len = ft_strlen(to_find);

	if (!*to_find)
		return ((char *)str);
	i = -1;
	while (str[++i] && n - i >= (size_t)len)
	{
		if (str[i] == to_find[0] && (j = 1))
		{
			while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
				j++;
			if (!to_find[j])
				return ((char *)str + i);
		}
	}
	return (0);
}
