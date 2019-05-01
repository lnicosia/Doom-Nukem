/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bmp_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:53:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/01 12:28:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bmp_parser.h"

void	check_bmp_parsing(t_bmp_parser parser)
{
	ft_printf("{yellow}");
	ft_printf("File size = %d bytes\n", parser.size);
	ft_printf("Image offset = %d\n", parser.start);
	ft_printf("Image header size = %d\n", parser.image_header_size);
	ft_printf("Image width = %d\n", parser.width);
	ft_printf("Image height = %d\n", parser.height);
	ft_printf("Image planes = %d\n", parser.planes);
	ft_printf("Bits per pixel = %d\n", parser.bbp);
	ft_printf("Image compression = %d\n", parser.compression);
	ft_printf("Image size = %d\n", parser.image_size);
	ft_printf("X pixels per meter = %d\n", parser.xpixels_per_meter);
	ft_printf("Y pixels per meter = %d\n", parser.ypixels_per_meter);
	ft_printf("Color map entries = %d\n", parser.color_used);
	ft_printf("Significant colors = %d\n", parser.color_important);
	ft_printf("{reset}");
}
