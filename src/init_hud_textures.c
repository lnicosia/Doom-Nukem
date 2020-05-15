/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:09:46 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/16 15:11:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		init_hud_textures4(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (parse_bmp("images/HUD/Gatling_2.bmp", start + 29, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling_3.bmp", start + 30, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling_4.bmp", start + 31, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling_5.bmp", start + 32, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling_6.bmp", start + 33, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Ammo_hud.bmp", start + 34, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Life_armor_hud.bmp", start + 35, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}

int		init_hud_textures3(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (parse_bmp("images/HUD/raygun5.bmp", start + 19, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun6.bmp", start + 20, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun7.bmp", start + 21, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_1.bmp", start + 22, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_2.bmp", start + 23, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_3.bmp", start + 24, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_4.bmp", start + 25, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_5.bmp", start + 26, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_6.bmp", start + 27, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling_1.bmp", start + 28, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_hud_textures4(env));
}

int		init_hud_textures2(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (parse_bmp("images/HUD/shot11.bmp", start + 10, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot12.bmp", start + 11, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot13.bmp", start + 12, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot14.bmp", start + 13, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot15.bmp", start + 14, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun1.bmp", start + 15, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun2.bmp", start + 16, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun3.bmp", start + 17, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun4.bmp", start + 18, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_hud_textures3(env));
}

int		init_hud_textures(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (parse_bmp("images/HUD/shot1.bmp", start + 0, env))
		return (custom_error("Invalid bmp file\n"));
 	if (parse_bmp("images/HUD/shot2.bmp", start + 1, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot3.bmp", start + 2, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot4.bmp", start + 3, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot5.bmp", start + 4, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot6.bmp", start + 5, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot7.bmp", start + 6, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot8.bmp", start + 7, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot9.bmp", start + 8, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot10.bmp", start + 9, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_hud_textures2(env));
}
