/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:50:05 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:17:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	initialise_flg(t_flg *flg)
{
	flg->sharp = 0;
	flg->zero = 0;
	flg->bar = 0;
	flg->pls = 0;
	flg->spc = 0;
	flg->size = 0;
	flg->prcs = 0;
	flg->dprcs = 0;
	flg->arg = '\0';
	flg->cvrs = '\0';
	flg->start_len = 0;
	flg->zero_len = 0;
	flg->pfx = 0;
	flg->sign = 0;
	flg->up = 0;
	flg->is_zero = 0;
	flg->is_nbr = 0;
	flg->is_p = 0;
	flg->is_inf = 0;
	flg->is_nan = 0;
}

const char	*get_argument(const char *s, t_flg *flg)
{
	if (*s == 'h')
	{
		flg->arg = (*(s + 1) == 'h' ? 'H' : 'h');
		s = (flg->arg == 'h' ? s + 1 : s + 2);
	}
	else if (*s == 'l')
	{
		flg->arg = (*(s + 1) == 'l' ? 'I' : 'l');
		s = (flg->arg == 'l' ? s + 1 : s + 2);
	}
	else if (ft_isinstr(*s, "LUzj"))
	{
		flg->arg = *s;
		s++;
	}
	return (s);
}

const char	*get_conversion(const char *s, t_flg *flg)
{
	if (ft_isinstr(*s, "FfdiouXxcsp%bk"))
	{
		if (*s == 'X' || *s == 'F')
		{
			flg->cvrs = (*s == 'X' ? 'x' : 'f');
			flg->up = 1;
		}
		else if (*s == 'p')
		{
			flg->sharp = '#';
			flg->arg = 'l';
			flg->cvrs = 'x';
			flg->is_p = 1;
		}
		else
			flg->cvrs = (*s == 'i' ? 'd' : *s);
		(*s == 'f' || *s == 'F') && !flg->dprcs ? flg->prcs = 6 : 0;
		s++;
	}
	return (s);
}

const char	*get_fd(const char *s, t_flg *flg, va_list ap)
{
	if (*s == 'w')
	{
		flg->w = va_arg(ap, int);
		flg->cvrs = 'w';
		s++;
	}
	return (s);
}

const char	*get_options(const char *s, t_flg *flg, va_list ap, va_list ap2)
{
	initialise_flg(flg);
	while (!flg->cvrs && *s && (ft_isinstr(*s, "FfdiouXxcsp%bkhlLzjUw$#*+- .")
				|| ft_isdigit(*s)))
	{
		s = get_fd(s, flg, ap);
		if (flg->cvrs == 'w')
			break ;
		s = get_dollar(s, ap, ap2);
		s = get_flags(s, flg);
		s = get_size(s, flg, ap);
		s = get_precision(s, flg, ap);
		s = get_argument(s, flg);
		s = get_conversion(s, flg);
	}
	return (s);
}
