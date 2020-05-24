/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_condition_target4.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:44:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 19:29:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "parser.h"
#include "events.h"

int		select_player_condition_target3(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	if (target_panel->selected_button == 8)
	{
		panel->condition.target = &env->player.sector;
		panel->condition.target_index = PLAYER_SECTOR;
		panel->condition.target_type = INT;
	}
	return (0);
}

int		select_player_condition_target2(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	if (target_panel->selected_button == 4)
	{
		panel->condition.target = &env->player.armor;
		panel->condition.target_index = PLAYER_ARMOR;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 5)
	{
		panel->condition.target = &env->player.speed;
		panel->condition.target_index = PLAYER_SPEED;
	}
	else if (target_panel->selected_button == 6)
	{
		panel->condition.target = &env->player.invincible;
		panel->condition.target_index = PLAYER_INVINCIBLE;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 7)
	{
		panel->condition.target = &env->player.infinite_ammo;
		panel->condition.target_index = PLAYER_INFINITE_AMMO;
		panel->condition.target_type = INT;
	}
	return (select_player_condition_target3(env, panel, target_panel));
}

int		select_player_condition_target(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	if (target_panel->selected_button == 0)
	{
		panel->condition.target = &env->player.pos.x;
		panel->condition.target_index = PLAYER_X;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target = &env->player.pos.y;
		panel->condition.target_index = PLAYER_Y;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target = &env->player.pos.z;
		panel->condition.target_index = PLAYER_Z;
	}
	else if (target_panel->selected_button == 3)
	{
		panel->condition.target = &env->player.health;
		panel->condition.target_index = PLAYER_HP;
		panel->condition.target_type = INT;
	}
	return (select_player_condition_target2(env, panel, target_panel));
}

int		select_object_condition_target2(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int object)
{
	if (target_panel->selected_button == 3)
	{
		panel->condition.target = &env->objects[object].pos.z;
		panel->condition.target_index = OBJECT_Z;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->condition.target = &env->objects[object].scale;
		panel->condition.target_index = OBJECT_SCALE;
	}
	else if (target_panel->selected_button == 5)
	{
		panel->condition.target = &env->objects[object].damage;
		panel->condition.target_index = OBJECT_DAMAGE;
	}
	else if (target_panel->selected_button == 6)
	{
		panel->condition.target = &env->objects[object].health;
		panel->condition.target_index = OBJECT_HP;
	}
	panel->condition.object = object;
	return (0);
}

int		select_object_condition_target(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	int		object;

	object = env->selected_object;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target = &env->objects[object].sprite;
		panel->condition.target_index = OBJECT_SPRITE;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target = &env->objects[object].pos.x;
		panel->condition.target_index = OBJECT_X;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target = &env->objects[object].pos.y;
		panel->condition.target_index = OBJECT_Y;
	}
	return (select_object_condition_target2(env, panel, target_panel, object));
}
