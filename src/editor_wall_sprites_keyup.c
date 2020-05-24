/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_wall_sprites_keyup.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:00:53 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 18:47:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	wall_keyup(t_env *env)
{
	wall_sprites_keyup(env,
		&env->sectors[env->editor.selected_sector].
		wall_sprites[env->selected_wall_sprite_wall].
		pos[env->selected_wall_sprite_sprite],
		&env->sectors[env->editor.selected_sector].
		wall_sprites[env->selected_wall_sprite_wall].
		scale[env->selected_wall_sprite_sprite]);
}

void	ceiling_keyup(t_env *env)
{
	wall_sprites_keyup(env,
		&env->sectors[env->selected_ceiling].
		ceiling_sprites.pos[env->selected_ceiling_sprite],
		&env->sectors[env->selected_ceiling].
		ceiling_sprites.scale[env->selected_ceiling_sprite]);
	precompute_ceiling_sprite_scales(env->selected_ceiling,
	env->selected_ceiling_sprite, env);
}

void	floor_keyup(t_env *env)
{
	wall_sprites_keyup(env,
		&env->sectors[env->selected_floor].
		floor_sprites.pos[env->selected_floor_sprite],
		&env->sectors[env->selected_floor].
		floor_sprites.scale[env->selected_floor_sprite]);
	precompute_floor_sprite_scales(env->selected_floor,
	env->selected_floor_sprite, env);
}

void	editor_wall_sprites_keyup(t_env *env)
{
	if (env->editor.in_game
			&& env->editor.selected_sector != -1
			&& env->selected_wall_sprite_wall != -1
			&& env->selected_wall_sprite_sprite != -1)
		wall_keyup(env);
	if (env->editor.in_game
			&& env->selected_ceiling != -1
			&& env->selected_ceiling_sprite != -1)
		ceiling_keyup(env);
	if (env->editor.in_game
			&& env->selected_floor != -1
			&& env->selected_floor_sprite != -1)
		floor_keyup(env);
}
