/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_blur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:51:27 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/23 19:51:28 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double g_filter_mb[FILTERHEIGHT][FILTERWIDTH] =
{
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
};

int		verif_img_mb(t_vector image)
{
	if (image.x == 0.0 && image.y == 0 && image.z == 0)
		return (0);
	return (1);
}

void	init_mb(t_mb *mb)
{
	mb->factor = 1.0 / 17.0;
	mb->bias = 0.1;
	mb->red = 0.0;
	mb->green = 0.0;
	mb->blue = 0.0;
}

void	motion_blur2(t_vector **image, t_mb *mb, int x, int y)
{
	mb->fy = 0;
	while (mb->fy < FILTERHEIGHT)
	{
		mb->fx = 0;
		while (mb->fx < FILTERWIDTH)
		{
			mb->img_x = (x - FILTERWIDTH / 2 + mb->fx + 1000)
				% 1000;
			mb->img_y = (y - FILTERHEIGHT / 2 + mb->fy + WIN_WIDTH)
				% WIN_WIDTH;
			mb->red += (image[mb->img_x][mb->img_y]).x *
				g_filter_mb[mb->fy][mb->fx];
			mb->green += (image[mb->img_x][mb->img_y]).y *
				g_filter_mb[mb->fy][mb->fx];
			mb->blue += (image[mb->img_x][mb->img_y]).z *
				g_filter_mb[mb->fy][mb->fx];
			(mb->fx)++;
		}
		mb->fy++;
	}
}

void	motion_blur(t_data *w, t_vector **image)
{
	int			x;
	int			y;
	t_vector	color;
	t_mb		mb;

	x = 100;
	while (x < WIN_HEIGHT)
	{
		y = -1;
		while (++y < WIN_WIDTH)
		{
			init_mb(&mb);
			if (verif_img_mb(image[(x - 100)][y]))
			{
				motion_blur2(image, &mb, (x - 100), y);
				color = (t_vector){mb.red * mb.factor + mb.bias,
					mb.green * mb.factor
					+ mb.bias, mb.blue * mb.factor + mb.bias};
				w->data[(WIN_HEIGHT - x - 1) * WIN_WIDTH + y] =
					rgb_color(color);
				color_bmp(&w->bmp, color, x, y);
			}
		}
		x++;
	}
}
