/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_panel_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:26:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/07 20:54:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		target_panel_keys(t_env *env)
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

int		target_panel_keyup(t_env *env)
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
