/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 00:23:31 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:54:11 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	empty(int n)
{
	(void)n;
	return (0);
}

char		*ft_skip_chars(const char *str, const char *compare, int (*f)(int))
{
	if (!f)
		f = empty;
	while (str && *str && (ft_isinstr(*str, compare) || f(*str)))
		str++;
	return ((char *)str);
}

char		*ft_rskip_chars(const char *str, const char *cmp,
														int (*f)(int), int i)
{
	if (!f)
		f = empty;
	while (i >= 0 && (ft_isinstr(str[i], cmp) || f(str[i])))
		i--;
	if (i == -1)
		i = 0;
	return ((char *)(str + i));
}
