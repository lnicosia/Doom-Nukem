/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_condition_target6.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:04:07 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 15:04:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		select_sector_other_condition_target2(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel, int sector)
{
	if (target_panel->selected_button == 3)
	{
		panel->condition.target = &env->sectors[sector].gravity;
		panel->condition.target_index = SECTOR_GRAVITY;
	}
	panel->condition.sector = sector;
	return (0);
}

int		select_sector_other_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel)
{
	int		sector;

	sector = env->editor.selected_sector;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target = &env->sectors[sector].brightness;
		panel->condition.target_index = SECTOR_BRIGHTNESS;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target = &env->sectors[sector].light_color;
		panel->condition.target_index = SECTOR_LIGHT_COLOR;
		panel->condition.target_type = UINT32;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target = &env->sectors[sector].intensity;
		panel->condition.target_index = SECTOR_INTENSITY;
		panel->condition.target_type = INT;
	}
	return (select_sector_other_condition_target2(env, panel, target_panel,
	sector));
}

int		select_vertex_condition_target(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	if (target_panel->selected_button == 0)
	{
		panel->condition.target = &env->vertices[env->editor.selected_vertex].x;
		panel->condition.target_index = VERTEX_X;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target = &env->vertices[env->editor.selected_vertex].y;
		panel->condition.target_index = VERTEX_Y;
	}
	panel->condition.vertex = env->editor.selected_vertex;
	return (0);
}

int		select_weapon_condition_target(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel)
{
	panel->condition.target_type = INT;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target =
		&env->weapons[env->editor.selected_weapon].damage;
		panel->condition.target_index = WEAPON_DAMAGE;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target =
		&env->weapons[env->editor.selected_weapon].range;
		panel->condition.target_index = WEAPON_RANGE;
	}
	panel->condition.weapon = env->editor.selected_weapon;
	return (0);
}
