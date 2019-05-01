/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:52 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/01 12:31:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bmp_parser.h"

static int	parse_file_header(int fd, t_bmp_parser *parser)
{
	int				ret;
	unsigned char	header[14];

	if ((ret = read(fd, header, 14)) > 0)
	{
		if ((header[0] && header[0] != 'B') || (header[1] && header[1] != 'M'))
			return (ft_printf("File type is missing\n"));
		if ((parser->size = read_int32(header, 2)) <= 14)
			return (ft_printf("File size is too small! (%d bytes)\n",
						parser->size));
			if ((parser->start = read_int32(header, 10)) <= 14)
			return (ft_printf("Image offset is too low (%d)\n",
						parser->start));
	}
	else if (!ret)
		return (ft_printf("File only contains header\n"));
	else
		return (ft_printf("Error while reading file header \n"));
	if (ret != 14)
		return (ft_printf("Header is not valid\n"));
	return (0);
}

static int	get_image_header_data(unsigned char *str, t_bmp_parser *parser)
{
	if ((parser->width = read_int32(str, 0)) <= 0)
		return (ft_printf("Image width is too small (%d)\n",
					parser->width));
		if ((parser->height = read_int32(str, 4)) <= 0)
		return (ft_printf("Image height is too small (%d)\n",
					parser->height));
		if ((parser->planes = read_int16(str, 8)) != 1)
		return (ft_printf("Image planes must be equal to 1 (%d)\n",
					parser->planes));
		parser->bbp = read_int16(str, 10);
	if (parser->bbp != 32 && parser->bbp != 24)
		return (ft_printf("Bits per pixels must be equal to 32 or 24 (%d)\n",
				parser->bbp));
		if ((parser->compression = read_int32(str, 12)))
		return (ft_printf("Image must not be compressed (%d)\n",
					parser->compression));
		parser->image_size = read_int32(str, 16);
	parser->xpixels_per_meter = read_int32(str, 20);
	parser->ypixels_per_meter = read_int32(str, 24);
	parser->color_used = read_int32(str, 28);
	parser->color_important = read_int32(str, 32);
	return (0);
}

static int	parse_image_header(int fd, t_bmp_parser *parser)
{
	int				ret;
	unsigned char	*image_header;

	if (!(image_header = (unsigned char*)malloc(sizeof(unsigned char)
					* parser->image_header_size)))
		return (ft_printf("Could not malloc image_header array\n"));
	if ((ret = read(fd, image_header, parser->image_header_size)) > 0)
	{
		if (get_image_header_data(image_header, parser))
			return (ft_printf("Image header is not valid\n"));
	}
	else if (!ret)
	{
		ft_memdel((void**)&image_header);
		return (ft_printf("Incomplete image header\n"));
	}
	else
	{
		ft_memdel((void**)&image_header);
		return (ft_printf("Error while reading image header \n"));
	}
	ft_memdel((void**)&image_header);
	return (0);
}

static int	get_image_header_size(int fd, t_bmp_parser *parser)
{
	int				ret;
	unsigned char	image_header_size[4];

	if ((ret = read(fd, image_header_size, 4)) > 0)
	{
		if ((parser->image_header_size = read_int32(image_header_size, 0)) <= 0)
			return (ft_printf("Invalid image header size (%d)\n",
						parser->image_header_size));
	}
	else if (!ret)
		return (ft_printf("Incomplete image header\n"));
	else
		return (ft_printf("Error while reading image header \n"));
	return (0);
}

/*
**	Main function: parse every part of the BMP file:
**	-File header
**	-Image header
**	-Image data
*/

static int	parse(int fd, t_env *env)
{
	t_bmp_parser	parser;

	(void)env;
	if (parse_file_header(fd, &parser))
		return (ft_printf("Error in file header\n"));
	if (get_image_header_size(fd, &parser))
		return (ft_printf("Error in image header\n"));
	if (parse_image_header(fd, &parser))
		return (ft_printf("Error in image header\n"));
	check_bmp_parsing(parser);
	return (0);
}

/*
**	Init function:
**	-Create a new SDL surface to store the image
**	-Open the given file
**	-Parse it
**	-Close the file
*/

int			parse_bmp(char *file, t_env *env)
{
	int	fd;

	ft_printf("Parsing \"%s\"\n{red}", file);
	if (!(env->sdl.image = SDL_CreateRGBSurfaceWithFormat(
					0,
					env->w,
					env->h,
					32,
					SDL_PIXELFORMAT_RGBA8888)))
		return (ft_printf("SDL_CreateRGBSurface error: %s\n", SDL_GetError()));
	env->sdl.image_str = env->sdl.surface->pixels;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_printf("Could not open \"%s\"\n", file));
	if (parse(fd, env))
		return (ft_printf("Error while parsing \"%s\"\n", file));
	if (close(fd))
		return (ft_printf("Could not close \"%s\"\n", file));
	ft_printf("{reset}");
	return (0);
}
