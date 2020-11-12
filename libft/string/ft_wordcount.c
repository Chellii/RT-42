/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:23:21 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/01/18 04:21:23 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *s, char *cmp)
{
	int	size;

	size = 0;
	if (s)
	{
		s = ft_skip_chars(s, cmp, NULL);
		while (*s)
		{
			size++;
			s = ft_skip_unitl_char(s, cmp, NULL);
			s = ft_skip_chars(s, cmp, NULL);
		}
	}
	return (size);
}
