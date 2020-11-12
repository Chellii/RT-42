/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:13:26 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/02 16:41:07 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	char		*fresh;
	unsigned	i;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	if (!(fresh = (char *)MALLOC((len + 1) * sizeof(char))))
		return (0);
	while (s && f && len && fresh && s[i])
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	fresh[i] = 0;
	return (fresh ? fresh : 0);
}
