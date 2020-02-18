/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_condition_target2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:07:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 17:59:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		select_enemy_condition_target3(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int enemy)
{
	if (target_panel->selected_button == 6)
	{
		panel->condition.target = &env->enemies[enemy].damage;
		panel->condition.target_index = ENEMY_DAMAGE;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 7)
	{
		panel->condition.target = &env->enemies[enemy].health;
		panel->condition.target_index = ENEMY_HP;
		panel->condition.target_type = INT;
	}
	panel->condition.enemy = enemy;
	return (0);
}

int		select_enemy_condition_target2(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int enemy)
{
	if (target_panel->selected_button == 3)
	{
		panel->condition.target = &env->enemies[enemy].pos.z;
		panel->condition.target_index = ENEMY_Z;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->condition.target = &env->enemies[enemy].scale;
		panel->condition.target_index = ENEMY_SCALE;
	}
	else if (target_panel->selected_button == 5)
	{
		panel->condition.target = &env->enemies[enemy].speed;
		panel->condition.target_index = ENEMY_SPEED;
	}
	return (select_enemy_condition_target3(env, panel, target_panel, enemy));
}

int		select_enemy_condition_target(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	int		enemy;

	enemy = env->selected_enemy;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target = &env->enemies[enemy].sprite;
		panel->condition.target_index = ENEMY_SPRITE;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target = &env->enemies[enemy].pos.x;
		panel->condition.target_index = ENEMY_X;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target = &env->enemies[enemy].pos.y;
		panel->condition.target_index = ENEMY_Y;
	}
	return (select_enemy_condition_target2(env, panel, target_panel, enemy));
}

int		select_wall_condition_target2(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int sector)
{
	int		wall;

	wall = env->editor.selected_wall;
	if (target_panel->selected_button == 3)
	{
		panel->condition.target = &env->sectors[sector].align[wall].x;
		panel->condition.target_index = SECTOR_WALL_ALIGN_Y;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->condition.target = &env->sectors[sector].scale[wall].x;
		panel->condition.target_index = SECTOR_WALL_SCALE_X;
	}
	else if (target_panel->selected_button == 5)
	{
		panel->condition.target = &env->sectors[sector].scale[wall].y;
		panel->condition.target_index = SECTOR_WALL_SCALE_Y;
	}
	panel->condition.sector = sector;
	panel->condition.wall = wall;
	return (0);
}

int		select_wall_condition_target(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	int		sector;
	int		wall;

	sector = env->editor.selected_sector;
	wall = env->editor.selected_wall;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target = &env->sectors[sector].textures[wall];
		panel->condition.target_index = SECTOR_WALL_TEXTURE;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target = &env->sectors[sector].portals[wall];
		panel->condition.target_index = SECTOR_WALL_PORTAL;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target = &env->sectors[sector].align[wall].x;
		panel->condition.target_index = SECTOR_WALL_ALIGN_X;
	}
	return (select_wall_condition_target2(env, panel, target_panel, sector));
}
