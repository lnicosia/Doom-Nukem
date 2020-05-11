/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:44:23 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/28 16:57:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

static int	parse2(int fd, t_bmp_parser *parser, t_env *env)
{
	if (parser->color_used || parser->bpp <= 8)
	{
		if (set_color_table(fd, parser))
			return (custom_error("Error in color table\n"));
	}
	if (parse_pixel_data(fd, parser, env->sprite_textures))
		return (custom_error("Error in pixel data\n"));
	return (0);
}

/*
**	Main function: parse every part of the BMP file:
**	-File header
**	-Image header
**	-Image data
*/

static int	parse(int fd, int index, t_env *env)
{
	t_bmp_parser	parser;

	parser.index = index;
	if (index >= MAX_TEXTURES)
		return (custom_error("Too much textures\n"));
	if (parse_file_header(fd, &parser))
		return (custom_error("Error in file header\n"));
	if (get_image_header_size(fd, &parser))
		return (custom_error("Error in image header\n"));
	if (parse_image_header(fd, &parser))
		return (custom_error("Error in image header\n"));
	ft_printf("{red}");
	if (!(env->sprite_textures[index].surface =
		SDL_CreateRGBSurfaceWithFormat(
		0, parser.w, parser.h, parser.bpp,
		SDL_PIXELFORMAT_ARGB8888)))
		return (ft_printf("SDL_CreateRGBSurface error: %s\n",
		SDL_GetError()));
		env->sprite_textures[index].str =
	env->sprite_textures[index].surface->pixels;
	env->sprite_textures[index].scale = 1;
	env->sprite_textures[index].xpadding = 0;
	env->sprite_textures[index].ypadding = 0;
	return (parse2(fd, &parser, env));
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

	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_printf("Could not open \"%s\"\n", file));
	if (parse(fd, index, env))
		return (ft_printf("Error while parsing \"%s\"\n", file));
	if (close(fd))
		return (ft_printf("Could not close \"%s\"\n", file));
	ft_printf("{reset}");
	return (0);
}
