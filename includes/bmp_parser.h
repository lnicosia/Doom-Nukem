/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:48:16 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/01 12:27:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARSER_H
# define BMP_PARSER_H
# define TRUE 1
# define FALSE 0

typedef struct	s_bmp_parser
{
	int32_t		size;
	int32_t		start;
	int32_t		image_header_size;
	int32_t		width;
	int32_t		height;
	int16_t		planes;
	int16_t		bbp;
	int32_t		compression;
	int32_t		image_size;
	int32_t		xpixels_per_meter;
	int32_t		ypixels_per_meter;
	int32_t		color_used;
	int32_t		color_important;
}				t_bmp_parser;

int32_t				read_int32(unsigned char *str, int index);
int16_t				read_int16(unsigned char *str, int index);
void				check_bmp_parsing(t_bmp_parser parser);
#endif
