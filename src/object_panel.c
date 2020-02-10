/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 15:05:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		select_object(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.object_type = 1;
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
