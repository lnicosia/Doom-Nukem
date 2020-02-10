/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 14:35:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		select_floor(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.floor_type = 1;
	return (0);
}

int		draw_floor_panel(t_env *env)
{
	draw_button(env, env->editor.event_panel.target_panel.targets[0], "Height");
	draw_button(env, env->editor.event_panel.target_panel.targets[1], "Texture");
	draw_button(env, env->editor.event_panel.target_panel.targets[2], "Slope");
	draw_button(env, env->editor.event_panel.target_panel.targets[3], "Align X");
	draw_button(env, env->editor.event_panel.target_panel.targets[4], "Align Y");
	draw_button(env, env->editor.event_panel.target_panel.targets[5], "Scale X");
	draw_button(env, env->editor.event_panel.target_panel.targets[6], "Scale Y");
	return (0);
}
