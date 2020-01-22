/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor_tab_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:41:32 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/22 09:33:57 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	change_var(void *target)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab *)target;
	env = button->env;
	new_input_var(&env->input_box, button->pos,
	button->type, button->target);
}

void	init_wall_buttons(t_env *env)
{
	init_wall_general_env(env);
	init_wall_sector_env(env);
//	init_wall_sprite_env(env);
	init_wall_general_buttons(env);
	init_wall_sector_buttons(env);
	init_wall_sprite_buttons(env);
}

void	init_floor_buttons(t_env *env)
{
	init_floor_general_env(env);
	init_floor_sector_env(env);
//	init_floor_sprite_env(env);
	init_floor_general_buttons(env);
	init_floor_sector_buttons(env);
	init_floor_sprite_buttons(env);
}

void	init_ceilling_buttons(t_env *env)
{
	init_ceilling_general_env(env);
	init_ceilling_sector_env(env);
//	init_ceilling_sprite_env(env);
	init_ceilling_general_buttons(env);
	init_ceilling_sector_buttons(env);
	init_ceilling_sprite_buttons(env);
}

void	init_sector_buttons(t_env *env)
{
	init_sector_general_env(env);
	init_sector_general_buttons(env);
}

void	init_editor_tab_buttons(t_env *env)
{
	init_wall_buttons(env);
	init_floor_buttons(env);
	init_ceilling_buttons(env);
	init_sector_buttons(env);
	//init_player_buttons(env);
	//init_object_buttons(env);
	//init_enemy_buttons(env);
}