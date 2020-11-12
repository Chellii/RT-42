/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_mb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:20:11 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 05:33:24 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	graph_mb2(t_data *w, t_vector **image)
{
	int			i;
	int			j;
	t_vector	color;

	i = -1;
	while (++i < 1000)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			color = (t_vector){0.0, 0.0, 0.0};
			if (w->all->scene.scene_type == 0)
				color = scene_normal(w->all, i, j);
			if (w->all->scene.scene_type == 1)
				color = scene_alias(w->all, i, j);
			else if (w->all->scene.scene_type == 2)
				color = scene_dof(w->all, i, j);
			(image[i][j]).x = color.x;
			(image[i][j]).y = color.y;
			(image[i][j]).z = color.z;
		}
	}
}

void	graph_mb(t_data *w)
{
	int			i;
	t_vector	**image;

	init_bmp(&w->bmp);
	image = (t_vector **)malloc(1000 * sizeof(t_vector *));
	i = -1;
	while (++i < 1000)
		image[i] = (t_vector *)malloc(1000 * sizeof(t_vector));
	init_mlx(w);
	menu_color(w);
	graph_mb2(w, image);
	motion_blur(w, image);
	fill_bmp(&w->bmp);
	i = 0;
	while (i < 1000)
	{
		free(image[i]);
		i++;
	}
	free(image);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img_ptr, 0, 0);
	menu(w);
	mlx_input(w);
}
