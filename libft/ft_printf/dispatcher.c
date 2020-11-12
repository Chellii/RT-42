/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:05:02 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:17:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	cvrs_k(va_list ap)
{
	int count;

	count = 0;
	count = ft_printf("%s, ", va_arg(ap, char*));
	count = count + ft_printf("%s ", va_arg(ap, char*)) + 1;
	count = count + ft_printf("%d, ", va_arg(ap, int)) + 2;
	count = count + ft_printf("%.2d:", va_arg(ap, int)) + 1;
	count = count + ft_printf("%.2d", va_arg(ap, int));
	return (count);
}

static int	cvrs_c(va_list ap, t_flg *flg)
{
	char *str;

	str = NULL;
	str = ft_strnew(1);
	*str = va_arg(ap, int);
	!*str && flg->size ? flg->size-- : 0;
	flg->prcs = 0;
	return (set_options(str, flg));
}

static int	cvrs_s(va_list ap, t_flg *flg)
{
	char *str;

	str = NULL;
	str = ft_strdup(va_arg(ap, char*));
	if (!str)
		str = ft_strdup("(null)");
	if (str && !flg->prcs && flg->dprcs)
		str[flg->prcs] = '\0';
	else if (flg->dprcs && flg->prcs < ft_strlen(str))
		str[flg->prcs] = '\0';
	flg->prcs = 0;
	return (set_options(str, flg));
}

int			dispatcher(va_list ap, t_flg *flg)
{
	if (flg->cvrs == 'd')
		return (set_options(ft_itoa(ft_va_arg(ap, flg->arg)), flg));
	else if (flg->cvrs == 'u')
		return (set_options(ft_uitoa(ft_uva_arg(ap, flg->arg)), flg));
	else if (flg->cvrs == 'o')
		return (set_options(ft_uitoa_base(ft_uva_arg(ap, flg->arg), 8), flg));
	else if (flg->cvrs == 'x')
		return (set_options(ft_uitoa_base(ft_uva_arg(ap, flg->arg), 16), flg));
	else if (flg->cvrs == '%')
		return (set_options(ft_strdup("%"), flg));
	else if (flg->cvrs == 'f')
		return (set_options(ft_ldtoa(ft_fva_arg(ap, flg->arg)
						, flg->prcs), flg));
	else if (flg->cvrs == 'b')
		return (set_options(ft_uitoa_base(ft_uva_arg(ap, flg->arg), 2), flg));
	else if (flg->cvrs == 'k')
		return (cvrs_k(ap));
	else if (flg->cvrs == 'c')
		return (cvrs_c(ap, flg));
	else if (flg->cvrs == 's')
		return (cvrs_s(ap, flg));
	return (0);
}
