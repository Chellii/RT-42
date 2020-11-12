/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmapheader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 03:56:18 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/02 12:22:04 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAPHEADER_H
# define BITMAPHEADER_H

typedef struct	s_bitmap_file_header
{
	uint16_t	bf_type[2];
	uint32_t	bf_size;
	uint16_t	bf_reserved1;
	uint32_t	bf_off_bits;
}				t_bitmap_file_header;
typedef struct	s_bitmap_info_header
{
	uint32_t	bi_size;
	int32_t		bi_width;
	int32_t		bi_height;
	uint16_t	bi_planes;
	uint16_t	bi_bit_count;
	uint32_t	bi_compression;
	uint32_t	bi_size_image;
	int32_t		bix_pels_per_meter;
	int32_t		biy_pels_per_meter;
	uint32_t	bi_clr_used;
	uint32_t	bi_clr_important;

}				t_bitmap_info_header;

#endif
