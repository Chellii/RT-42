/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:42:49 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/02/19 23:42:51 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	move_z_camera(int key, t_data *w)
{
	if (key == 124)
	{
		mlx_destroy(w);
		w->all->cam.lookat.x += 2.0;
		graph(w);
	}
	else if (key == 123)
	{
		mlx_destroy(w);
		w->all->cam.lookat.x -= 2.0;
		graph(w);
	}
	else if (key == 126)
	{
		mlx_destroy(w);
		w->all->cam.lookat.y += 2.0;
		graph(w);
	}
	else if (key == 125)
	{
		mlx_destroy(w);
		w->all->cam.lookat.y -= 2.0;
		graph(w);
	}
}

void	move_x_camera(int key, t_data *w)
{
	if (key == 124)
	{
		mlx_destroy(w);
		w->all->cam.lookat.z -= 2.0;
		graph(w);
	}
	else if (key == 123)
	{
		mlx_destroy(w);
		w->all->cam.lookat.z += 2.0;
		graph(w);
	}
	else if (key == 126)
	{
		mlx_destroy(w);
		w->all->cam.lookat.y += 2.0;
		graph(w);
	}
	else if (key == 125)
	{
		mlx_destroy(w);
		w->all->cam.lookat.y -= 2.0;
		graph(w);
	}
}

int		deal_key(int key, t_data *w)
{
	if (key == 53)
	{
		mlx_destroy(w);
		free_all(w->all);
		exit(1);
	}
	if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		if (w->all->cam.lookfrom.x != 0.0)
			move_x_camera(key, w);
		else if (w->all->cam.lookfrom.z != 0.000001)
			move_z_camera(key, w);
	}
	return (0);
}

int		ft_close(void *data)
{
	t_data *w;

	w = (t_data*)data;
	free_all(w->all);
	(void)data;
	exit(0);
	return (0);
}
