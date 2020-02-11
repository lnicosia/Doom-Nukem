/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 11:57:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_weapon_panel_buttons_state(t_env *env)
{
	if (env->editor.event_panel.event.target_index == WEAPON_DAMAGE)
		env->editor.event_panel.target_panel.targets[0].state = DOWN;
	else if (env->editor.event_panel.event.target_index == WEAPON_RANGE)
		env->editor.event_panel.target_panel.targets[1].state = DOWN;
	return (0);
}

int		select_weapon(void *param)
{
	t_env	*env;
	int		i;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.weapon_type = 1;
	i = 0;
	while (i < 8)
	{
		env->editor.event_panel.target_panel.targets[i].state = UP;
		env->editor.event_panel.target_panel.targets[i].anim_state = REST;
		i++;
	}
	if (env->editor.event_panel.event.target)
		set_weapon_panel_buttons_state(env);
	return (0);
}

int		draw_weapon_panel(t_env *env)
{
	draw_button(env, env->editor.event_panel.target_panel.targets[0], "Damage");
	draw_button(env, env->editor.event_panel.target_panel.targets[1], "Range");
	return (0);
}
