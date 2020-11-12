/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:42:33 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 03:47:40 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	color_bmp(t_bmp *bmp, t_vector color, int i, int j)
{
	bmp->buf[(i - 100) * bmp->width_in_bytes + j * 3 + 0] = cmp(color.z * 255,
		0, 255);
	bmp->buf[(i - 100) * bmp->width_in_bytes + j * 3 + 1] = cmp(color.y * 255,
		0, 255);
	bmp->buf[(i - 100) * bmp->width_in_bytes + j * 3 + 2] = cmp(color.x * 255,
		0, 255);
}

void	init_bmp(t_bmp *bmp)
{
	ft_memset(&(bmp->filehdr), 0, sizeof(bmp->filehdr));
	ft_memset(&(bmp->infohdr), 0, sizeof(bmp->infohdr));
	bmp->width_in_bytes = ((1000 * 24 + 23) / 24) * 3;
	bmp->imagesize = bmp->width_in_bytes * 1000;
	ft_memcpy(&(bmp->filehdr.bf_type), "BM", 2);
	bmp->filehdr.bf_size = 14;
	bmp->filehdr.bf_reserved1 = 0;
	bmp->filehdr.bf_off_bits = 54;
	bmp->infohdr.bi_size = 40;
	bmp->infohdr.bi_width = WIN_WIDTH;
	bmp->infohdr.bi_height = 1000;
	bmp->infohdr.bi_planes = 1;
	bmp->infohdr.bi_bit_count = 24;
	bmp->infohdr.bi_compression = 0;
	bmp->infohdr.bi_size_image = bmp->imagesize;
	bmp->infohdr.bix_pels_per_meter = 2835;
	bmp->infohdr.biy_pels_per_meter = 2835;
	bmp->infohdr.bi_clr_used = 0;
	bmp->infohdr.bi_clr_important = 0;
	bmp->buf = (unsigned char*)malloc(sizeof(unsigned char) * bmp->imagesize);
}

void	fill_bmp(t_bmp *bmp)
{
	if ((bmp->fout = open("screen_shot.bmp", O_RDWR | O_CREAT, 0644)) == -1)
	{
		ft_putstr("No file : ");
		ft_putendl("screen_shot");
		close(bmp->fout);
		exit(1);
	}
	write(bmp->fout, &(bmp->filehdr.bf_type), 2);
	write(bmp->fout, &(bmp->filehdr.bf_size), 4);
	write(bmp->fout, &(bmp->filehdr.bf_reserved1), 4);
	write(bmp->fout, &(bmp->filehdr.bf_off_bits), 4);
	write(bmp->fout, &(bmp->infohdr.bi_size), 4);
	write(bmp->fout, &(bmp->infohdr.bi_width), 4);
	write(bmp->fout, &(bmp->infohdr.bi_height), 4);
	write(bmp->fout, &(bmp->infohdr.bi_planes), 2);
	write(bmp->fout, &(bmp->infohdr.bi_bit_count), 2);
	write(bmp->fout, &(bmp->infohdr.bi_compression), 4);
	write(bmp->fout, &(bmp->infohdr.bi_size_image), 4);
	write(bmp->fout, &(bmp->infohdr.bix_pels_per_meter), 4);
	write(bmp->fout, &(bmp->infohdr.biy_pels_per_meter), 4);
	write(bmp->fout, &(bmp->infohdr.bi_clr_used), 4);
	write(bmp->fout, &(bmp->infohdr.bi_clr_important), 4);
	write(bmp->fout, bmp->buf, bmp->imagesize);
	close(bmp->fout);
	free(bmp->buf);
}
