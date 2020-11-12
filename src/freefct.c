/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:29:04 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/02/20 17:29:05 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_list(t_list_pars *lt)
{
	t_list_pars *list_tracker;

	list_tracker = lt;
	while (list_tracker != NULL)
	{
		if (list_tracker != NULL)
			lt = list_tracker->next;
		free(list_tracker->str);
		free(list_tracker);
		list_tracker = lt;
	}
}

void	free_all(t_all *all)
{
	t_obj	*obj_tracker;
	t_light	*lights_tracker;

	obj_tracker = all->obj;
	while (obj_tracker != NULL)
	{
		if (obj_tracker != NULL)
			all->obj = obj_tracker->next;
		free(obj_tracker);
		obj_tracker = all->obj;
	}
	lights_tracker = all->lights;
	while (lights_tracker != NULL)
	{
		if (lights_tracker != NULL)
			all->lights = lights_tracker->next;
		free(lights_tracker);
		lights_tracker = all->lights;
	}
	free(all);
}
