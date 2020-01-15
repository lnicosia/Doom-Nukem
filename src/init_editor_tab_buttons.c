/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor_tab_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:41:32 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/15 15:48:45 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	change_var(void *target)
{
	t_button_tab	*button;
	t_env			*env;

	env = button->env;
	button = (t_button_tab *)target;
	new_input_var(&env->input_box, button->pos,
	button->type, button->target);
}

void	init_wall_buttons(t_env *env)
{
	env->editor.hud.wall_texture = new_hud_button(WHEN_DOWN, &chage_var, env, env);
	env->editor.hud.wall_texture.pos = new_point();
}

void	init_editor_tab_buttons(t_env *env)
{
	init_wall_buttons(env);
	init_floor_buttons(env);
	init_ceilling_buttons(env);
	init_player_buttons(env);
	init_sector_buttons(env);
	init_object_buttons(env);
	init_enemy_buttons(env);
}