/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_until_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:19:58 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:54:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	empty(int n)
{
	(void)n;
	return (0);
}

char		*ft_skip_unitl_char(const char *str, const char *compare,
																int (*f)(int))
{
	if (!f)
		f = empty;
	while (str && *str && !ft_isinstr(*str, compare) && !f(*str))
		str++;
	return ((char *)str);
}

char		*ft_rskip_unitl_char(const char *str, const char *compare,
														int (*f)(int), int i)
{
	if (!f)
		f = empty;
	while (str && i >= 0 && !ft_isinstr(str[i], compare) && !f(str[i]))
		i--;
	if (i == -1)
		i = 0;
	return ((char *)(str + i));
}
