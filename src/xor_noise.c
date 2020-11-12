/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_noise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:17:48 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/31 14:17:49 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	xor_noise(t_vector color, int x, int y)
{
	uint8_t c;

	c = (y ^ x);
	color.x = 255 - c;
	color.y = c;
	color.z = c % 128;
	color = (t_vector){color.x / 255, color.y / 255, color.z / 255};
	return (color);
}
