/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:30:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 19:00:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_skyboxes(t_env *env)
{
	if (parse_bmp_skybox_textures("images/skyboxes/night_bottom.bmp", 0, 0, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_top.bmp", 0, 1, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_back.bmp", 0, 2, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_left.bmp", 0, 3, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_front.bmp", 0, 4, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/night_right.bmp", 0, 5, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_bottom.bmp", 1, 0, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_top.bmp", 1, 1, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_back.bmp", 1, 2, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_left.bmp", 1, 3, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_front.bmp", 1, 4, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/nebula_right.bmp", 1, 5, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/bottom.bmp", 2, 0, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/top.bmp", 2, 1, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/back.bmp", 2, 2, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/left.bmp", 2, 3, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/front.bmp", 2, 4, env))
		return (ft_printf("Failed to load skybox\n"));
	if (parse_bmp_skybox_textures("images/skyboxes/right.bmp", 2, 5, env))
		return (ft_printf("Failed to load skybox\n"));
	return (0);
}

int		init_wall_textures(t_env *env)
{
	if (parse_bmp_wall_textures("images/textures/wall0.bmp", 0, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("images/textures/wall1.bmp", 1, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("images/textures/wall2.bmp", 2, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("images/textures/wall3.bmp", 3, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("images/textures/floor0.bmp", 4, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("images/textures/floor1.bmp", 5, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("images/textures/rust.bmp", 6, env))
		return (ft_printf("Failed to load rust\n"));
	if (parse_bmp_wall_textures("images/textures/black_tiles.bmp", 7, env))
		return (ft_printf("Failed to load black_tiles\n"));
	if (parse_bmp_wall_textures("images/textures/rock.bmp", 8, env))
		return (ft_printf("Failed to load rock\n"));
	if (parse_bmp_wall_textures("images/textures/grass1.bmp", 9, env))
		return (ft_printf("Failed to load grass1\n"));
	if (parse_bmp_wall_textures("images/textures/grass2.bmp", 10, env))
		return (ft_printf("Failed to load grass2\n"));
	if (parse_bmp_wall_textures("images/textures/grass3.bmp", 11, env))
		return (ft_printf("Failed to load grass3\n"));
	if (parse_bmp_wall_textures("images/textures/tiles.bmp", 12, env))
		return (ft_printf("Failed to load tiles\n"));
	if (parse_bmp_wall_textures("images/textures/sand.bmp", 13, env))
		return (ft_printf("Failed to load sand\n"));
	if (parse_bmp_wall_textures("images/textures/grey.bmp", 14, env))
		return (ft_printf("Failed to load grey\n"));
	return (0);
}

int		init_textures(t_env *env)
{
	if (init_wall_textures(env))
		return (ft_printf("Could not load Wall textures\n"));
	if (init_ui_textures(env))
		return (ft_printf("Could not load UI textures\n"));
	if (init_shotgun(env))
		return (ft_printf("Failed to load shotgun textures\n"));
	if (init_raygun(env))
		return (ft_printf("Failed to load raygun textures\n"));
	if (init_gun(env))
		return (ft_printf("Failed to load gun textures\n"));
	if (init_gatling(env))
		return (ft_printf("Failed to load gatling textures\n"));
	if (parse_bmp("images/sprites/sprite_sheet.bmp", 22, env))
		return (ft_printf("Failed to load sprite sheet\n"));
	if (parse_bmp("images/sprites/lost_soul.bmp", 23, env))
		return (ft_printf("Failed to load lost soul\n"));
	if (parse_bmp("images/sprites/cyber_demon.bmp", 24, env))
		return (ft_printf("Failed to load cyber demon sprite sheet\n"));
	if (parse_bmp("images/sprites/projectiles_sprites.bmp", 25, env))
		return (ft_printf("Failed to load projectiles sprite sheet\n"));
	if (parse_bmp("images/HUD/Ammo_hud.bmp", 26, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Life_armor_hud.bmp", 27, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/UI/button-default-up.bmp", 28, env))
		return (ft_printf("Failed to load default button\n"));
	if (parse_bmp("images/UI/button-default-pressed.bmp", 29, env))
		return (ft_printf("Failed to load default button\n"));
	if (parse_bmp("images/UI/button-default-hover.bmp", 30, env))
		return (ft_printf("Failed to load default button\n"));
	if (parse_bmp("images/sprites/MIDSPACE.bmp", 31, env))
		return (ft_printf("Failed to load midspace\n"));
	if (parse_bmp("images/sprites/button_off.bmp", 32, env))
		return (ft_printf("Failed to load midspace\n"));
	if (parse_bmp("images/sprites/button_on.bmp", 33, env))
		return (ft_printf("Failed to load midspace\n"));
	if (parse_bmp("images/sprites/objects_sprites.bmp", 34, env))
		return (ft_printf("Failed to load object sprites\n"));
	if (parse_bmp("images/sprites/bullet_hole.bmp", 35, env))
		return (ft_printf("Failed to load bullet hole sprite\n"));
	if (parse_bmp("images/sprites/doom_guy.bmp", 36, env))
		return (ft_printf("Failed to load doom guy sprite\n"));
	if (parse_bmp("images/sprites/doom_guy_face.bmp", 37, env))
		return (ft_printf("Failed to load doom guy face sprite\n"));
	if (parse_bmp("images/sprites/camera.bmp", 38, env))
		return (ft_printf("Failed to load camera sprite\n"));
	if (parse_bmp("images/sprites/raygun.bmp", 39, env))
		return (ft_printf("Failed to load raygun sprite\n"));
	if (parse_bmp("images/sprites/hd.bmp", 46, env))
		return (ft_printf("Failed to load raygun sprite\n"));
	if (init_skyboxes(env))
		return (ft_printf("Could not load skyboxes textures\n"));
	return (0);
}
