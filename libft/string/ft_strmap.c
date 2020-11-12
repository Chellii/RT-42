/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:04:10 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/02 16:41:02 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*fresh;
	int		i;

	if (!s || !f)
		return (0);
	i = -1;
	len = ft_strlen(s);
	if (!(fresh = (char *)MALLOC((len + 1) * sizeof(char))))
		return (0);
	while (s[++i] && len && fresh)
		fresh[i] = f(s[i]);
	fresh[i] = 0;
	return (fresh ? fresh : 0);
}
