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
	if (init_ui_textures(env))
		return (custom_error("Could not init ui textures\n"));
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
	return (0);
}