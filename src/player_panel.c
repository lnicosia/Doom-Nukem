/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 15:01:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		select_player(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.player_type = 1;
	return (0);
}

int		draw_player_panel(t_env *env)
{
	draw_button(env, env->editor.event_panel.target_panel.targets[0], "X");
	draw_button(env, env->editor.event_panel.target_panel.targets[1], "Y");
	draw_button(env, env->editor.event_panel.target_panel.targets[2], "Z");
	draw_button(env, env->editor.event_panel.target_panel.targets[3], "Health");
	draw_button(env, env->editor.event_panel.target_panel.targets[4], "Armor");
	draw_button(env, env->editor.event_panel.target_panel.targets[5], "Speed");
	draw_button(env, env->editor.event_panel.target_panel.targets[6],
	"Invincible");
	draw_button(env, env->editor.event_panel.target_panel.targets[7],
	"Infinite ammo");
	return (0);
}
