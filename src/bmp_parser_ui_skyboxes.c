/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser_ui_skyboxes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:04:26 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/11 15:17:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

static int	parse_mini_skyboxes_textures2(int fd, t_bmp_parser *parser,
t_env *env)
{
	if (parser->color_used || parser->bpp <= 8)
	{
		if (set_color_table(fd, parser))
			return (custom_error("Error in color table\n"));
	}
	if (parse_pixel_data(fd, parser, env->mini_skyboxes))
		return (custom_error("Error in pixel data\n"));
	return (0);
}

static int	parse_mini_skyboxes_textures(int fd, int index, t_env *env)
{
	t_bmp_parser	parser;

	parser.index = index;
	if (index >= MAX_SKYBOX + MAX_SKYBOX)
		return (custom_error("Too much textures\n"));
	if (parse_file_header(fd, &parser))
		return (custom_error("Error in file header\n"));
	if (get_image_header_size(fd, &parser))
		return (custom_error("Error in image header\n"));
	if (parse_image_header(fd, &parser))
		return (custom_error("Error in image header\n"));
	ft_printf("{red}");
	if (!(env->mini_skyboxes[index].surface = SDL_CreateRGBSurfaceWithFormat(
		0, parser.w, parser.h, parser.bpp, SDL_PIXELFORMAT_ARGB8888)))
		return (custom_error("SDL_CreateRGBSurface error: %s\n",
		SDL_GetError()));
		env->mini_skyboxes[index].str =
		env->mini_skyboxes[index].surface->pixels;
	env->mini_skyboxes[index].scale = 1;
	env->mini_skyboxes[index].xpadding = 0;
	env->mini_skyboxes[index].ypadding = 0;
	return (parse_mini_skyboxes_textures2(fd, &parser, env));
}

int			parse_bmp_mini_skyboxes_textures(char *file, int index, t_env *env)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (custom_error("Could not open \"%s\"\n", file));
	if (parse_mini_skyboxes_textures(fd, index, env))
	{
		if (close(fd))
			return (ft_perror("Mini skyboxe parsing failed and could not close"
			" the file\n"));
		return (custom_error("Error while parsing \"%s\"\n", file));
	}
	if (close(fd))
		return (custom_error("Could not close \"%s\"\n", file));
	ft_printf("{reset}");
	return (0);
}
