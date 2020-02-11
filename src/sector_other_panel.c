/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_other_panel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 15:50:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_sector_other_panel_buttons_state(t_env *env)
{
	if (env->editor.event_panel.event.target_index == SECTOR_BRIGHTNESS)
		env->editor.event_panel.target_panel.targets[0].state = DOWN;
	else if (env->editor.event_panel.event.target_index == SECTOR_LIGHT_COLOR)
		env->editor.event_panel.target_panel.targets[1].state = DOWN;
	else if (env->editor.event_panel.event.target_index == SECTOR_INTENSITY)
		env->editor.event_panel.target_panel.targets[2].state = DOWN;
	else if (env->editor.event_panel.event.target_index == SECTOR_GRAVITY)
		env->editor.event_panel.target_panel.targets[3].state = DOWN;
	return (0);
}

int		select_sector_other(void *param)
{
	t_env	*env;
	int		i;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.sector_other_type = 1;
	i = 0;
	while (i < 8)
	{
		env->editor.event_panel.target_panel.targets[i].state = UP;
		env->editor.event_panel.target_panel.targets[i].anim_state = REST;
		i++;
	}
	if (env->editor.event_panel.event.target)
		set_sector_other_panel_buttons_state(env);
	return (0);
}

int		draw_sector_other_panel(t_env *env)
{
	draw_button(env, env->editor.event_panel.target_panel.targets[0],
	"Light brightness");
	draw_button(env, env->editor.event_panel.target_panel.targets[1],
	"Light color");
	draw_button(env, env->editor.event_panel.target_panel.targets[2],
	"Color intensity");
	draw_button(env, env->editor.event_panel.target_panel.targets[3],
	"Gravity");
	return (0);
}
