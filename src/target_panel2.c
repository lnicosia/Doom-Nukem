/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_panel2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:24:57 by marvin            #+#    #+#             */
/*   Updated: 2020/05/20 12:49:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"
#include "events.h"

int	draw_third_phase_selection3(t_env *env, t_target_panel *panel)
{
	if (panel->ceiling_type)
	{
		if (draw_ceiling_panel(env, panel))
			return (-1);
	}
	else if (panel->sector_other_type)
	{
		if (draw_sector_other_panel(env, panel))
			return (-1);
	}
	else if (panel->other_type)
	{
		if (draw_other_panel(env, panel))
			return (-1);
	}
	return (0);
}

int	draw_third_phase_selection2(t_env *env, t_target_panel *panel)
{
	if (panel->enemy_type)
	{
		if (draw_enemy_panel(env, panel))
			return (-1);
	}
	else if (panel->player_type)
	{
		if (draw_player_panel(env, panel))
			return (-1);
	}
	else if (panel->vertex_type)
	{
		if (draw_vertex_panel(env, panel))
			return (-1);
	}
	else if (panel->floor_type)
	{
		if (draw_floor_panel(env, panel))
			return (-1);
	}
	else if (draw_third_phase_selection3(env, panel))
		return (-1);
	return (0);
}

int	draw_third_phase_selection(t_env *env, t_target_panel *panel)
{
	if (draw_button(env, panel->previous, NULL))
		return (-1);
	if (panel->wall_type)
	{
		if (draw_wall_panel(env, panel))
			return (-1);
	}
	else if (panel->wall_sprite_type)
	{
		if (draw_wall_sprite_panel(env, panel))
			return (-1);
	}
	else if (panel->object_type)
	{
		if (draw_object_panel(env, panel))
			return (-1);
	}
	else if (panel->weapon_type)
	{
		if (draw_weapon_panel(env, panel))
			return (-1);
	}
	else if (draw_third_phase_selection2(env, panel))
		return (-1);
	return (0);
}
