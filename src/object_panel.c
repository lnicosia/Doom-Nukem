/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 11:57:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_object_panel_buttons_state(t_env *env)
{
	if (env->editor.event_panel.event.target_index == OBJECT_SPRITE)
		env->editor.event_panel.target_panel.targets[0].state = DOWN;
	else if (env->editor.event_panel.event.target_index == OBJECT_X)
		env->editor.event_panel.target_panel.targets[1].state = DOWN;
	else if (env->editor.event_panel.event.target_index == OBJECT_Y)
		env->editor.event_panel.target_panel.targets[2].state = DOWN;
	else if (env->editor.event_panel.event.target_index == OBJECT_Z)
		env->editor.event_panel.target_panel.targets[3].state = DOWN;
	else if (env->editor.event_panel.event.target_index == OBJECT_SCALE)
		env->editor.event_panel.target_panel.targets[4].state = DOWN;
	else if (env->editor.event_panel.event.target_index == OBJECT_DAMAGE)
		env->editor.event_panel.target_panel.targets[5].state = DOWN;
	else if (env->editor.event_panel.event.target_index == OBJECT_HP)
		env->editor.event_panel.target_panel.targets[6].state = DOWN;
	return (0);
}

int		select_object(void *param)
{
	t_env	*env;
	int		i;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.object_type = 1;
	i = 0;
	while (i < 8)
	{
		env->editor.event_panel.target_panel.targets[i].state = UP;
		env->editor.event_panel.target_panel.targets[i].anim_state = REST;
		i++;
	}
	if (env->editor.event_panel.event.target)
		set_object_panel_buttons_state(env);
	return (0);
}

int		draw_object_panel(t_env *env)
{
	draw_button(env, env->editor.event_panel.target_panel.targets[0], "Sprite");
	draw_button(env, env->editor.event_panel.target_panel.targets[1], "X");
	draw_button(env, env->editor.event_panel.target_panel.targets[2], "Y");
	draw_button(env, env->editor.event_panel.target_panel.targets[3], "Z");
	draw_button(env, env->editor.event_panel.target_panel.targets[4], "Scale");
	draw_button(env, env->editor.event_panel.target_panel.targets[5], "Damage");
	draw_button(env, env->editor.event_panel.target_panel.targets[6], "Health");
	return (0);
}
