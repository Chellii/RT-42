/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:15:53 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:17:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	set_flags_1(char *s, t_flg *flg)
{
	if (flg->cvrs == 'f')
	{
		flg->is_inf = (!ft_strcmp(s, "inf") || !ft_strcmp(s, "-inf") ? 1 : 0);
		flg->is_nan = (!ft_strcmp(s, "nan") ? 1 : 0);
	}
	if (flg->is_nan)
	{
		flg->spc = 0;
		flg->pls = 0;
		flg->sharp = 0;
		flg->zero = 0;
		flg->prcs = 0;
	}
	if (flg->is_inf)
	{
		flg->prcs = 0;
		flg->zero = 0;
	}
}

static void	calcul_size(char *s, t_flg *flg)
{
	int size;

	size = ft_max(flg->prcs, ft_strlen(s));
	if (flg->cvrs == 'd' || flg->cvrs == 'f')
		size = (flg->sign || flg->pls || flg->spc ? size + 1 : size);
	flg->sharp && flg->cvrs == 'o' ? size++ : 0;
	if ((flg->sharp && !flg->is_zero && flg->cvrs == 'x') || flg->is_p)
		size = size + 2;
	flg->sharp && flg->cvrs == 'f' && !flg->prcs && !flg->is_inf ? size++ : 0;
	flg->size = ft_max(flg->size, size);
}

char		*set_flags(char *s, t_flg *flg)
{
	set_flags_1(s, flg);
	flg->zero = ((flg->dprcs && flg->cvrs != 'f') || flg->bar ? 0 : flg->zero);
	flg->is_nbr = (ft_isinstr(flg->cvrs, "sc") ? 0 : 1);
	flg->is_zero = (*s == '0' && !*(s + 1) ? 1 : 0);
	flg->sign = (*s == '-' && flg->is_nbr ? 1 : 0);
	if (flg->cvrs == 'o')
	{
		if (flg->is_zero && (flg->prcs >= 1 || !flg->dprcs))
			flg->sharp = 0;
		flg->sharp = (flg->prcs > ft_strlen(s) ? 0 : flg->sharp);
	}
	flg->sharp = (flg->is_p ? 1 : flg->sharp);
	s = s + flg->sign;
	if (flg->is_nbr && flg->is_zero && flg->dprcs && flg->cvrs != 'f')
		*s = '\0';
	flg->start_len = ft_strlen(s);
	calcul_size(s, flg);
	flg->zero_len = ft_max(flg->prcs - flg->start_len, 0);
	return (s);
}
