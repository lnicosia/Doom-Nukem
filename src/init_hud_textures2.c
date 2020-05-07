/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_textures2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:32:22 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/16 15:06:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		init_hud_textures5(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (!(env->init.hud_names[19] = ft_strdup("images/HUD/raygun5.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/raygun5.bmp", start + 19, env))
		env->init.hud[19] = 1;
	if (!(env->init.hud_names[20] = ft_strdup("images/HUD/raygun6.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/raygun6.bmp", start + 20, env))
		env->init.hud[20] = 1;
	if (!(env->init.hud_names[21] = ft_strdup("images/HUD/raygun7.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/raygun7.bmp", start + 21, env))
		env->init.hud[21] = 1;
	return (0);
}

int		init_hud_textures6(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (!(env->init.hud_names[22] = ft_strdup("images/HUD/gun_1.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gun_1.bmp", start + 22, env))
		env->init.hud[22] = 1;
	if (!(env->init.hud_names[23] = ft_strdup("images/HUD/gun_2.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gun_2.bmp", start + 23, env))
		env->init.hud[23] = 1;
	if (!(env->init.hud_names[24] = ft_strdup("images/HUD/gun_3.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gun_3.bmp", start + 24, env))
		env->init.hud[24] = 1;
	if (!(env->init.hud_names[25] = ft_strdup("images/HUD/gun_4.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gun_4.bmp", start + 25, env))
		env->init.hud[25] = 1;
	return (0);
}

int		init_hud_textures7(t_env *env)
{
	int	start;

	start = env->hud_start;
	if (!(env->init.hud_names[26] = ft_strdup("images/HUD/gun_5.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gun_5.bmp", start + 26, env))
		env->init.hud[26] = 1;
	if (!(env->init.hud_names[27] = ft_strdup("images/HUD/gun_6.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gun_6.bmp", start + 27, env))
		env->init.hud[27] = 1;
	if (!(env->init.hud_names[28] = ft_strdup("images/HUD/gatling_1.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gatling_1.bmp", start + 28, env))
		env->init.hud[28] = 1;
	if (!(env->init.hud_names[29] = ft_strdup("images/HUD/gatling_2.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gatling_2.bmp", start + 29, env))
		env->init.hud[29] = 1;
	return (0);
}

int		init_hud_textures8(t_env *env)
{
	int start;
	
	start = env->hud_start;
	if (!(env->init.hud_names[30] = ft_strdup("images/HUD/gatling_3.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gatling_3.bmp", start + 30, env))
		env->init.hud[30] = 1;
	if (!(env->init.hud_names[31] = ft_strdup("images/HUD/gatling_4.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gatling_4.bmp", start + 31, env))
		env->init.hud[31] = 1;
	if (!(env->init.hud_names[32] = ft_strdup("images/HUD/gatling_5.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gatling_5.bmp", start + 32, env))
		env->init.hud[32] = 1;
	if (!(env->init.hud_names[33] = ft_strdup("images/HUD/gatling_6.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/gatling_6.bmp", start + 33, env))
		env->init.hud[33] = 1;
	return (0);
}

int		init_hud_textures9(t_env *env)
{
	int start;
	
	start = env->hud_start;
	if (!(env->init.hud_names[34] = ft_strdup("images/HUD/Ammo_hud.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/Ammo_hud.bmp", start + 34, env))
		env->init.hud[34] = 1;
	if (!(env->init.hud_names[35] = ft_strdup("images/HUD/Life_armor_hud.bmp")))
		return (ft_printf("Error while parsing hud textures\n"));
	if (parse_bmp("images/HUD/Life_armor_hud.bmp", start + 35, env))
		env->init.hud[35] = 1;
	return (0);
}