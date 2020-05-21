/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ceiling_condition_target.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:45:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:45:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events.h"
#include "parser.h"

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
	panel->condition.sector = sector;
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
