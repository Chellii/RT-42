/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_promalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:37:13 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/02 16:43:39 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_promalloc(size_t size)
{
	unsigned char	*r;

	r = malloc(size);
	if (r == NULL)
	{
		ft_printf("malloc error");
		exit(10);
	}
	return (r);
}
