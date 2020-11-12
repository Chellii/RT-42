/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:08:42 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:21:57 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char **strings, int n)
{
	char	*concat;
	size_t	size;
	int		i;
	int		lenghts[n];

	size = 0;
	i = -1;
	while (++i < n)
	{
		if (!strings[i])
			return (NULL);
		lenghts[i] = ft_strlen(strings[i]);
		size += lenghts[i];
	}
	if ((concat = ft_strnew(size)))
	{
		i = -1;
		size = 0;
		while (++i < n)
		{
			ft_strcat(concat + size, strings[i]);
			size += lenghts[i];
		}
	}
	return (concat);
}
