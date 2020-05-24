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
	if (parse_bmp("images/HUD/shot12.bmp", 11, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot13.bmp", 12, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot14.bmp", 13, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot15.bmp", 14, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}

int		init_shotgun(t_env *env)
{
	if (parse_bmp("images/HUD/shot1.bmp", 0, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot2.bmp", 1, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot3.bmp", 2, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot4.bmp", 3, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot5.bmp", 4, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot6.bmp", 5, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot7.bmp", 6, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot8.bmp", 7, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot9.bmp", 8, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot10.bmp", 9, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/shot11.bmp", 10, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_shotgun2(env));
}

int		init_raygun(t_env *env)
{
	if (parse_bmp("images/HUD/raygun1.bmp", 15, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun2.bmp", 16, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun3.bmp", 17, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun4.bmp", 18, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun5.bmp", 19, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun6.bmp", 20, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/raygun7.bmp", 21, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}

int		init_gun(t_env *env)
{
	if (parse_bmp("images/HUD/gun_1.bmp", 40, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_2.bmp", 41, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_3.bmp", 42, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_4.bmp", 43, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_5.bmp", 44, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/gun_6.bmp", 45, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}

int		init_gatling(t_env *env)
{
	if (parse_bmp("images/HUD/Gatling/Gatling_1.bmp", 46, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_2.bmp", 47, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_3.bmp", 48, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_4.bmp", 49, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_5.bmp", 50, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Gatling/Gatling_6.bmp", 51, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}
