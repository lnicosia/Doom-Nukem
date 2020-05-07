/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:10:54 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/30 12:12:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		init_shotgun2(t_env *env)
{
	if (parse_bmp("images/HUD/shot12.bmp", env->hud_start + 11, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot13.bmp", env->hud_start + 12, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot14.bmp", env->hud_start + 13, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot15.bmp", env->hud_start + 14, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}

int		init_shotgun(t_env *env)
{
	if (parse_bmp("images/HUD/shot1.bmp", env->hud_start + 0, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot2.bmp", env->hud_start + 1, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot3.bmp", env->hud_start + 2, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot4.bmp", env->hud_start + 3, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot5.bmp", env->hud_start + 4, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot6.bmp", env->hud_start + 5, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot7.bmp", env->hud_start + 6, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot8.bmp", env->hud_start + 7, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot9.bmp", env->hud_start + 8, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot10.bmp", env->hud_start + 9, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot11.bmp", env->hud_start + 10, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_shotgun2(env));
}

int		init_raygun(t_env *env)
{
	if (parse_bmp("images/HUD/raygun1.bmp", env->hud_start + 15, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun2.bmp", env->hud_start + 16, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun3.bmp", env->hud_start + 17, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun4.bmp", env->hud_start + 18, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun5.bmp", env->hud_start + 19, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun6.bmp", env->hud_start + 20, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun7.bmp", env->hud_start + 21, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}

int		init_gun(t_env *env)
{
	if (parse_bmp("images/HUD/gun_1.bmp", env->hud_start + 22, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_2.bmp", env->hud_start + 23, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_3.bmp", env->hud_start + 24, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_4.bmp", env->hud_start + 25, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_5.bmp", env->hud_start + 26, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_6.bmp", env->hud_start + 27, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}

int		init_gatling(t_env *env)
{
	if (parse_bmp("images/HUD/Gatling/Gatling_1.bmp", env->hud_start + 28, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_2.bmp", env->hud_start + 29, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_3.bmp", env->hud_start + 30, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_4.bmp", env->hud_start + 31, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_5.bmp", env->hud_start + 32, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_6.bmp", env->hud_start + 33, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}
