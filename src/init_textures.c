/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:30:20 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/09 16:46:42 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_shotgun(t_env *env)
{
	if (parse_bmp("images/shotgun/shot1.bmp", 6, env))
		return (ft_printf("Invalid bmp file\n"));
 	if (parse_bmp("images/shotgun/shot2.bmp", 7, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot3.bmp", 8, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot4.bmp", 9, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot5.bmp", 10, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot6.bmp", 11, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot7.bmp", 12, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot8.bmp", 13, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot9.bmp", 14, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot10.bmp", 15, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot11.bmp", 16, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot12.bmp", 17, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot13.bmp", 18, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot14.bmp", 19, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/shotgun/shot15.bmp", 20, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}

int		init_raygun(t_env *env)
{
	if (parse_bmp("images/raygun/raygun1.bmp", 21, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/raygun/raygun2.bmp", 22, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/raygun/raygun3.bmp", 23, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/raygun/raygun4.bmp", 24, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/raygun/raygun5.bmp", 25, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/raygun/raygun6.bmp", 26, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/raygun/raygun7.bmp", 27, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}

int		init_wallpapers_and_buttons(t_env *env)
{
	if (parse_bmp("images/wallpaper1.bmp", 28, env))
		return (ft_printf("invalid bmp file\n"));
	if (parse_bmp("images/wallpaper2.bmp", 29, env))
		return (ft_printf("invalid bmp file\n"));
	if (parse_bmp("images/left.bmp", 30, env))
		return (ft_printf("invalid bmp file\n"));
	if (parse_bmp("images/right.bmp", 31, env))
		return (ft_printf("invalid bmp file\n"));
	if (parse_bmp("images/menu.bmp", 32, env))
		return (ft_printf("invalid bmp file\n"));
	if (parse_bmp("images/HUD/Ammo_hud.bmp", 36, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Life_armor_hud.bmp", 35, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}

int		init_skyboxes(t_env *env)
{
	if (parse_bmp("images/skyboxes/bottom.bmp", 38, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp("images/skyboxes/top.bmp", 39, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp("images/skyboxes/back.bmp", 40, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp("images/skyboxes/left.bmp", 41, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp("images/skyboxes/front.bmp", 42, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp("images/skyboxes/right.bmp", 43, env))
		return (ft_printf("Failed to load skybox\n"));
	return (0);
}

int		init_textures(t_env *env)
{
	if (parse_bmp("images/wall0.bmp", 0, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/wall1.bmp", 1, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/wall2.bmp", 2, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/wall3.bmp", 3, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/floor0.bmp", 4, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/floor1.bmp", 5, env))
		return (ft_printf("Invalid bmp file\n"));
	if (init_shotgun(env))
		return (ft_printf("Failed to load shotgun textures\n"));
	if (init_raygun(env))
		return (ft_printf("Failed to load raygun textures\n"));
	if (init_wallpapers_and_buttons(env))
		return (ft_printf("Could not load wallpapers\n"));
	if (parse_bmp("images/sprite_sheet.bmp", 33, env))
		return (ft_printf("Failed to load sprite sheet\n"));
	if (parse_bmp("images/lost_soul.bmp", 34, env))
		return (ft_printf("Failed to load sprite sheet\n"));
	if (parse_bmp("images/rust.bmp", 37, env))
		return (ft_printf("Failed to load sprite sheet\n"));
	if (init_skyboxes(env))
		return (ft_printf("Could not load skyboxes textures\n"));
	if (parse_bmp("images/cyber_demon.bmp", 44, env))
		return (ft_printf("Failed to load cyber demon sprite sheet\n"));
	return (0);
}
