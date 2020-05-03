/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_target_panel_buttons2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:09:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:09:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		get_target_selection_phase(t_target_panel *panel)
{
	if (panel->sector_type && !panel->floor_type && !panel->ceiling_type
		&& !panel->sector_other_type)
		return (1);
	else if (panel->wall_type || panel->wall_sprite_type
		|| panel->weapon_type || panel->enemy_type || panel->object_type
		|| panel->player_type || panel->vertex_type || panel->floor_type
		|| panel->ceiling_type || panel->sector_other_type || panel->other_type)
		return (2);
	return (0);
}

int		set_int_button(void *param)
{
	*((int*)param) = 1;
	return (0);
}

void	reset_panel_type(t_target_panel *panel)
{
	panel->wall_type = 0;
	panel->wall_sprite_type = 0;
	panel->object_type = 0;
	panel->other_type = 0;
	panel->weapon_type = 0;
	panel->enemy_type = 0;
	panel->player_type = 0;
	panel->vertex_type = 0;
	panel->floor_type = 0;
	panel->ceiling_type = 0;
	panel->sector_other_type = 0;
}

int		previous_target_selection_phase(void *param)
{
	t_target_panel	*panel;
	t_env			*env;

	env = (t_env*)param;
	if (env->editor.creating_condition)
		panel = &env->editor.condition_panel.target_panel;
	else
		panel = &env->editor.event_panel.target_panel;
	if (get_target_selection_phase(panel) == 1)
		panel->sector_type = 0;
	if (get_target_selection_phase(panel) == 2)
		reset_panel_type(panel);
	update_condition_target_buttons_pos(env);
	update_target_panel_buttons_pos(env);
	return (0);
}
