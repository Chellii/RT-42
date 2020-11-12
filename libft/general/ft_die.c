/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 02:04:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/01 12:30:32 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_die(const char *message, int error_nb)
{
	if (error_nb != 0 && message)
		ft_printf("%w%s", 2, message);
	else if (message)
		ft_printf("%s", message);
	exit(error_nb);
}
