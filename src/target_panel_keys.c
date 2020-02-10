/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_panel_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:26:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 12:06:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		first_phase_keys(t_env *env)
{
	if (button_keys(&env->editor.event_panel.target_panel.sector, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.target_panel.wall, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.target_panel.wall_sprite, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.target_panel.weapon, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.target_panel.enemy, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.target_panel.object, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.target_panel.player, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.target_panel.other, env))
		return (-1);
	return (0);
}

int		first_phase_keyup(t_env *env)
{
	if (button_keyup(&env->editor.event_panel.target_panel.sector, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.wall, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.wall_sprite, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.weapon, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.enemy, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.object, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.player, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.other, env))
		return (-1);
	return (0);
}

int		second_phase_keys(t_env *env)
{
	if (button_keys(&env->editor.event_panel.target_panel.previous, env))
		return (-1);
	if (env->editor.event_panel.target_panel.sector_type)
	if (button_keys(&env->editor.event_panel.target_panel.floor, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.target_panel.ceiling, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.target_panel.sector_other,
		env))
		return (-1);
	return (0);
}

int		second_phase_keyup(t_env *env)
{
	if (button_keyup(&env->editor.event_panel.target_panel.previous, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.floor, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.ceiling, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.target_panel.sector_other,
		env))
		return (-1);
	return (0);
}

int		third_phase_keys(t_env *env)
{
	if (button_keys(&env->editor.event_panel.target_panel.previous, env))
		return (-1);
	return (0);
}

int		third_phase_keyup(t_env *env)
{
	if (button_keyup(&env->editor.event_panel.target_panel.previous, env))
		return (-1);
	return (0);
}

int		target_panel_keys(t_env *env)
{
	int	phase;

	phase = get_target_selection_phase(env);
	if (phase == 0)
	{
		if (first_phase_keys(env))
			return (-1);
	}
	if (phase == 1)
	{
		if (second_phase_keys(env))
			return (-1);
	}
	if (phase == 2)
	{
		if (third_phase_keys(env))
			return (-1);
	}
	return (0);
}

int		target_panel_keyup(t_env *env)
{
	int	phase;

	phase = get_target_selection_phase(env);
	if (phase == 0)
	{
		if (first_phase_keyup(env))
			return (-1);
	}
	if (phase == 1)
	{
		if (second_phase_keyup(env))
			return (-1);
	}
	if (phase == 2)
	{
		if (third_phase_keyup(env))
			return (-1);
	}
	return (0);
}
