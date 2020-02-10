/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite_panel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 15:06:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		select_wall_sprite(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.wall_sprite_type = 1;
	return (0);
}

int		draw_wall_sprite_panel(t_env *env)
{
	draw_button(env, env->editor.event_panel.target_panel.targets[0], "Sprite");
	draw_button(env, env->editor.event_panel.target_panel.targets[1], "Align X");
	draw_button(env, env->editor.event_panel.target_panel.targets[2], "Align Y");
	draw_button(env, env->editor.event_panel.target_panel.targets[3], "Scale X");
	draw_button(env, env->editor.event_panel.target_panel.targets[4], "Scale Y");
	return (0);
}
