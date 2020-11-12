/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_multi_thread2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:58:20 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/28 10:58:22 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	graph1(t_data *w)
{
	int			i;
	int			j;
	t_vector	color;
	t_all		*all;

	all = w->all;
	i = 100;
	while (i < (((WIN_HEIGHT - 100) / 4) + 100))
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			color = call_scene(all, i, j);
			color_bmp(&w->bmp, color, i, j);
			w->data[(WIN_HEIGHT - i - 1) * WIN_WIDTH + j] = rgb_color(color);
		}
		i++;
	}
	menu_color(w);
}

void	graph2(t_data *w)
{
	int			i;
	int			j;
	t_vector	color;
	t_all		*all;

	all = w->all;
	i = (((WIN_HEIGHT - 100) / 4) + 100);
	while (i < ((WIN_HEIGHT - 100) / 2) + 100)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			color = call_scene(all, i, j);
			color_bmp(&w->bmp, color, i, j);
			w->data[(WIN_HEIGHT - i - 1) * WIN_WIDTH + j] = rgb_color(color);
		}
		i++;
	}
	menu_color(w);
}

void	graph3(t_data *w)
{
	int			i;
	int			j;
	t_vector	color;
	t_all		*all;

	all = w->all;
	i = ((WIN_HEIGHT - 100) / 2) + 100;
	while (i < ((WIN_HEIGHT - 100) * 0.75) + 100)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			color = call_scene(all, i, j);
			color_bmp(&w->bmp, color, i, j);
			w->data[(WIN_HEIGHT - i - 1) * WIN_WIDTH + j] = rgb_color(color);
		}
		i++;
	}
	menu_color(w);
}

void	graph4(t_data *w)
{
	int			i;
	int			j;
	t_vector	color;
	t_all		*all;

	all = w->all;
	i = ((WIN_HEIGHT - 100) * 0.75) + 100;
	while (i < (WIN_HEIGHT - 100) + 100)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			color = call_scene(all, i, j);
			color_bmp(&w->bmp, color, i, j);
			w->data[(WIN_HEIGHT - i - 1) * WIN_WIDTH + j] = rgb_color(color);
		}
		i++;
	}
	menu_color(w);
}
