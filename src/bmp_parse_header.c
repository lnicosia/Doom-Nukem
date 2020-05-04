/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parse_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:43:35 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/28 16:56:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

int	parse_file_header(int fd, t_bmp_parser *parser)
{
	int				ret;
	unsigned char	header[14];

	if ((ret = read(fd, header, 14)) > 0)
	{
		if ((header[0] && header[0] != 'B') || (header[1] && header[1] != 'M'))
			return (custom_error("File type is missing\n"));
		if ((parser->size = read_int32(header, 2)) <= 14)
			return (custom_error("File size is too small! (%d bytes)\n",
						parser->size));
			if ((parser->start = read_int32(header, 10)) <= 14)
			return (custom_error("Image offset is too low (%d)\n",
						parser->start));
	}
	else if (!ret)
		return (custom_error("File only contains header\n"));
	else
		return (custom_error("Error while reading file header \n"));
	if (ret != 14)
		return (custom_error("Header is not valid\n"));
	return (0);
}

int	get_image_header_data(unsigned char *str, t_bmp_parser *parser)
{
	if ((parser->w = read_int32(str, 0)) <= 0)
		return (custom_error("Image width is too small (%d)\n",
					parser->w));
		if (ft_abs(parser->h = read_int32(str, 4)) <= 0)
		return (custom_error("Image height is too small (%d)\n",
					parser->h));
		if ((parser->planes = read_int16(str, 8)) != 1)
		return (custom_error("Image planes must be equal to 1 (%d)\n",
					parser->planes));
		parser->bpp = read_int16(str, 10);
	if (parser->bpp != 24)
		return (custom_error("Bits per pixels must be equal 24 (%d)\n",
					parser->bpp));
		if ((parser->compression = read_int32(str, 12)))
		return (custom_error("Image must not be compressed (%d)\n",
					parser->compression));
		parser->image_size = read_int32(str, 16);
	parser->xpixels_per_meter = read_int32(str, 20);
	parser->ypixels_per_meter = read_int32(str, 24);
	parser->color_used = read_int32(str, 28);
	parser->color_important = read_int32(str, 32);
	return (0);
}

int	parse_image_header(int fd, t_bmp_parser *parser)
{
	int				ret;
	unsigned char	*image_header;

	if (!(image_header = (unsigned char*)ft_memalloc(sizeof(unsigned char)
					* (parser->image_header_size - 4))))
		return (ft_perror("Could not malloc image_header array"));
	if ((ret = read(fd, image_header, parser->image_header_size - 4)) > 0)
	{
		if (get_image_header_data(image_header, parser))
			return (custom_error("Image header is not valid\n"));
	}
	else if (!ret)
	{
		ft_memdel((void**)&image_header);
		return (custom_error("Incomplete image header\n"));
	}
	else
	{
		ft_memdel((void**)&image_header);
		return (custom_error("Error while reading image header \n"));
	}
	ft_memdel((void**)&image_header);
	return (0);
}

int	get_image_header_size(int fd, t_bmp_parser *parser)
{
	int				ret;
	unsigned char	image_header_size[4];

	if ((ret = read(fd, image_header_size, 4)) > 0)
	{
		if ((parser->image_header_size = read_int32(image_header_size, 0)) <= 0)
			return (custom_error("Invalid image header size (%d)\n",
						parser->image_header_size));
	}
	else if (!ret)
		return (custom_error("Incomplete image header\n"));
	else
		return (custom_error("Error while reading image header \n"));
	return (0);
}
