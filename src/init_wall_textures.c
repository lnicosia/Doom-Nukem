/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:56:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/12 17:43:57 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		init_wall_textures2(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/tiles.bmp", 12, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/sand.bmp", 13, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/grey.bmp", 14, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}

int		init_wall_textures(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/wall0.bmp", 0, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wall1.bmp", 1, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wall2.bmp", 2, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wall3.bmp", 3, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/floor0.bmp", 4, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/floor1.bmp", 5, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/menu_texture.bmp", 6, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/black_tiles.bmp", 7, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/rock.bmp", 8, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/grass1.bmp", 9, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/grass2.bmp", 10, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/grass3.bmp", 11, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures2(env));
}
