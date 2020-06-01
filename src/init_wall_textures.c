/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:56:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/15 20:03:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		init_wall_textures5(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/cratop2.bmp", 48, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/door1.bmp", 49, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/door3.bmp", 50, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/doorblu.bmp", 51, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/doorblu2.bmp", 52, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/doorred.bmp", 53, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/doorred2.bmp", 54, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/doorstop.bmp", 55, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/doortrak.bmp", 56, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/dooryel.bmp", 57, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/dooryel2.bmp", 58, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/exitsign.bmp", 59, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures6(env));
}

int		init_wall_textures4(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/cement1.bmp", 36, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/cement2.bmp", 37, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/cement3.bmp", 38, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/cement4.bmp", 39, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/cement5.bmp", 40, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/cement6.bmp", 41, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/cement7.bmp", 42, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/cement8.bmp", 43, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/cement9.bmp", 44, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/comptall.bmp", 45, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/compwerd.bmp", 46, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/cratop1.bmp", 47, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures5(env));
}

int		init_wall_textures3(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/blood1.bmp", 24, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/blood2.bmp", 25, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/blood3.bmp", 26, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bronze1.bmp", 27, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bronze2.bmp", 28, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bronze3.bmp", 29, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bronze4.bmp", 30, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/brovine2.bmp", 31, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/ceil1_1.bmp", 32, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/ceil1_2.bmp", 33, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/ceil1_3.bmp", 34, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/ceil3_4.bmp", 35, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures4(env));
}

int		init_wall_textures2(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/tiles.bmp", 12, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/sand.bmp", 13, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/grey.bmp", 14, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/menu_texture.bmp", 15, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wall4.bmp", 16, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bigdoor1.bmp", 17, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bigdoor2.bmp", 18, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bigdoor3.bmp", 19, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bigdoor4.bmp", 20, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bigdoor5.bmp", 21, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bigdoor6.bmp", 22, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/bigdoor7.bmp", 23, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures3(env));
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
	if (parse_bmp_wall_textures("./images/textures/rust.bmp", 6, env))
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
