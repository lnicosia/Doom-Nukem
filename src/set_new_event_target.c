/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_event_target.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:07:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 16:18:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		set_new_event_target2(t_env *env, t_target_panel *panel)
{
	(void)env;
	if (panel->player_type)
	{
	}
	else if (panel->enemy_type)
	{
	}
	else if (panel->object_type)
	{
	}
	return (0);
}

int		set_new_event_target(t_env *env)
{
	t_target_panel	*panel;

	panel = &env->editor.event_panel.target_panel;
	if (panel->floor_type)
	{
		if (panel->targets[1].state == DOWN)
			env->editor.event_panel.event.type = INT;
		else
			env->editor.event_panel.event.type = DOUBLE;
		if (panel->targets[0].state == DOWN)
			env->editor.event_panel.event.target =
			&env->sectors[env->selected_floor].floor;
	}
	else if (panel->ceiling_type)
	{
	}
	else if (panel->wall_type)
	{
	}
	else if (panel->wall_sprite_type)
	{
	}
	else if (panel->vertex_type)
	{
	}
	else if (panel->weapon_type)
	{
	}
	else
		return (set_new_event_target2(env, panel));
	return (0);
}
