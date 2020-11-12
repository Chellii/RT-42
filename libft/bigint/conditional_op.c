/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:35:23 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/09/15 21:32:48 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bigint.h"

void		bi_assing(t_bigint *op, long long nb)
{
	int	len;
	int	i;

	i = 0;
	op->nb[LEN] = 0;
	ft_memset(op->nb, '0', LEN);
	op->sign = nb < 0;
	len = nb == 0 ? 0 : ft_declen(nb);
	op->len = len;
	while (len--)
	{
		op->nb[LEN - ++i] = nb % 10 + '0';
		nb /= 10;
	}
}

void		bi_move(t_bigint *nb, unsigned int i)
{
	int	len;

	len = nb->len;
	nb->len += i;
	while (len && i)
	{
		nb->nb[LEN - (len + i)] = nb->nb[LEN - len];
		nb->nb[LEN - len] = '0';
		len--;
	}
}

static int	equal_greater_less(t_bigint op1, t_bigint op2)
{
	int		len;
	bool	sign;

	len = op1.len;
	sign = op1.sign == op2.sign;
	if (sign && op1.len == op2.len)
	{
		while (len--)
			if (op2.nb[LEN - len - 1] != op1.nb[LEN - len - 1])
				return (op1.nb[LEN - len - 1] > op2.nb[LEN - len - 1] ? 1 : -1);
		return (0);
	}
	return ((!sign && !op1.sign) || op1.len > op2.len ? 1 : -1);
}

bool		cn_op(t_bigint op1, char *s, t_bigint op2)
{
	int	r;

	r = equal_greater_less(op1, op2);
	if (*s == '=')
		return (r == 0);
	if (*s == '>')
		return (r == 1);
	if ('<' == *s)
		return (r == -1);
	if (s[0] == '>' && s[1] == '=')
		return (r != -1);
	if (s[0] == '<' && s[1] == '=')
		return (r != 1);
	return (false);
}
