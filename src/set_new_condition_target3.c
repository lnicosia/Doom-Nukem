/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_condition_target3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:31:28 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 15:03:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

void		set_condition_buttons_state2(t_env *env)
{
	if (env->editor.condition_panel.target_panel.player_type)
		set_player_panel_buttons_state(&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
	if (env->editor.condition_panel.target_panel.vertex_type)
		set_vertex_panel_buttons_state(&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
	if (env->editor.condition_panel.target_panel.sector_other_type)
		set_sector_other_panel_buttons_state(
		&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
}

void		set_condition_buttons_state(t_env *env)
{
	if (env->editor.condition_panel.target_panel.floor_type)
		set_floor_panel_buttons_state(&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
	if (env->editor.condition_panel.target_panel.ceiling_type)
		set_ceiling_panel_buttons_state(&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
	if (env->editor.condition_panel.target_panel.wall_type)
		set_wall_panel_buttons_state(&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
	if (env->editor.condition_panel.target_panel.wall_sprite_type)
		set_wall_sprite_panel_buttons_state(
		&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
	if (env->editor.condition_panel.target_panel.weapon_type)
		set_weapon_panel_buttons_state(&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
	if (env->editor.condition_panel.target_panel.enemy_type)
		set_enemy_panel_buttons_state(&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
	if (env->editor.condition_panel.target_panel.object_type)
		set_object_panel_buttons_state(&env->editor.condition_panel.target_panel,
		env->editor.condition_panel.condition.target_index);
	set_condition_buttons_state2(env);
}

int			set_condition_wall_sprite2(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int wall)
{
	int	sector;
	int	sprite;

	sector = env->editor.selected_sector;
	sprite = env->selected_wall_sprite_sprite;
	if (target_panel->selected_button == 3)
	{
		panel->condition.target =
		&env->sectors[sector].wall_sprites[wall].scale[sprite].x;
		panel->condition.target_index = SECTOR_WALL_SPRITES_SCALE_X;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->condition.target =
		&env->sectors[sector].wall_sprites[wall].scale[sprite].y;
		panel->condition.target_index = SECTOR_WALL_SPRITES_SCALE_Y;
	}
	panel->condition.sector = sector;
	panel->condition.wall = wall;
	panel->condition.sprite = sprite;
	return (0);
}

int			set_condition_wall_sprite(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int wall)
{
	int	sector;
	int	sprite;

	sector = env->editor.selected_sector;
	sprite = env->selected_wall_sprite_sprite;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target =
		&env->sectors[sector].wall_sprites[wall].sprite[sprite];
		panel->condition.target_index = SECTOR_WALL_SPRITES_SPRITE;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target =
		&env->sectors[sector].wall_sprites[wall].pos[sprite].x;
		panel->condition.target_index = SECTOR_WALL_SPRITES_POS_X;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target =
		&env->sectors[sector].wall_sprites[wall].pos[sprite].y;
		panel->condition.target_index = SECTOR_WALL_SPRITES_POS_Y;
	}
	return (set_condition_wall_sprite2(env, panel, target_panel, wall));
}

int			select_wall_sprite_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel)
{
	if (env->selected_wall_sprite_wall != -1)
		return (set_condition_wall_sprite(env, panel, target_panel,
		env->selected_wall_sprite_wall));
	else if (env->selected_floor != -1)
		return (set_condition_floor_sprite(env, panel, target_panel,
		env->selected_floor));
	else if (env->selected_ceiling != -1)
		return (set_condition_ceiling_sprite(env, panel, target_panel,
		env->selected_ceiling));
		return (0);
}
