/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:38:30 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 05:45:49 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		mouse_move(int x, int y, t_data *w)
{
	((x >= 27 && x <= 145) && (y >= 1047 && y <= 1059)) ?
		mlx_string_put(w->mlx_ptr, w->win_ptr, 27, 1040, 0xFF0000,
		"Multi thread") : mlx_string_put(w->mlx_ptr,
		w->win_ptr, 27, 1040, 0xA9A9A9, "Multi thread");
	((x >= 187 && x <= 306) && (y >= 1047 && y <= 1059)) ?
		mlx_string_put(w->mlx_ptr, w->win_ptr, 187, 1040, 0xFF0000,
		"Antialiasing") : mlx_string_put(w->mlx_ptr,
		w->win_ptr, 187, 1040, 0xA9A9A9, "Antialiasing");
	((x >= 350 && x <= 469) && (y >= 1047 && y <= 1059)) ?
		mlx_string_put(w->mlx_ptr, w->win_ptr, 350, 1040, 0xFF0000,
		"Sepia Filter") : mlx_string_put(w->mlx_ptr,
		w->win_ptr, 350, 1040, 0xA9A9A9, "Sepia Filter");
	((x >= 512 && x <= 620) && (y >= 1047 && y <= 1059)) ?
		mlx_string_put(w->mlx_ptr, w->win_ptr, 512, 1040, 0xFF0000,
		"Grey Filter") : mlx_string_put(w->mlx_ptr,
		w->win_ptr, 512, 1040, 0xA9A9A9, "Grey Filter");
	((x >= 680 && x <= 787) && (y >= 1047 && y <= 1059)) ?
		mlx_string_put(w->mlx_ptr, w->win_ptr, 680, 1040, 0xFF0000,
		"Motion Blur") : mlx_string_put(w->mlx_ptr,
		w->win_ptr, 680, 1040, 0xA9A9A9, "Motion Blur");
	return (1);
}

void	mouse_press3(int x, int y, t_data *w)
{
	if ((y >= 0 && y < (1000 / 4)) && (x >= 0 && x < WIN_WIDTH))
	{
		mlx_destroy(w);
		graph_multi_thread(w, 3);
	}
	else if ((y >= (1000 / 4) && y < (1000 / 2)) &&
		(x >= 0 && x < WIN_WIDTH))
	{
		mlx_destroy(w);
		graph_multi_thread(w, 2);
	}
	else if ((y >= (1000 / 2) && y < (1000 * 0.75)) &&
		(x >= 0 && x < WIN_WIDTH))
	{
		mlx_destroy(w);
		graph_multi_thread(w, 1);
	}
	else if ((y >= (1000 * 0.75) && y < 1000) &&
		(x >= 0 && x < WIN_WIDTH))
	{
		mlx_destroy(w);
		graph_multi_thread(w, 0);
	}
}

void	mouse_press2(int x, int y, t_data *w)
{
	if ((x >= 27 && x <= 145) && (y >= 1047 && y <= 1059))
	{
		mlx_destroy(w);
		w->all->scene.filter = 0;
		graph_multi_thread(w, -1);
	}
	else if ((x >= 187 && x <= 306) && (y >= 1047 && y <= 1059))
	{
		mlx_destroy(w);
		w->all->scene.scene_type = anti_alias;
		graph_multi_thread(w, -1);
	}
	else
		mouse_press3(x, y, w);
}

int		mouse_press(int button, int x, int y, t_data *w)
{
	if (button == 1)
	{
		if ((x >= 680 && x <= 787) && (y >= 1047 && y <= 1059))
		{
			mlx_destroy(w);
			graph_mb(w);
		}
		else if ((x >= 512 && x <= 620) && (y >= 1047 && y <= 1059))
		{
			mlx_destroy(w);
			w->all->scene.filter = 2;
			graph_multi_thread(w, -1);
		}
		else if ((x >= 350 && x <= 469) && (y >= 1047 && y <= 1059))
		{
			mlx_destroy(w);
			w->all->scene.filter = 1;
			graph_multi_thread(w, -1);
		}
		else
			mouse_press2(x, y, w);
	}
	return (1);
}
