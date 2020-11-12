/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:11:00 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/02/17 20:11:01 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rotation_x(t_vector *axis, t_vector axis2, t_vector rot)
{
	axis->y = axis2.y * cos(rot.x * MPI / 180) - axis2.z *
		sin(rot.x * MPI / 180);
	axis->z = axis2.y * sin(rot.x * MPI / 180) + axis2.z *
		cos(rot.x * MPI / 180);
}

void	rotation_y(t_vector *axis, t_vector axis2, t_vector rot)
{
	axis->x = axis2.x * cos(rot.y * MPI / 180) + axis2.z *
		sin(rot.y * MPI / 180);
	axis->z = -axis2.x * sin(rot.y * MPI / 180) + axis2.z *
		cos(rot.y * MPI / 180);
}

void	rotation_z(t_vector *axis, t_vector axis2, t_vector rot)
{
	axis->x = axis2.x * cos(rot.z * MPI / 180) - axis2.y *
		sin(rot.z * MPI / 180);
	axis->y = axis2.x * sin(rot.z * MPI / 180) + axis2.y *
		cos(rot.z * MPI / 180);
}

void	rotation(t_vector *axis, t_vector rot)
{
	t_vector axis2;

	axis2 = (t_vector){axis->x, axis->y, axis->z};
	if (rot.x != 0)
		rotation_x(axis, axis2, rot);
	axis2 = (t_vector){axis->x, axis->y, axis->z};
	if (rot.y != 0)
		rotation_y(axis, axis2, rot);
	axis2 = (t_vector){axis->x, axis->y, axis->z};
	if (rot.z != 0)
		rotation_z(axis, axis2, rot);
}

void	translation(t_vector *pos, t_vector trans)
{
	pos->x += trans.x;
	pos->y += trans.y;
	pos->z += trans.z;
}
