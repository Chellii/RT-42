/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aritmitic_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:35:19 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/05/31 14:04:20 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bigint.h"

static t_bigint	addition(t_bigint op1, t_bigint op2)
{
	const int	len = op1.len > op2.len ? op1.len : op2.len;
	int			i;
	int			r;

	i = 0;
	r = 0;
	if (op2.sign == op1.sign)
	{
		while (++i <= len)
		{
			r += (op2.nb[LEN - i] - '0') + (op1.nb[LEN - i] - '0');
			op1.nb[LEN - i] = r % 10 + '0';
			r /= 10;
		}
		op1.nb[LEN - i] = r + '0';
		op1.len = len + !!r;
	}
	else
		op1 = ar_op(op1, '-', op2);
	return (op1);
}

static t_bigint	substraction(t_bigint op1, t_bigint op2)
{
	int				i;
	int				r;
	int				c;
	t_bigint		op3;

	op3 = cn_op(op1, "<", op2) ? op1 : op2;
	op1 = cn_op(op1, "<", op2) ? op2 : op1;
	i = 0;
	r = 0;
	c = 0;
	if (op3.sign == op1.sign && !op3.sign)
		while (++i <= op1.len)
		{
			r += (op1.nb[LEN - i] - '0') - (op3.nb[LEN - i] - '0') - !!c;
			c = r < 0 ? 10 : 0;
			r += c;
			op1.nb[LEN - i] = r % 10 + '0';
			r /= 10;
		}
	else
		op1 = ar_op(op1, '+', op3);
	return (op1);
}

static t_bigint	multiplication(t_bigint op1, t_bigint op2, int i, int j)
{
	t_multpvariable	v;

	v.sign = cn_op(op1, ">", op2) ? op1.sign : op2.sign;
	i = 0;
	bi_assing(&v.ret, 0);
	while (++i <= op2.len)
	{
		j = 0;
		v.r = 0;
		bi_assing(&v.m, 0);
		while (++j <= op1.len && (op2.nb[LEN - i] - '0'))
		{
			v.r += (op1.nb[LEN - j] - '0') * (op2.nb[LEN - i] - '0');
			v.m.nb[LEN - j] = v.r % 10 + '0';
			v.m.len++;
			v.r /= 10;
		}
		v.m.nb[LEN - j] = v.r + '0';
		v.m.len += !!v.r;
		bi_move(&v.m, i - 1);
		v.ret = addition(v.ret, v.m);
	}
	v.ret.sign = op1.sign != op2.sign;
	return (v.ret);
}

static t_bigint	division(t_bigint op1, t_bigint op2)
{
	t_bigint	m;
	t_bigint	ret;
	t_bigint	var;
	int			len;

	len = (op1.len + 1) - op2.len;
	bi_assing(&ret, 0);
	while (--len >= 0)
	{
		bi_assing(&m, 1);
		bi_move(&m, len);
		while (1)
		{
			ret = ar_op(ret, '+', m);
			if (cn_op((var = ar_op(op2, '*', ret)), "=", op1))
				return (ret);
			else if (cn_op(var, ">", op1))
				break ;
		}
		ret = ar_op(ret, '-', m);
	}
	ret.sign = op1.sign != op2.sign;
	return (ret);
}

t_bigint		ar_op(t_bigint op1, char c, t_bigint op2)
{
	if (c == '+')
		return (addition(op1, op2));
	if (c == '-')
		return (substraction(op1, op2));
	if (c == '*')
		return (multiplication(op1, op2, 0, 0));
	if (c == '/')
		return (division(op1, op2));
	if (c == '%')
		return (ar_op(op1, '-',
					multiplication(op2, ar_op(op1, '/', op2), 0, 0)));
		return (op1);
}
