/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 11:57:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_player_panel_buttons_state(t_env *env)
{
	if (env->editor.event_panel.event.target_index == PLAYER_X)
		env->editor.event_panel.target_panel.targets[0].state = DOWN;
	else if (env->editor.event_panel.event.target_index == PLAYER_Y)
		env->editor.event_panel.target_panel.targets[1].state = DOWN;
	else if (env->editor.event_panel.event.target_index == PLAYER_Z)
		env->editor.event_panel.target_panel.targets[2].state = DOWN;
	else if (env->editor.event_panel.event.target_index == PLAYER_HP)
		env->editor.event_panel.target_panel.targets[3].state = DOWN;
	else if (env->editor.event_panel.event.target_index == PLAYER_ARMOR)
		env->editor.event_panel.target_panel.targets[4].state = DOWN;
	else if (env->editor.event_panel.event.target_index == PLAYER_SPEED)
		env->editor.event_panel.target_panel.targets[5].state = DOWN;
	else if (env->editor.event_panel.event.target_index == PLAYER_INVINCIBLE)
		env->editor.event_panel.target_panel.targets[6].state = DOWN;
	else if (env->editor.event_panel.event.target_index == PLAYER_INFINITE_AMMO)
		env->editor.event_panel.target_panel.targets[7].state = DOWN;
	return (0);
}

int		select_player(void *param)
{
	t_env	*env;
	int		i;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.player_type = 1;
	i = 0;
	while (i < 8)
	{
		env->editor.event_panel.target_panel.targets[i].state = UP;
		env->editor.event_panel.target_panel.targets[i].anim_state = REST;
		i++;
	}
	if (env->editor.event_panel.event.target)
		set_player_panel_buttons_state(env);
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
