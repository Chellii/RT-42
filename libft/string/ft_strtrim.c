/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:36:10 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/04 23:25:35 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	st;
	int	len;

	if (!s)
		return (0);
	st = 0;
	len = ft_strlen(s) - 1;
	while (s[st] && (s[st] == '\n' || s[st] == '\t' || s[st] == ' '))
		st++;
	while (st <= len && (s[len] == '\n' || s[len] == '\t' || s[len] == ' '))
		len--;
	return (ft_strsub(s + st, 0, (len - st) + 1));
}
