/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:30:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 19:10:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

/*
** Init images needed for game menu
*/

int		init_game_ui_textures(t_env *env)
{
	if (parse_bmp_ui_textures("images/ui/hud-button-up.bmp", 39, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/hud-button-pressed.bmp", 40, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/hud-button-hover.bmp", 41, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/minus-button-up.bmp", 21, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/minus-button-pressed.bmp", 22, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/minus-button-hover.bmp", 23, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/add_button.bmp", 35, env))
		return (custom_error("Invalid bmp files\n"));
	return (0);
}

int		init_sprites_textures(t_env *env)
{
	if (init_enemies_sprites_textures(env))
		return (custom_error("Error in init enemies sprites textures"));
	if (init_objects_sprites_textures(env))
		return (custom_error("Error in init obejcts sprites textures"));
	if (init_wall_sprites_textures(env))
		return (custom_error("Error in init wall sprites textures"));
	if (init_editor_sprites(env))
		return (custom_error("Error in init editor sprites textures"));
	return (0);
}

int		init_textures(t_env *env)
{
	if (!env->playing && init_ui_textures(env))
		return (custom_error("Could not init ui textures\n"));
	if (init_game_ui_textures(env))
		return (custom_error("Could not init game menu ui textures\n"));
	if (init_wall_textures(env))
		return (custom_error("Could not init walls textures\n"));
	if (init_skyboxes_textures(env))
		return (custom_error("Could not init skyboxes textures\n"));
	if (init_skyboxes_textures1(env))
		return (custom_error("Could not init skyboxes textures\n"));
	if (init_sprites_textures(env))
		return (custom_error("Could not init sprites tetxures\n"));
	if (init_hud_textures(env))
		return (custom_error("Could not init hud textures\n"));
	if (init_mini_skyboxes_selection(env))
		return (custom_error("Could not init hud textures\n"));
	return (0);
}
