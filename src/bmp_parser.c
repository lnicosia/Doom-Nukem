/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:52 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/30 16:53:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bmp_parser.h"

static int	parse_file_header(int fd, int debug, t_bmp_parser *parser)
{
	int				ret;
	unsigned char	header[14];

	if ((ret = read(fd, header, 14)) > 0)
	{
		if ((header[0] && header[0] != 'B') || (header[1] && header[1] != 'M'))
			return (ft_printf("File type is missing\n"));
		parser->size = read_int(header, 2);
		if (debug)
			ft_printf("File size = %d\n", parser->size);
		parser->start = read_int(header, 10);
		if (debug)
			ft_printf("Image offset (=start) = %d\n", parser->start);
	}
	else if (!ret)
		return (ft_printf("File only contains header\n"));
	else
		return (ft_printf("Error while reading file header \n"));
	if (ret != 14)
		return (ft_printf("Header is not valid\n"));
	return (0);
}

static int	parse_image_header(int fd, int debug, t_bmp_parser *parser)
{
	int				ret;
	unsigned char	*image_header;

	(void)debug;
	if (!(image_header = (unsigned char*)malloc(sizeof(unsigned char)
					* parser->image_header_size)))
		return (ft_printf("Could not malloc image_header array\n"));
	ft_memdel((void**)&image_header);
	if ((ret = read(fd, image_header, parser->image_header_size)) > 0)
	{

	}
	return (0);
}

static int	get_image_header_size(int fd, int debug, t_bmp_parser *parser)
{
	int				ret;
	unsigned char	image_header_size[4];

	if ((ret = read(fd, image_header_size, 4)) > 0)
	{
		parser->image_header_size = read_int(image_header_size, 0);
		if (debug)
			ft_printf("Image_header size = %d\n", parser->image_header_size);
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

static int	parse(int fd, int debug, t_env *env)
{
	t_bmp_parser	parser;

	(void)env;
	if (parse_file_header(fd, debug, &parser))
		return (ft_printf("Error in file header\n"));
	if (get_image_header_size(fd, debug, &parser))
		return (ft_printf("Error in image header\n"));
	if (parse_image_header(fd, debug, &parser))
		return (ft_printf("Error in image header\n"));
	return (0);
}

/*
**	Init function: 
**	-Create a new SDL surface to store the image
**	-Open the given file
**	-Parse it
**	-Close the file
*/

int			parse_bmp(char *file, int debug, t_env *env)
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
	if (parse(fd, debug, env))
		return (ft_printf("Error while parsing \"%s\"\n", file));
	if (close(fd))
		return (ft_printf("Could not close \"%s\"\n", file));
	ft_printf("{reset}");
	return (0);
}
