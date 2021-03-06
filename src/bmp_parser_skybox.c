/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser_skybox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:51:34 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/11 15:17:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

static int	parse_skybox_textures2(int fd, t_bmp_parser *parser, t_env *env)
{
	if (parser->color_used || parser->bpp <= 8)
	{
		if (set_color_table(fd, parser))
			return (custom_error("Error in color table\n"));
	}
	if (parse_pixel_data(fd, parser,
		env->skyboxes[parser->skybox_index].textures))
		return (custom_error("Error in pixel data\n"));
	return (0);
}

static int	parse_skybox_textures(int fd, int num_sky, int index, t_env *env)
{
	t_bmp_parser	parser;

	parser.index = index;
	parser.skybox_index = num_sky;
	if (index >= 6)
		return (custom_error("Too much textures\n"));
	if (parse_file_header(fd, &parser))
		return (custom_error("Error in file header\n"));
	if (get_image_header_size(fd, &parser))
		return (custom_error("Error in image header\n"));
	if (parse_image_header(fd, &parser))
		return (custom_error("Error in image header\n"));
	ft_printf("{red}");
	if (!(env->skyboxes[num_sky].textures[index].surface =
		SDL_CreateRGBSurfaceWithFormat(0, parser.w, parser.h, parser.bpp,
		SDL_PIXELFORMAT_ARGB8888)))
		return (custom_error("SDL_CreateRGBSurface error: %s\n",
		SDL_GetError()));
		env->skyboxes[num_sky].textures[index].str =
	env->skyboxes[num_sky].textures[index].surface->pixels;
	env->skyboxes[num_sky].textures[index].scale = 1;
	env->skyboxes[num_sky].textures[index].xpadding = 0;
	env->skyboxes[num_sky].textures[index].ypadding = 0;
	return (parse_skybox_textures2(fd, &parser, env));
}

int			parse_bmp_skybox_textures(char *file, int num_sky, int index,
t_env *env)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (custom_error("Could not open \"%s\"\n", file));
	if (parse_skybox_textures(fd, num_sky, index, env))
	{
		if (close(fd))
			return (ft_perror("Skybox parsing failed and could not close the"
			" file\n"));
		return (custom_error("Error while parsing \"%s\"\n", file));
	}
	if (close(fd))
		return (custom_error("Could not close \"%s\"\n", file));
	ft_printf("{reset}");
	return (0);
}
