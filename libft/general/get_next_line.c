/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:07:27 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/01 12:29:33 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			r;
	char		b[BUFF_SIZE + 1];
	static char	*re[5002];

	if (!line || fd < 0 || fd > L || !(re[fd] = re[fd] ? re[fd] : ft_strnew(0)))
		return (-1);
	r = 1;
	while (!(re[L] = ft_strchr(re[fd], '\n')) &&
			(r = read(fd, b, BS)) > 0)
	{
		re[TMP] = re[fd];
		b[r] = 0;
		re[fd] = ft_strjoin(re[fd], b);
		free(re[TMP]);
		if (!re[fd])
			return (-1);
	}
	*line = ft_strsub(re[fd], 0, (re[L] ? re[L] - re[fd] : ft_strlen(re[fd])));
	re[TMP] = re[fd];
	re[fd] = r > 0 ? ft_strdup(re[L] + 1) : NULL;
	free(re[TMP]);
	if ((!re[fd] && re[L] && re[L][1]) || !*line)
		return (-1);
	return (**line || re[L] ? 1 + (r == 0) : r);
}
