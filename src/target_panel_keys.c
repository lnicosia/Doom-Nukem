/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_panel_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:26:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:34:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events.h"

int		first_phase_keys(t_env *env, t_target_panel *panel)
{
	if (button_keys(&panel->sector, env))
		return (-1);
	if (button_keys(&panel->wall, env))
		return (-1);
	if (button_keys(&panel->wall_sprite, env))
		return (-1);
	if (button_keys(&panel->weapon, env))
		return (-1);
	if (button_keys(&panel->enemy, env))
		return (-1);
	if (button_keys(&panel->object, env))
		return (-1);
	if (button_keys(&panel->player, env))
		return (-1);
	if (button_keys(&panel->vertex, env))
		return (-1);
	if (button_keys(&panel->other, env))
		return (-1);
	return (0);
}

int		second_phase_keys(t_env *env, t_target_panel *panel)
{
	if (button_keys(&panel->previous, env))
		return (-1);
	if (panel->sector_type)
	{
		if (button_keys(&panel->floor, env))
			return (-1);
		if (button_keys(&panel->ceiling, env))
			return (-1);
		if (button_keys(&panel->sector_other, env))
			return (-1);
	}
	return (0);
}

int		third_phase_buttons_keys(t_env *env, t_target_panel *panel, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		if (button_keys(&panel->targets[i], env))
			return (-1);
		i++;
	}
	return (0);
}

int		third_phase_keys(t_env *env, t_target_panel *panel)
{
	int		max;

	if (button_keys(&panel->previous, env))
		return (-1);
	if (panel->player_type && env->editor.creating_event)
		max = 9;
	else if (panel->floor_type || panel->ceiling_type || panel->object_type)
		max = 7;
	else if (panel->wall_type)
		max = 6;
	else if (panel->wall_sprite_type)
		max = 5;
	else if (panel->sector_other_type)
		max = 4;
	else if (panel->vertex_type)
		max = 2;
	else if (panel->other_type)
		max = 2;
	else
		max = 8;
	if (third_phase_buttons_keys(env, panel, max))
		return (0);
	return (0);
}

int		target_panel_keys(t_env *env, t_target_panel *panel)
{
	int	phase;

	phase = get_target_selection_phase(panel);
	if (phase == 0)
	{
		if (first_phase_keys(env, panel))
			return (-1);
	}
	if (phase == 1)
	{
		if (second_phase_keys(env, panel))
			return (-1);
	}
	if (phase == 2)
	{
		if (third_phase_keys(env, panel))
			return (-1);
	}
	return (0);
}
