/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser_ui_skyboxes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:04:26 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/07 11:43:27 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

static int	parse_mini_skyboxes_textures(int fd, int index, t_env *env)
{
	t_bmp_parser	parser;

	if (index >= MAX_SKYBOX + MAX_SKYBOX)
		return (ft_printf("Too much textures\n"));
	if (parse_file_header(fd, &parser))
		return (ft_printf("Error in file header\n"));
	if (get_image_header_size(fd, &parser))
		return (ft_printf("Error in image header\n"));
	if (parse_image_header(fd, &parser))
		return (ft_printf("Error in image header\n"));
//	check_bmp_parsing(parser);
	ft_printf("{red}");
	if (!(env->mini_skyboxes[index].surface = SDL_CreateRGBSurfaceWithFormat(
					0,
					parser.w,
					parser.h,
					parser.bpp,
					SDL_PIXELFORMAT_ARGB8888)))
		return (ft_printf("SDL_CreateRGBSurface error: %s\n", SDL_GetError()));
	env->mini_skyboxes[index].str = env->mini_skyboxes[index].surface->pixels;
	env->mini_skyboxes[index].scale = 1;
	env->mini_skyboxes[index].xpadding = 0;
	env->mini_skyboxes[index].ypadding = 0;
	if (parser.color_used || parser.bpp <= 8)
	{
		if (set_color_table(fd, &parser))
			return (ft_printf("Error in color table\n"));
	}
	//check_bmp_parsing(parser);
	if (parse_pixel_data_ui_mini_skyboxes(fd, &parser, index, env))
		return (ft_printf("Error in pixel data\n"));
	//check_bmp_parsing(parser);
	return (0);
}

int			parse_bmp_mini_skyboxes_textures(char *file, int index, t_env *env)
{
	int	fd;

	//ft_printf("Parsing \"%s\"\n{red}", file);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_printf("Could not open \"%s\"\n", file));
	if (parse_mini_skyboxes_textures(fd, index, env))
		return (ft_printf("Error while parsing \"%s\"\n", file));
	if (close(fd))
		return (ft_printf("Could not close \"%s\"\n", file));
	ft_printf("{reset}");
	return (0);
}