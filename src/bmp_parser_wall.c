/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:51:04 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/14 17:08:38 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

static int	parse_wall_textures2(int fd, t_bmp_parser *parser, t_env *env)
{
	if (parser->color_used || parser->bpp <= 8)
	{
		if (set_color_table(fd, parser))
			return (ft_printf("Error in color table\n"));
	}
	if (parse_pixel_data(fd, parser, env->wall_textures))
		return (ft_printf("Error in pixel data\n"));
	return (0);
}

static int	parse_wall_textures(int fd, int index, t_env *env)
{
	t_bmp_parser	parser;

	parser.index = index;
	if (index >= MAX_WALL_TEXTURE)
		return (ft_printf("Too much textures\n"));
	if (parse_file_header(fd, &parser))
		return (ft_printf("Error in file header\n"));
	if (get_image_header_size(fd, &parser))
		return (ft_printf("Error in image header\n"));
	if (parse_image_header(fd, &parser))
		return (ft_printf("Error in image header\n"));
	ft_printf("{red}");
	if (!(env->wall_textures[index].surface = SDL_CreateRGBSurfaceWithFormat(
					0,
					parser.w,
					parser.h,
					parser.bpp,
					SDL_PIXELFORMAT_ARGB8888)))
		return (ft_printf("SDL_CreateRGBSurface error: %s\n", SDL_GetError()));
	env->wall_textures[index].str = env->wall_textures[index].surface->pixels;
	env->wall_textures[index].scale = 1;
	env->wall_textures[index].xpadding = 0;
	env->wall_textures[index].ypadding = 0;
	return (parse_wall_textures2(fd, &parser, env));
}

int			parse_bmp_wall_textures(char *file, int index, t_env *env)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_printf("Could not open \"%s\"\n", file));
	if (parse_wall_textures(fd, index, env))
		return (ft_printf("Error while parsing \"%s\"\n", file));
	if (close(fd))
		return (ft_printf("Could not close \"%s\"\n", file));
	ft_printf("{reset}");
	return (0);
}
