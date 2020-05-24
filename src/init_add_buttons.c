/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_buttons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:29:15 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/30 11:45:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_change_wall_buttons(t_env *env)
{
	env->editor.next_wall =
	new_next_button(WHEN_DOWN, &next_selected_wall, env, env);
	env->editor.next_wall_env.env = env;
	env->editor.next_wall.pos = new_point(350, 510);
	env->editor.next_wall_env.button_type = NEXT;
	env->editor.previous_wall =
	new_previous_button(WHEN_DOWN, &next_selected_wall, env, env);
	env->editor.previous_wall_env.env = env;
	env->editor.previous_wall.pos = new_point(30, 510);
	env->editor.previous_wall_env.button_type = PREVIOUS;
}

void	init_change_sprite_button(t_env *env)
{
	env->editor.next_sprite =
	new_next_button(WHEN_DOWN, &change_sprite, env, env);
	env->editor.next_sprite_env.env = env;
	env->editor.next_sprite.pos = new_point(320, 485);
	env->editor.next_sprite_env.button_type = NEXT;
	env->editor.previous_sprite =
	new_previous_button(WHEN_DOWN, &change_sprite, env, env);
	env->editor.previous_sprite_env.button_type = PREVIOUS;
	env->editor.previous_sprite_env.env = env;
	env->editor.previous_sprite.pos = new_point(60, 485);
}

void	init_add_object_button(t_env *env)
{
	env->editor.add_object =
	new_add_button(WHEN_DOWN, &add_object_button, env, env);
	env->editor.add_object.pos = new_point(295, 223);
}

void	init_add_enemy_button(t_env *env)
{
	env->editor.add_enemy =
	new_add_button(WHEN_DOWN, &add_enemy_button, env, env);
	env->editor.add_enemy.pos = new_point(295, 323);
}

void	init_add_buttons(t_env *env)
{
	init_add_enemy_button(env);
	init_add_object_button(env);
	init_change_sprite_button(env);
	init_change_wall_buttons(env);
	init_change_slope_direction_buttons(env);
}
