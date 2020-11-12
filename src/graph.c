/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:20:51 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 03:43:13 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		window_drawing(t_data *w)
{
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
	menu(w);
	mlx_input(w);
}

t_vector	call_scenes(t_all *all, int i, int j)
{
	t_vector color;

	color = (t_vector){0.0, 0.0, 0.0};
	if (all->scene.scene_type == 0)
		color = scene_normal(all, i, j);
	else if (all->scene.scene_type == 1)
		color = scene_alias(all, i, j);
	else if (all->scene.scene_type == 2)
		color = scene_dof(all, i, j);
	return (color);
}

void		graph(t_data *w)
{
	int			i;
	int			j;
	t_all		*all;
	t_vector	color;
	t_bmp		bmp;

	init_bmp(&bmp);
	all = w->all;
	i = 99;
	init_mlx(w);
	menu_color(w);
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			color = call_scenes(all, i, j);
			color_bmp(&bmp, color, i, j);
			w->data[(WIN_HEIGHT - i - 1) * WIN_WIDTH + j] = rgb_color(color);
		}
	}
	fill_bmp(&bmp);
	window_drawing(w);
}
