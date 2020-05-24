/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_event_target.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:07:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 16:44:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "events.h"
#include "parser.h"

int		set_new_event_target2(t_event_panel *panel, t_env *env)
{
	if (panel->target_panel.sector_other_type)
		return (select_sector_other_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.other_type)
		return (select_other_target(env, panel, &panel->target_panel));
	return (0);
}

int		set_new_event_target(t_env *env)
{
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	env->editor.event_panel.event.type = DOUBLE;
	if (panel->target_panel.floor_type)
		return (select_floor_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.ceiling_type)
		return (select_ceiling_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.wall_type)
		return (select_wall_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.wall_sprite_type)
		return (select_wall_sprite_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.vertex_type)
		return (select_vertex_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.weapon_type)
		return (select_weapon_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.player_type)
		return (select_player_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.enemy_type)
		return (select_enemy_target(env, panel, &panel->target_panel));
	else if (panel->target_panel.object_type)
		return (select_object_target(env, panel, &panel->target_panel));
	return (set_new_event_target2(panel, env));
}
