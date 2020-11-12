/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:18:52 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:19:01 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		ft_set_flags(const char *str, _Bool *flags,
								const char *acpt_flgs, void (*f)(char, _Bool*))
{
	if (!str || *str++ != '-' || *str == '-' || !ft_isprint(*str))
		return (0);
	while (*str)
	{
		if (ft_isinstr(*str, acpt_flgs) || (!acpt_flgs && ft_isalnum(*str)))
		{
			flags[(int)*str] = 1;
			if (f)
				f(*str, flags);
		}
		else
			return (-1);
		str++;
	}
	return (1);
}

void		ft_unset_flags(int c, _Bool *flags)
{
	flags[c] = 0;
}

_Bool		ft_flag_active(int c, _Bool *flags)
{
	return (flags[c]);
}
