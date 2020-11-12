/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:55:05 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/19 22:18:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_lenm(int s, long m, int i, int c)
{
	while (m * 10 <= s)
	{
		m *= 10;
		i++;
	}
	while (c++ < (i + 1) / 2)
		m /= 10;
	i = m;
	return (m);
}

int			ft_sqrt(int s)
{
	int			m;
	long	int i;

	m = int_lenm(s, 1, 0, 0);
	i = m;
	while (i * i != s && m > 0)
	{
		if (i * i > s)
		{
			i -= m;
			m /= 10;
		}
		else
			i += m;
	}
	if (m < 1)
		return (0);
	return (i);
}
