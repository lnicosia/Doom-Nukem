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
		return (custom_error("Error in init wwall sprites textures"));
	if (init_editor_sprites(env))
		return (custom_error("Error in init editor sprites textures"));
	return (0);
}

/*int		init_textures(t_env *env)
{
	if (init_ui_textures(env))
		return (-1);
	if (init_wall_textures(env))
		return (-1);
	if (init_wall_textures1(env))
		return (-1);
	if (init_wall_textures2(env))
		return (-1);
	if (init_skyboxes_textures(env))
		return (-1);
	if (init_skyboxes_textures1(env))
		return (-1);
	if (init_skyboxes_textures2(env))
		return (-1);
	if (init_skyboxes_textures3(env))
		return (-1);
	if (init_skyboxes_textures4(env))
		return (-1);
	if (init_skyboxes_textures5(env))
		return (-1);
	if (init_sprites_textures(env))
		return (-1);
	if (init_hud_textures(env))
		return (-1);
	if (init_hud_textures1(env))
		return (-1);
	if (init_hud_textures2(env))
		return (-1);
	if (init_hud_textures3(env))
		return (-1);
	if (init_hud_textures4(env))
		return (-1);
	if (init_hud_textures5(env))
		return (-1);
	if (init_hud_textures6(env))
		return (-1);
	if (init_hud_textures7(env))
		return (-1);
	if (init_hud_textures8(env))
		return (-1);
	if (init_hud_textures9(env))
		return (-1);
	if (init_mini_skyboxes_selection(env))
		return (-1);
	if (init_mini_skyboxes_selection2(env))
		return (-1);
}*/

void	init_textures(t_env *env)
{
	init_ui_textures(env);
	init_wall_textures(env);
	init_wall_textures1(env);
	init_wall_textures2(env);
	init_skyboxes_textures(env);
	init_skyboxes_textures1(env);
	init_skyboxes_textures2(env);
	init_skyboxes_textures3(env);
	init_skyboxes_textures4(env);
	init_skyboxes_textures5(env);
	init_sprites_textures(env);
	init_hud_textures(env);
	init_hud_textures1(env);
	init_hud_textures2(env);
	init_hud_textures3(env);
	init_hud_textures4(env);
	init_hud_textures5(env);
	init_hud_textures6(env);
	init_hud_textures7(env);
	init_hud_textures8(env);
	init_hud_textures9(env);
	init_mini_skyboxes_selection(env);
	init_mini_skyboxes_selection2(env);
}
