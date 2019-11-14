/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:56:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/14 11:56:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

/*
**	Main function: parse every part of the BMP file:
**	-File header
**	-Image header
**	-Image data
*/

static int	parse(int fd, int index, t_env *env)
{
	t_bmp_parser	parser;

	if (index >= MAX_TEXTURE)
		return (ft_printf("Too much textures\n"));
	if (parse_file_header(fd, &parser))
		return (ft_printf("Error in file header\n"));
	if (get_image_header_size(fd, &parser))
		return (ft_printf("Error in image header\n"));
	if (parse_image_header(fd, &parser))
		return (ft_printf("Error in image header\n"));
//	check_bmp_parsing(parser);
	ft_printf("{red}");
	if (!(env->textures[index].surface = SDL_CreateRGBSurfaceWithFormat(
					0, parser.w, parser.h, parser.bpp,
					SDL_PIXELFORMAT_ARGB8888)))
		return (ft_printf("SDL_CreateRGBSurface error: %s\n",
		SDL_GetError()));
	env->textures[index].str = env->textures[index].surface->pixels;
	env->textures[index].scale = 1;
	env->textures[index].xpadding = 0;
	env->textures[index].ypadding = 0;
	if (parser.color_used || parser.bpp <= 8)
	{
		if (set_color_table(fd, &parser))
			return (ft_printf("Error in color table\n"));
	}
	//check_bmp_parsing(parser);
	if (parse_pixel_data(fd, &parser, index, env))
		return (ft_printf("Error in pixel data\n"));
	//check_bmp_parsing(parser);
	return (0);
}

/*
**	Init function:
**	-Create a new SDL surface to store the image
**	-Open the given file
**	-Parse it
**	-Close the file
*/

int			parse_bmp(char *file, int index, t_env *env)
{
	int	fd;

	//ft_printf("Parsing \"%s\"\n{red}", file);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_printf("Could not open \"%s\"\n", file));
	if (parse(fd, index, env))
		return (ft_printf("Error while parsing \"%s\"\n", file));
	if (close(fd))
		return (ft_printf("Could not close \"%s\"\n", file));
	ft_printf("{reset}");
	return (0);
}
