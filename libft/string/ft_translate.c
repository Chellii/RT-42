/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 07:21:19 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/12/24 01:30:24 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_translate(char *str, const char *from, const char *to)
{
	int		i;
	char	*ret;

	ret = str;
	if (!str || !from || !to)
		return (str);
	while (*str)
	{
		i = 0;
		while (from[i])
		{
			if (*str == from[i])
			{
				*str = to[i];
				break ;
			}
			i++;
		}
		str++;
	}
	return (ret);
}
