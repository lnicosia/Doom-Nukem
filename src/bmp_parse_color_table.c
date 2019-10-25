/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   bmp_parse_color_table.c							:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/05/02 11:58:19 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/07/24 14:54:44 by sipatry		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

static int	parse_color_table(int fd, t_bmp_parser *parser)
{
	int				ret;
	int				i;
	unsigned char	*str;

	if (!(parser->colors = (unsigned int*)malloc(sizeof(unsigned int)
					* parser->color_used)))
		return (ft_printf("Could not malloc colors array\n"));
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char)
					* parser->color_used * 4)))
	{
		ft_memdel((void**)&parser->colors);
		return (ft_printf("Could not malloc buffer for color table\n"));
	}
	if ((ret = read(fd, str, parser->color_used * 4)) > 0)
	{
		i = 0;
		while (i < parser->color_used)
		{
			parser->colors[i] = read_color24(str, i * 4);
			i++;
		}
	}
	ft_memdel((void**)&str);
	return (0);
}

static void	set_colors8(unsigned int *colors)
{
	colors[0] = 0x000000FF;
	colors[1] = 0x00000FFF;
	colors[2] = 0x0000F0FF;
	colors[3] = 0x0000FFFF;
	colors[4] = 0x000F00FF;
	colors[5] = 0x00F000FF;
	colors[6] = 0x00FF00FF;
	colors[7] = 0x0F0000FF;
	colors[8] = 0xF00000FF;
	colors[9] = 0xFF0000FF;
}

static void	set_colors4(unsigned int *colors)
{
	colors[0] = 0;
	colors[1] = 0xFF0000AA;
	colors[2] = 0xFF00AA00;
	colors[3] = 0xFF00AAAA;
	colors[4] = 0xFFAA0000;
	colors[5] = 0xFFAA00AA;
	colors[6] = 0xFFAA5500;
	colors[7] = 0xFFAAAAAA;
	colors[8] = 0xFF555555;
	colors[9] = 0xFF5555FF;
	colors[10] = 0xFF55FF55;
	colors[11] = 0xFF55FFFF;
	colors[12] = 0xFFFF5555;
	colors[13] = 0xFFFF55FF;
	colors[14] = 0xFFFFFF55;
	colors[15] = 0xFFFFFFFF;
}

static void	set_colors1(unsigned int *colors)
{
	colors[0] = 0xFF;
	colors[1] = 0xFFFFFFFF;
}

static int	default_color_table(t_bmp_parser *parser)
{
	if (!(parser->colors = (unsigned int*)malloc(sizeof(unsigned int)
					* pow(2, parser->bpp))))
		return (ft_printf("Could not malloc colors array\n"));
	if (parser->bpp == 8)
		set_colors8(parser->colors);
	if (parser->bpp == 4)
		set_colors4(parser->colors);
	if (parser->bpp == 1)
		set_colors1(parser->colors);
	return (0);
}

int			set_color_table(int fd, t_bmp_parser *parser)
{
	if (parser->color_used)
		return (parse_color_table(fd, parser));
	else
		return (default_color_table(parser));
}
