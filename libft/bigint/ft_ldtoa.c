/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 22:35:17 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 20:20:35 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

static t_bigint	round_double(t_bigint nb, int comma, int prcs)
{
	t_bigint	round;
	int			r;

	bi_assing(&round, 5);
	if (comma - prcs > 0 && nb.nb[LEN - (comma - prcs)] >= '5')
	{
		bi_move(&round, comma - prcs - 1);
		if (nb.nb[LEN - (comma - prcs)] == '5')
		{
			r = 1;
			while ((comma - prcs - r) > 1 &&
					nb.nb[LEN - (comma - prcs - r)] == '0')
				r++;
			if (nb.nb[LEN - (comma - prcs - r)] > '0')
				nb = ar_op(nb, '+', round);
			else if ((r = (nb.nb[LEN - ((comma - prcs) + 1)] - '0') % 2))
				nb = ar_op(nb, '+', round);
		}
		else
			nb = ar_op(nb, '+', round);
	}
	return (nb);
}

static char		*under_0(t_bigint nb, int comma, int sign, int prcs)
{
	int		len;
	int		i;
	int		j;
	char	*s;

	nb = round_double(nb, comma, prcs);
	len = 1 + prcs + sign + !!prcs;
	if (!(s = ft_strnew(len)))
		return (NULL);
	ft_memset(s, '0', len);
	s[0] = '-';
	s[sign] = '0';
	if (len > 1)
		s[sign + 1] = '.';
	j = 0;
	i = comma - nb.len + sign + 2;
	while (i < len && (nb.len - j) > 0)
	{
		s[i] = nb.nb[LEN - (nb.len - j)];
		i++;
		j++;
	}
	return (s);
}

static char		*over_0(t_bigint nb, int comma, int sign, int prcs)
{
	int		len;
	char	*s;
	int		i;

	nb = round_double(nb, comma, prcs);
	len = nb.len + sign + prcs + !!prcs - comma;
	if (!(s = ft_strnew(len)))
		return (NULL);
	ft_memset(s, '0', len);
	s[0] = '-';
	i = sign;
	while (i < len && nb.len > 0)
	{
		s[i++] = nb.nb[LEN - nb.len--];
		if (nb.len - comma == 0 && prcs > 0)
			s[i++] = '.';
	}
	return (s);
}

static t_bigint	get_mantissa(t_double_sem sem)
{
	t_bigint		mantissa;
	t_bigint		zero;
	t_bigint		free;
	long long int	m;
	int				i;

	bi_assing(&zero, 0);
	bi_assing(&mantissa, sem.s.p);
	bi_assing(&free, 5);
	m = sem.s.mantissa;
	m = ft_reverse_bits(m, 63);
	i = 0;
	while (m)
	{
		i++;
		bi_move(&mantissa, 1);
		mantissa = ar_op(mantissa, '+', m & 1 ? ft_bipow(free, i) : zero);
		m >>= 1;
	}
	return (mantissa);
}

char			*ft_ldtoa(long double n, int prcs)
{
	t_double_sem	sem;
	t_bigint		mantissa;
	t_bigint		e;
	int				pow;

	sem.d = n;
	if (sem.s.exp == 32767 || (!sem.s.mantissa && !sem.s.exp))
		return (special_case(sem, prcs));
	pow = sem.s.exp + !sem.s.exp;
	mantissa = get_mantissa(sem);
	bi_assing(&e, (pow -= 16383) < 0 ? 5 : 2);
	e = ft_bipow(e, ft_abs(pow));
	e = ar_op(e, '*', mantissa);
	if (pow >= 0)
		return (over_0(e, mantissa.len - sem.s.p, sem.s.sign, prcs));
	else
		return (under_0(e, mantissa.len - sem.s.p - pow, sem.s.sign, prcs));
}
