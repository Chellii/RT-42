/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:41:20 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/02 16:40:51 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;

	i = 0;
	if (s1 && s2 && (fresh = (char *)MALLOC((ft_strlen(s1)
						+ ft_strlen(s2) + 1) * sizeof(char))))
	{
		ft_strcpy(fresh, s1);
		return (ft_strcat(fresh, s2));
	}
	return (0);
}
