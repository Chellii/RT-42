/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 22:53:32 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:17:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long			ft_va_arg(va_list ap, char type)
{
	if (type == '\0')
		return (va_arg(ap, int));
	if (type == 'h')
		return ((short)va_arg(ap, int));
	if (type == 'H')
		return ((char)va_arg(ap, int));
	if (ft_isinstr(type, "ljz"))
		return (va_arg(ap, long));
	if (type == 'I')
		return (va_arg(ap, long long));
	return (0);
}

unsigned long long	ft_uva_arg(va_list ap, char type)
{
	if (type == '\0')
		return (va_arg(ap, unsigned int));
	if (type == 'h')
		return ((unsigned short)va_arg(ap, unsigned int));
	if (type == 'H')
		return ((unsigned char)va_arg(ap, unsigned int));
	if (ft_isinstr(type, "ljz"))
		return (va_arg(ap, unsigned long));
	if (type == 'I')
		return (va_arg(ap, unsigned long long));
	return (0);
}

long double			ft_fva_arg(va_list ap, char type)
{
	if (type == '\0' || type == 'l' || type == 'j')
		return (va_arg(ap, double));
	if (type == 'L')
		return (va_arg(ap, long double));
	return (0);
}
