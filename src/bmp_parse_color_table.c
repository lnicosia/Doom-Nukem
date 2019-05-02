/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parse_color_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:58:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/02 17:11:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bmp_parser.h"

int		parse_color_table(int fd, t_bmp_parser *parser)
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
			parser->colors[i] = read_int24(str, i * 4);
			i++;
		}
	}
	return (0);
}
