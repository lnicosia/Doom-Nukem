/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_event_target6.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:04:07 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 14:11:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		select_sector_other_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel)
{
	int		sector;

	sector = env->editor.selected_sector;
	if (target_panel->targets[0].state == DOWN)
	{
		panel->event.target = &env->sectors[sector].brightness;
		panel->event.target_index = SECTOR_BRIGHTNESS;
		panel->event.type = INT;
	}
	else if (target_panel->targets[1].state == DOWN)
	{
		panel->event.target = &env->sectors[sector].light_color;
		panel->event.target_index = SECTOR_LIGHT_COLOR;
		panel->event.type = UINT32;
	}
	else if (target_panel->targets[3].state == DOWN)
	{
		panel->event.target = &env->sectors[sector].intensity;
		panel->event.target_index = SECTOR_INTENSITY;
		panel->event.type = INT;
	}
	else if (target_panel->targets[4].state == DOWN)
	{
		panel->event.target = &env->sectors[sector].gravity;
		panel->event.target_index = SECTOR_GRAVITY;
	}
	return (0);
}

int		select_vertex_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel)
{
	if (target_panel->targets[0].state == DOWN)
	{
		panel->event.target = &env->vertices[env->editor.selected_vertex].x;
		panel->event.target_index = VERTEX_X;
	}
	else if (target_panel->targets[1].state == DOWN)
	{
		panel->event.target = &env->vertices[env->editor.selected_vertex].y;
		panel->event.target_index = VERTEX_Y;
	}
	return (0);
}

int		select_weapon_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel)
{
	if (target_panel->targets[0].state == DOWN)
	{
		panel->event.target =
		&env->weapons[env->editor.selected_weapon].damage;
		panel->event.target_index = VERTEX_X;
	}
	else if (target_panel->targets[1].state == DOWN)
	{
		panel->event.target =
		&env->weapons[env->editor.selected_weapon].range;
		panel->event.target_index = VERTEX_Y;
	}
	return (0);
}
