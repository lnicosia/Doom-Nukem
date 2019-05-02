/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parse_pixel_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:22:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/02 17:56:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bmp_parser.h"

static unsigned int	get_pixel(double i, unsigned char *str, t_bmp_parser *parser)
{
	if (parser->bpp == 32)
		return (read_int32(str, i));
	if (parser->bpp == 24)
		return (read_int24(str, i));
	if (parser->bpp == 16)
		return (read_int16(str, i));
	if (parser->bpp == 8)
		return (read_int8(str, i, parser->colors));
	if (parser->bpp == 4)
		return (read_int4(str, i, parser->colors));
	if (parser->bpp == 1)
		return (read_int1(str, i, parser->colors));
	return (0);
}

int					parse_pixel_data(int fd, t_bmp_parser *parser, t_env *env)
{
	double			i;
	int				x;
	int				y;
	int				ret;
	unsigned char	*str;

	ft_printf("{cyan}");
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char)
					* parser->w * parser->h * parser->bpp / 8.0)))
		return (ft_printf("Could not malloc buffer for pixel data\n"));
	if ((ret = read(fd, str, parser->w * parser->h * parser->bpp / 8.0)) > 0)
	{
		i = 0;
		x = 0;
		y = parser->h - 1;
		while (i < parser->h * parser->w * parser->bpp / 8.0)
		{
			env->sdl.image_str[x + y * parser->w] = get_pixel(i, str, parser); 
			//ft_printf("i = %f (~%d) [y = %d, x = %d]\n", i, (int)i, y, x);
			if ((int)i == i)
			{
				//ft_printf("byte %d = 0x%.2x (=%d)\n",(int)i, str[(int)i], str[(int)i]);
				/*ft_printf("%d%d%d%d%d%d%d%d\n", 
						str[(int)i] >> 7 & 1,
						str[(int)i] >> 6 & 1,
						str[(int)i] >> 5 & 1,
						str[(int)i] >> 4 & 1,
						str[(int)i] >> 3 & 1,
						str[(int)i] >> 2 & 1,
						str[(int)i] >> 1 & 1,
						str[(int)i] >> 0 & 1);*/
			}
			//ft_printf("img[%d, %d] = %x\n", y, x, env->sdl.image_str[x + y * parser->w]);
			i += parser->bpp / 8.0;
			x++;
			if (x >= parser->w)
			{
				while ((int)i % 4 != 0)
					i++;
				x = 0;
				y--;
			}
		}
	}
	ft_memdel((void**)&str);
	return (0);
}
