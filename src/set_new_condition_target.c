/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_condition_target.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:07:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 10:14:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		select_floor_condition_target2(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int sector)
{
	if (target_panel->selected_button == 3)
	{
		panel->condition.target = &env->sectors[sector].floor_map_align.x;
		panel->condition.target_index = SECTOR_FLOOR_ALIGN_X;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->condition.target = &env->sectors[sector].floor_map_align.y;
		panel->condition.target_index = SECTOR_FLOOR_ALIGN_Y;
	}
	else if (target_panel->selected_button == 5)
	{
		panel->condition.target = &env->sectors[sector].floor_map_scale.x;
		panel->condition.target_index = SECTOR_FLOOR_SCALE_X;
	}
	else if (target_panel->selected_button == 6)
	{
		panel->condition.target = &env->sectors[sector].floor_map_scale.y;
		panel->condition.target_index = SECTOR_FLOOR_SCALE_Y;
	}
	panel->condition.target_sector = sector;
	return (0);
}

int		select_floor_condition_target(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	int	sector;

	sector = env->editor.selected_sector == -1 ? env->selected_floor : env->
	editor.selected_sector;
	if (target_panel->selected_button == 1)
		panel->condition.target_type = INT;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target = &env->sectors[sector].floor;
		panel->condition.target_index = SECTOR_FLOOR_HEIGHT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target = &env->sectors[sector].floor_texture;
		panel->condition.target_index = SECTOR_FLOOR_TEXTURE;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target = &env->sectors[sector].floor_slope;
		panel->condition.target_index = SECTOR_FLOOR_SLOPE;
	}
	return (select_floor_condition_target2(env, panel, target_panel, sector));
}

int		select_ceiling_condition_target2(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int sector)
{
	if (target_panel->selected_button == 3)
	{
		panel->condition.target = &env->sectors[sector].ceiling_map_align.x;
		panel->condition.target_index = SECTOR_CEILING_ALIGN_X;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->condition.target = &env->sectors[sector].ceiling_map_align.y;
		panel->condition.target_index = SECTOR_CEILING_ALIGN_Y;
	}
	else if (target_panel->selected_button == 5)
	{
		panel->condition.target = &env->sectors[sector].ceiling_map_scale.x;
		panel->condition.target_index = SECTOR_CEILING_SCALE_X;
	}
	else if (target_panel->selected_button == 6)
	{
		panel->condition.target = &env->sectors[sector].ceiling_map_scale.y;
		panel->condition.target_index = SECTOR_CEILING_SCALE_Y;
	}
	panel->condition.target_sector = sector;
	return (0);
}

int		select_ceiling_condition_target(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	int	sector;

	sector = env->editor.selected_sector == -1 ? env->selected_ceiling : env->
	editor.selected_sector;
	if (target_panel->selected_button == 1)
		panel->condition.target_type = INT;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target = &env->sectors[sector].ceiling;
		panel->condition.target_index = SECTOR_CEILING_HEIGHT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target = &env->sectors[sector].ceiling_texture;
		panel->condition.target_index = SECTOR_CEILING_TEXTURE;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target = &env->sectors[sector].ceiling_slope;
		panel->condition.target_index = SECTOR_CEILING_SLOPE;
	}
	return (select_ceiling_condition_target2(env, panel, target_panel, sector));
}

int		set_new_condition_target2(t_env *env, t_condition_panel *panel)
{
	if (panel->target_panel.enemy_type)
		return (select_enemy_condition_target(env, panel,
		&panel->target_panel));
	else if (panel->target_panel.object_type)
		return (select_object_condition_target(env, panel,
		&panel->target_panel));
	else if (panel->target_panel.sector_other_type)
		return (select_sector_other_condition_target(env, panel,
		&panel->target_panel));
		return (0);
}

int		set_new_condition_target(t_env *env)
{
	t_condition_panel	*panel;

	panel = &env->editor.condition_panel;
	env->editor.condition_panel.condition.target_type = DOUBLE;
	if (panel->target_panel.floor_type)
		return (select_floor_condition_target(env, panel,
		&panel->target_panel));
	else if (panel->target_panel.ceiling_type)
		return (select_ceiling_condition_target(env, panel,
		&panel->target_panel));
	else if (panel->target_panel.wall_type)
		return (select_wall_condition_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.wall_sprite_type)
		return (select_wall_sprite_condition_target(env, panel,
		&panel->target_panel));
	else if (panel->target_panel.vertex_type)
		return (select_vertex_condition_target(env, panel,
		&panel->target_panel));
	else if (panel->target_panel.weapon_type)
		return (select_weapon_condition_target(env, panel,
		&panel->target_panel));
	else if (panel->target_panel.player_type)
		return (select_player_condition_target(env, panel,
		&panel->target_panel));
		return (set_new_condition_target2(env, panel));
}
