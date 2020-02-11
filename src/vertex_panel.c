/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 11:56:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_vertex_panel_buttons_state(t_env *env)
{
	if (env->editor.event_panel.event.target_index == VERTEX_X)
		env->editor.event_panel.target_panel.targets[0].state = DOWN;
	else if (env->editor.event_panel.event.target_index == VERTEX_Y)
		env->editor.event_panel.target_panel.targets[1].state = DOWN;
	return (0);
}

int		select_vertex(void *param)
{
	t_env	*env;
	int		i;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.vertex_type = 1;
	i = 0;
	while (i < 8)
	{
		env->editor.event_panel.target_panel.targets[i].state = UP;
		env->editor.event_panel.target_panel.targets[i].anim_state = REST;
		i++;
	}
	if (env->editor.event_panel.event.target)
		set_vertex_panel_buttons_state(env);
	return (0);
}

int		draw_vertex_panel(t_env *env)
{
	draw_button(env, env->editor.event_panel.target_panel.targets[0], "X");
	draw_button(env, env->editor.event_panel.target_panel.targets[1], "Y");
	return (0);
}
