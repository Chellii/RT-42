/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_multi_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:21:01 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/19 19:21:02 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	graph_multi_thread2(t_data *w, int i, pthread_t *thread)
{
	init_mlx(w);
	if (i == 0)
		pthread_create(&thread[i], NULL, (void *)graph1, (void *)w);
	else if (i == 1)
		pthread_create(&thread[i], NULL, (void *)graph2, (void *)w);
	else if (i == 2)
		pthread_create(&thread[i], NULL, (void *)graph3, (void *)w);
	else if (i == 3)
		pthread_create(&thread[i], NULL, (void *)graph4, (void *)w);
	pthread_join(thread[i], NULL);
}

void	graph_multi_thread(t_data *w, int i)
{
	pthread_t	thread[4];

	init_bmp(&w->bmp);
	if (i == -1)
	{
		i = 0;
		init_mlx(w);
		pthread_create(&thread[0], NULL, (void *)graph1, (void *)w);
		pthread_create(&thread[1], NULL, (void *)graph2, (void *)w);
		pthread_create(&thread[2], NULL, (void *)graph3, (void *)w);
		pthread_create(&thread[3], NULL, (void *)graph4, (void *)w);
		while (i < 4)
		{
			pthread_join(thread[i], NULL);
			i++;
		}
	}
	else
		graph_multi_thread2(w, i, thread);
	fill_bmp(&w->bmp);
	window_drawing(w);
}
