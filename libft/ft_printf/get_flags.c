/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 23:11:09 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:17:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const char	*get_dollar(const char *s, va_list ap, va_list ap2)
{
	const char	*tmp = s;
	int			i;

	if (!ft_isdigit(*s))
		return (s);
	i = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	if (*s == '$')
	{
		va_copy(ap, ap2);
		while (i-- > 1)
			va_arg(ap, int);
		return (s + 1);
	}
	return (tmp);
}

const char	*get_flags(const char *s, t_flg *flg)
{
	while (ft_isinstr(*s, "#-+ 0"))
	{
		*s == '#' ? flg->sharp = 1 : 0;
		*s == '-' ? flg->bar = 1 : 0;
		*s == '+' ? flg->pls = 1 : 0;
		*s == ' ' ? flg->spc = 1 : 0;
		*s == '0' ? flg->zero = 1 : 0;
		s++;
	}
	return (s);
}

const char	*get_size(const char *s, t_flg *flg, va_list ap)
{
	if (*s == '*')
	{
		flg->size = va_arg(ap, int);
		if (flg->size < 0)
		{
			flg->bar = 1;
			flg->size = -flg->size;
		}
		s++;
	}
	else if (ft_isdigit(*s))
	{
		flg->size = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
	}
	flg->size = flg->size < 0 ? 0 : flg->size;
	return (s);
}

const char	*get_precision(const char *s, t_flg *flg, va_list ap)
{
	int precision;

	precision = 0;
	if (*s == '.')
	{
		s++;
		flg->dprcs = 1;
		if (*s == '*')
		{
			precision = va_arg(ap, int);
			s++;
		}
		else
		{
			precision = ft_atoi(s);
			while (ft_isdigit(*s))
				s++;
		}
	}
	if (precision < 0)
		flg->prcs = flg->dprcs ? 6 : 0;
	else
		flg->prcs = precision;
	return (s);
}
