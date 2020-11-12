/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_chrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 00:23:31 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/24 01:24:13 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skip_chrs(const char *str, const char *compare)
{
	while (str && ft_isinstr(compare, *str))
		str++;
	return (str);
}

char	*ft_rskip_chrs(const char *str, const char *compare, int i)
{
	while (i >= 0 && ft_isinstr(compare, str[i]))
		i--;
	return (&str[i]);
}
