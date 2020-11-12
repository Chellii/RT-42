/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:49:40 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/19 22:20:38 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

char	*special_case(t_double_sem sem, int precs)
{
	char	*s;

	if (sem.s.exp == 0)
	{
		if (!(s = ft_strnew(1 + precs + sem.s.sign + !!precs)))
			return (NULL);
		ft_memset(s, '0', 1 + precs + sem.s.sign + !!precs);
		s[0] = sem.s.sign ? '-' : s[0];
		s[sem.s.sign + 1] = precs ? '.' : s[sem.s.sign + 1];
	}
	else if (sem.s.mantissa)
		s = ft_strdup("nan");
	else
		s = ft_strdup(sem.s.sign ? "-inf" : "inf");
	return (s);
}
