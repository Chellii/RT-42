/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:20:22 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 05:55:52 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parse.h"

double	rand_double(void)
{
	return (rand() / (double)RAND_MAX);
}

void	graph_choices(t_data *w, int i)
{
	if (w->all->scene.choices == 0)
		graph(w);
	else if (w->all->scene.choices == 1)
		graph_multi_thread(w, i);
	else if (w->all->scene.choices == 2)
		graph_mb(w);
	else
		ft_putendl("choose between 1, 2 or 3 in scene choices");
	free_all(w->all);
}

int		main(int ac, char **av)
{
	t_data	w;

	if (ac == 2)
	{
		w.file_name = av[1];
		if (!(w.all = read_make_obj(w.file_name)))
			exit(0);
		w.mlx_ptr = mlx_init();
		w.win_ptr = mlx_new_window(w.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "RT");
		graph_choices(&w, -1);
	}
	else
		ft_putendl("./rt namefile");
	return (0);
}
