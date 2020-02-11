/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_panel_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:31:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 18:45:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		action_panel_keys(t_env *env)
{
	if (button_keys(&env->editor.event_panel.action_panel.go_to, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.action_panel.add, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.action_panel.func, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.action_panel.delay, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.action_panel.max_uses, env))
		return (-1);
	return (0);
}

int		action_panel_keyup(t_env *env)
{
	if (button_keyup(&env->editor.event_panel.action_panel.go_to, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.action_panel.add, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.action_panel.func, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.action_panel.delay, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.action_panel.max_uses, env))
		return (-1);
	return (0);
}
