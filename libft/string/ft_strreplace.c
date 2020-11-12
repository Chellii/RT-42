/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 02:08:30 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/07/31 15:43:06 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char find, char replace)
{
	if (str && (str = ft_strchr(str, find)))
		*str++ = replace;
	return (str);
}

void	ft_strreplaceall(char *str, char find, char replace)
{
	while (str && *str)
	{
		if (*str == find)
			*str = replace;
		str++;
	}
}
