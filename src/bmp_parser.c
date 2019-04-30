/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:52 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/30 15:27:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bmp_parser.h"

static int	parse_header(int fd, int debug, t_bmp_parser *parser, t_env *env)
{
	int				ret;
	unsigned char	header[14];

	(void)debug;
	(void)env;
	if ((ret = read(fd, header, 14)) > 0)
	{
		if ((header[0] && header[0] != 'B') || (header[1] && header[1] != 'M'))
			return (ft_printf("File type is missing\n"));
		parser->size = read_int(header, 2);
		if (debug)
			ft_printf("File size = %d\n", parser->size);
	}
	else if (!ret)
		return (ft_printf("File only contains header\n"));
	else
		return (ft_printf("Error while reading the header \n"));
	if (ret != 14)
		return (ft_printf("Header is not valid\n"));
	return (0);
}

static int	parse(int fd, int debug, t_env *env)
{
	t_bmp_parser	parser;

	parser.size = 0;
	if (parse_header(fd, debug, &parser, env))
		return (ft_printf("Error in file header\n"));
	return (0);
}

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
	ft_printf("{reset}");
	return (0);
}
