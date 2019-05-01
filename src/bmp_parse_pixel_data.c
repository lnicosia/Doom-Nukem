/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parse_pixel_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:22:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/01 15:35:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bmp_parser.h"

static unsigned int	get_pixel(int i, unsigned char *str, t_bmp_parser *parser)
{
	if (parser->bpp == 32)
		return (read_int32(str, i));
	if (parser->bpp == 24)
		return (read_int24(str, i));
	return (0);
}

int					parse_pixel_data(int fd, t_bmp_parser *parser, t_env *env)
{
	int				i;
	int				x;
	int				y;
	int				ret;
	unsigned char	*str;

	if (!(str = (unsigned char*)malloc(sizeof(unsigned char)
					* parser->w * parser->h * parser->bpp / 8)))
		return (ft_printf("Could not malloc buffer for pixel data\n"));
	if ((ret = read(fd, str, parser->w * parser->h * parser->bpp / 8)) > 0)
	{
		i = -4;
		x = 0;
		y = parser->h - 1;
		while (i < parser->h * parser->w * parser->bpp / 8)
		{
			env->sdl.image_str[x + y * parser->w] = get_pixel(i, str, parser); 
			i += parser->bpp / 8;
			x++;
			if (x >= parser->w)
			{
				x = 0;
				y--;
			}
		}
	}
	ft_memdel((void**)&str);
	return (0);
}
