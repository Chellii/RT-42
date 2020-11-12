/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:45:29 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/23 17:45:29 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_mlx(t_data *w)
{
	w->img_ptr = mlx_new_image(w->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	w->data = (int *)mlx_get_data_addr(w->img_ptr, &(w->b),
		&(w->s_l), &(w->end));
}

void	mlx_destroy(t_data *w)
{
	mlx_destroy_image(w->mlx_ptr, w->img_ptr);
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
}

void	mlx_input(t_data *w)
{
	mlx_hook(w->win_ptr, 2, 0, deal_key, w);
	mlx_hook(w->win_ptr, 17, 0, ft_close, w);
	mlx_hook(w->win_ptr, 4, 0, mouse_press, w);
	mlx_hook(w->win_ptr, 6, 0, mouse_move, w);
	mlx_loop(w->mlx_ptr);
}
