/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:25:00 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/10/14 20:25:02 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static	int	g_permutation[] =
{
	151, 160, 137, 91, 90, 15, 131, 13, 201, 95,
	96, 53, 194, 233, 7, 225, 140, 36, 103, 30,
	69, 142, 8, 99, 37, 240, 21, 10, 23, 190,
	6, 148, 247, 120, 234, 75, 0, 26, 197, 62,
	94, 252, 219, 203, 117, 35, 11, 32, 57, 177,
	33, 88, 237, 149, 56, 87, 174, 20, 125, 136,
	171, 168, 68, 175, 74, 165, 71, 134, 139, 48,
	27, 166, 77, 146, 158, 231, 83, 111, 229, 122,
	60, 211, 133, 230, 220, 105, 92, 41, 55, 46,
	245, 40, 244, 102, 143, 54, 65, 25, 63, 161,
	1, 216, 80, 73, 209, 76, 132, 187, 208, 89,
	18, 169, 200, 196, 135, 130, 116, 188, 159, 86,
	164, 100, 109, 198, 173, 186, 3, 64, 52, 217,
	226, 250, 124, 123, 5, 202, 38, 147, 118, 126,
	255, 82, 85, 212, 207, 206, 59, 227, 47, 16,
	58, 17, 182, 189, 28, 42, 223, 183, 170, 213,
	119, 248, 152, 2, 44, 154, 163, 70, 221, 153,
	101, 155, 167, 43, 172, 9, 129, 22, 39, 253,
	19, 98, 108, 110, 79, 113, 224, 232, 178, 185,
	112, 104, 218, 246, 97, 228, 251, 34, 242, 193,
	238, 210, 144, 12, 191, 179, 162, 241, 81, 51,
	145, 235, 249, 14, 239, 107, 49, 192, 214, 31,
	181, 199, 106, 157, 184, 84, 204, 176, 115, 121,
	50, 45, 127, 4, 150, 254, 138, 236, 205, 93,
	222, 114, 67, 29, 24, 72, 243, 141, 128, 195,
	78, 66, 215, 61, 156, 180
};

double		result_noise(t_pnoise pn, double x, double y, double z)
{
	return (lerp(pn.w,
				lerp(pn.v,
					lerp(pn.u,
						grad(pn.p[pn.aa], x, y, z),
						grad(pn.p[pn.ba], x - 1, y, z)),
					lerp(pn.u,
						grad(pn.p[pn.ab], x, y - 1, z),
						grad(pn.p[pn.bb], x - 1, y - 1, z))),
				lerp(pn.v,
					lerp(pn.u,
						grad(pn.p[pn.aa + 1], x, y, z - 1),
						grad(pn.p[pn.ba + 1], x - 1, y, z - 1)),
					lerp(pn.u,
						grad(pn.p[pn.ab + 1], x, y - 1, z - 1),
						grad(pn.p[pn.bb + 1], x - 1, y - 1, z - 1)))));
}

double		noise(double x, double y, double z)
{
	double		result;
	t_pnoise	pn;

	pn.p = (int*)malloc(sizeof(int) * 512);
	perlin(pn.p, g_permutation);
	pn.xi = ((int)floor(x)) & 255;
	pn.yi = ((int)floor(y)) & 255;
	pn.zi = ((int)floor(z)) & 255;
	x -= floor(x);
	y -= floor(y);
	z -= floor(z);
	pn.u = fade(x);
	pn.v = fade(y);
	pn.w = fade(z);
	pn.a = pn.p[pn.xi] + pn.yi;
	pn.aa = pn.p[pn.a] + pn.zi;
	pn.ab = pn.p[pn.a + 1] + pn.zi;
	pn.b = pn.p[pn.xi + 1] + pn.yi;
	pn.ba = pn.p[pn.b] + pn.zi;
	pn.bb = pn.p[pn.b + 1] + pn.zi;
	result = result_noise(pn, x, y, z);
	free(pn.p);
	return (result);
}

float		turbulence(float x, float y, float z, float size)
{
	float	value;
	float	initial_size;

	value = 0.0;
	initial_size = size;
	while (size >= 1)
	{
		value += noise(x / size, y / size, z / size) * size;
		size /= 2.0;
	}
	return (value / initial_size);
}

t_vector	set_perlin_noise(t_ray ray)
{
	float n;

	n = noise((ray.j / 30.), (ray.i / 30.), 0);
	n = 0.4 * (n + 1.0);
	return ((t_vector){n, n, n});
}
