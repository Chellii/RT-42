/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_occurence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:44:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/09/16 19:55:59 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_occurence(char *str, char c)
{
	int i;

	i = 0;
	while (str && *str)
	{
		str = ft_strreplace(str, c, c);
		i += str ? 1 : 0;
	}
	return (i);
}
