/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:15:35 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 20:20:50 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	declen_base(long long n, int base)
{
	int len;

	len = 1;
	while ((n = n / base))
		len++;
	return (len);
}

char		*ft_itoa_base(long long n, int base)
{
	const char	*b;
	int			len;
	char		*res;
	bool		sign;

	b = "0123456789abcdef";
	sign = n < 0 && base == 10 ? 1 : 0;
	len = declen_base(n, base);
	res = ft_strnew(len + sign);
	if (!res)
		return (NULL);
	res[0] = '-';
	while (len--)
	{
		res[len + sign] = b[ft_abs(n % base)];
		n /= base;
	}
	return (res);
}
