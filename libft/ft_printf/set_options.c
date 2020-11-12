/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:45:14 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:17:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	set_prefix(char *str, t_flg *flg)
{
	if (flg->cvrs == 'd' || flg->cvrs == 'f')
	{
		flg->spc ? *str = ' ' : 0;
		flg->pls ? *str = '+' : 0;
		flg->sign ? *str = '-' : 0;
		flg->sign || flg->pls || flg->spc ? flg->pfx = 1 : 0;
	}
	if (flg->sharp && flg->cvrs == 'f' && !flg->prcs && !flg->is_inf)
	{
		str[flg->pfx + flg->zero_len + flg->start_len] = '.';
		flg->start_len++;
	}
	else if ((flg->sharp && flg->cvrs == 'x' && !flg->is_zero) || flg->is_p)
	{
		*str = '0';
		*(str + 1) = 'x';
		flg->pfx = 2;
	}
	else if (flg->sharp && flg->cvrs == 'o')
	{
		*str = '0';
		flg->pfx = 1;
	}
}

static char	*set_flag_bar(char *str, int final_len, t_flg *flg)
{
	if (!flg->bar)
	{
		if (flg->pfx == 2 && flg->zero)
			ft_memmove(str + flg->size - final_len + 2, str + 2, final_len - 2);
		else
			ft_memmove(str + flg->size - final_len, str, final_len);
		if (flg->zero)
			ft_memset(str + flg->pfx, '0', flg->size - final_len);
		else
			ft_memset(str, ' ', flg->size - final_len);
	}
	return (str);
}

int			set_options(char *s, t_flg *flg)
{
	char	*str;
	size_t	final_len;
	int		ret;

	s = set_flags(s, flg);
	if (!s && !flg->is_nbr)
		exit(1);
	if ((str = ft_strnew(flg->size)) == NULL)
		exit(0);
	ft_memset(str, ' ', flg->size);
	set_prefix(str, flg);
	ft_memset(str + flg->pfx, '0', flg->zero_len);
	ft_memmove(str + flg->pfx + flg->zero_len, s, ft_strlen(s));
	final_len = flg->pfx + flg->zero_len + flg->start_len;
	str = set_flag_bar(str, final_len, flg);
	ret = !*s && flg->cvrs == 'c' ? flg->size + 1 : flg->size;
	if (flg->cvrs == 'c' && !*s && flg->bar)
		ft_putchar_fd(0, flg->w);
	ft_putstr_fd(flg->up ? ft_strtoupper(str) : str, flg->w);
	if (flg->cvrs == 'c' && !*s && !flg->bar)
		ft_putchar_fd(0, flg->w);
	free(s - flg->sign);
	free(str);
	return (ret);
}
