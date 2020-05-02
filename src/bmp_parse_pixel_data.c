/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parse_pixel_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:56:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 17:09:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"
#include <math.h>

int		parse_pixels(unsigned char *str, t_bmp_parser *parser,
t_texture *textures)
{
	double	byte;
	int		x;
	int		y;

	byte = 0;
	x = 0;
	y = parser->h - 1;
	while (byte + 4 < parser->ret)
	{
		textures[parser->index].str[x + y * parser->w] =
		get_pixel(byte, str, parser);
		byte += parser->bpp / 8.0;
		x++;
		set_byte(&x, &y, &byte, parser);
	}
	return (0);
}

int		set_byte(int *x, int *y, double *byte, t_bmp_parser *parser)
{
	double	trash;

	if (*x >= parser->w)
	{
		while (modf(*byte, &trash) != 0)
			(*byte) += parser->bpp / 8.0;
		while ((int)*byte % 4 != 0)
			(*byte)++;
		*x = 0;
		(*y)--;
	}
	return (0);
}

int		parse_pixel_data(int fd, t_bmp_parser *parser, t_texture *textures)
{
	int				size;
	unsigned char	*str;

	ft_printf("{cyan}");
	if (parser->image_size)
		size = parser->image_size;
	else
		size = ceil((parser->w * parser->bpp) / 32.0) * 4 * parser->h;
	if (!(str = (unsigned char*)ft_memalloc(sizeof(unsigned char) * size)))
		return (ft_printf("Could not malloc buffer for pixel data\n"));
	if ((parser->ret = read(fd, str, size)) > 0)
		parse_pixels(str, parser, textures);
	ft_memdel((void**)&str);
	return (0);
}
