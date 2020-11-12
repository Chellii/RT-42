/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:55:30 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 14:21:06 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>

_Bool	ft_is_dir(const char *file_name)
{
	DIR	*dirp;

	if ((dirp = opendir(file_name)))
	{
		closedir(dirp);
		return (1);
	}
	return (0);
}
