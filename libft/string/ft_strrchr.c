/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:14:21 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 14:26:50 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (len--)
	{
		if (str[len] == c)
			return ((char *)(str + len));
	}
	return (NULL);
}
