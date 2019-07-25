/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bmp_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:53:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/24 14:55:39 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

void	check_bmp_parsing(t_bmp_parser parser)
{
	int	i;

	i = 0;
	ft_printf("{yellow}");
	ft_printf("File size = %d bytes\n", parser.size);
	ft_printf("Image offset = %d\n", parser.start);
	ft_printf("Image header size = %d\n", parser.image_header_size);
	ft_printf("Image width = %d\n", parser.w);
	ft_printf("Image height = %d\n", parser.h);
	ft_printf("Image planes = %d\n", parser.planes);
	ft_printf("Bits per pixel = %d\n", parser.bpp);
	ft_printf("Image compression = %d\n", parser.compression);
	ft_printf("Image size = %d\n", parser.image_size);
	ft_printf("X pixels per meter = %d\n", parser.xpixels_per_meter);
	ft_printf("Y pixels per meter = %d\n", parser.ypixels_per_meter);
	ft_printf("Color map entries = %d\n", parser.color_used);
	ft_printf("Significant colors = %d\n", parser.color_important);
	/*while (i < parser.color_used)
	{
		ft_printf("Color %d = 0x%x\n", i, parser.colors[i]);
		i++;
	}*/
	ft_printf("{reset}");
}
