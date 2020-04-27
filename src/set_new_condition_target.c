/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_condition_target.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:07:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 15:09:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

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
