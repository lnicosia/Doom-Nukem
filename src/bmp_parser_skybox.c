/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser_skybox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:51:34 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/17 16:48:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

static int	parse_skybox_textures(int fd, int num_sky, int index, t_env *env)
{
	t_bmp_parser	parser;

	if (index >= 6)
		return (ft_printf("Too much textures\n"));
	if (parse_file_header(fd, &parser))
		return (ft_printf("Error in file header\n"));
	if (get_image_header_size(fd, &parser))
		return (ft_printf("Error in image header\n"));
	if (parse_image_header(fd, &parser))
		return (ft_printf("Error in image header\n"));
//	check_bmp_parsing(parser);
	ft_printf("{red}");
	if (!(env->skyboxes[num_sky].textures[index].surface = SDL_CreateRGBSurfaceWithFormat(
					0,
					parser.w,
					parser.h,
					parser.bpp,
					SDL_PIXELFORMAT_ARGB8888)))
		return (ft_printf("SDL_CreateRGBSurface error: %s\n", SDL_GetError()));
	env->skyboxes[num_sky].textures[index].str = env->skyboxes[num_sky].textures[index].surface->pixels;
	env->skyboxes[num_sky].textures[index].scale = 1;
	env->skyboxes[num_sky].textures[index].xpadding = 0;
	env->skyboxes[num_sky].textures[index].ypadding = 0;
	if (parser.color_used || parser.bpp <= 8)
	{
		if (set_color_table(fd, &parser))
			return (ft_printf("Error in color table\n"));
	}
	//check_bmp_parsing(parser);
	if (parse_pixel_data_skybox(fd, &parser, num_sky, index, env))
		return (ft_printf("Error in pixel data\n"));
	//check_bmp_parsing(parser);
	return (0);
}

int			parse_bmp_skybox_textures(char *file, int num_sky, int index, t_env *env)
{
	int	fd;

	//ft_printf("Parsing \"%s\"\n{red}", file);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_printf("Could not open \"%s\"\n", file));
	if (parse_skybox_textures(fd, num_sky, index, env))
		return (ft_printf("Error while parsing \"%s\"\n", file));
	if (close(fd))
		return (ft_printf("Could not close \"%s\"\n", file));
	ft_printf("{reset}");
	return (0);
}
