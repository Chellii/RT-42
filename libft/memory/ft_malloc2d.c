/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:13:49 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/02 14:56:49 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_malloc2d(int rows, int size, void *(*alloc)(size_t))
{
	void	**ret;
	int		i;

	i = 0;
	if (!rows || !size || !(ret = alloc(sizeof(void *) * rows)))
		return (NULL);
	while (i < rows)
	{
		if (!(ret[i] = alloc(size)))
		{
			ft_free_2d_tab((char **)ret);
			return (NULL);
		}
		i++;
	}
	return (ret);
}
