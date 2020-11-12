/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:50:36 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:17:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct		s_flg
{
	bool	sharp;
	bool	zero;
	bool	bar;
	bool	pls;
	bool	spc;
	int		size;
	size_t	prcs;
	bool	dprcs;
	char	arg;
	char	cvrs;
	size_t	start_len;
	size_t	zero_len;
	size_t	pfx;
	size_t	sign;
	bool	up;
	bool	is_zero;
	bool	is_p;
	bool	is_nbr;
	bool	is_inf;
	bool	is_nan;
	int		w;
}					t_flg;

int					ft_printf(const char *restrict fmt, ...);
int					dispatcher(va_list ap, t_flg *flg);
int					set_options(char *s, t_flg *flg);
const char			*set_color (const char *str);
const char			*get_options
					(const char *str, t_flg *flg, va_list ap, va_list ap2);
char				*set_flags(char *s, t_flg *flg);
long long			ft_va_arg(va_list ap, char type);
unsigned long long	ft_uva_arg(va_list ap, char type);
long double			ft_fva_arg(va_list ap, char type);
const char			*get_dollar(const char *s, va_list ap, va_list ap2);
const char			*get_flags(const char *s, t_flg *flg);
const char			*get_size(const char *s, t_flg *flg, va_list ap);
const char			*get_precision(const char *s, t_flg *flg, va_list ap);

#endif
