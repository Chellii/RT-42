/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:42:03 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/19 17:42:04 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	initial_verif_obj(t_verif_obj *vo)
{
	vo->i = 0;
	vo->line = 0;
	vo->mat = 0;
	vo->tex = 0;
	vo->vec = 0;
	vo->cut = 0;
}

float	min_max(float m)
{
	if (m < 0)
		return (0);
	else if (m > 1)
		return (1);
	return (m);
}
