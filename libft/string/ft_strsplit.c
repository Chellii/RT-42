/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:03:34 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 20:34:15 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char *cmp)
{
	int		size;
	int		i;
	char	**tab2d;

	i = 0;
	size = ft_wordcount(s, cmp);
	if (!size || !(tab2d = (char **)ft_memalloc((size + 1) * sizeof(char *))))
		return (0);
	while (size--)
	{
		s = ft_skip_chars(s, cmp, NULL);
		tab2d[i + 1] = (char *)ft_skip_unitl_char(s, cmp, NULL);
		if (!(tab2d[i] = ft_strsub(s, 0, tab2d[i + 1] - s)))
		{
			ft_free_2d_tab(tab2d);
			return (NULL);
		}
		s = tab2d[i + 1];
		i++;
	}
	tab2d[i] = 0;
	return (tab2d);
}
