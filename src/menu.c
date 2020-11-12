/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:45:19 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/23 17:45:20 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	menu(t_data *w)
{
	mlx_string_put(w->mlx_ptr, w->win_ptr, 27, 1040, 0xA9A9A9, "Multi thread");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 159, 1040, 0xFFFFFF, "|");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 187, 1040, 0xA9A9A9, "Antialiasing");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 320, 1040, 0xFFFFFF, "|");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 350, 1040, 0xA9A9A9, "Sepia Filter");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 480, 1040, 0xFFFFFF, "|");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 512, 1040, 0xA9A9A9, "Grey Filter");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 640, 1040, 0xFFFFFF, "|");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 680, 1040, 0xA9A9A9, "Motion Blur");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 800, 1040, 0xFFFFFF, "|");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 840, 1030, 0xFF0C00, "To move");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 840, 1050, 0xFF0C00, "use Arrows");
}

void	menu_color(t_data *w)
{
	int i;
	int j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			w->data[(WIN_HEIGHT - i - 1) * WIN_WIDTH + j] = 0x090943;
			j++;
		}
		i++;
	}
}
