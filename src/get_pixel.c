/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:22:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:22:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

unsigned int		get_pixel(double byte, unsigned char *str,
t_bmp_parser *parser)
{
	if (parser->bpp == 32)
		return (read_color32(str, byte));
	if (parser->bpp == 24)
		return (read_color24(str, byte));
	if (parser->bpp == 16)
		return (read_color16(str, byte));
	if (parser->bpp == 8)
		return (read_color8(str, byte, parser));
	if (parser->bpp == 4)
		return (read_color4(str, byte, parser->colors));
	if (parser->bpp == 1)
		return (read_color1(str, byte, parser->colors));
	return (0);
}
