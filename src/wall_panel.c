/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 11:56:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_wall_panel_buttons_state(t_env *env)
{
	if (env->editor.event_panel.event.target_index == SECTOR_WALL_TEXTURE)
		env->editor.event_panel.target_panel.targets[0].state = DOWN;
	else if (env->editor.event_panel.event.target_index == SECTOR_WALL_PORTAL)
		env->editor.event_panel.target_panel.targets[1].state = DOWN;
	else if (env->editor.event_panel.event.target_index == SECTOR_WALL_ALIGN_X)
		env->editor.event_panel.target_panel.targets[2].state = DOWN;
	else if (env->editor.event_panel.event.target_index == SECTOR_WALL_ALIGN_Y)
		env->editor.event_panel.target_panel.targets[3].state = DOWN;
	else if (env->editor.event_panel.event.target_index == SECTOR_WALL_SCALE_X)
		env->editor.event_panel.target_panel.targets[4].state = DOWN;
	else if (env->editor.event_panel.event.target_index == SECTOR_WALL_SCALE_Y)
		env->editor.event_panel.target_panel.targets[5].state = DOWN;
	return (0);
}

int		select_wall(void *param)
{
	t_env	*env;
	int		i;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.wall_type = 1;
	i = 0;
	while (i < 8)
	{
		env->editor.event_panel.target_panel.targets[i].state = UP;
		env->editor.event_panel.target_panel.targets[i].anim_state = REST;
		i++;
	}
	if (env->editor.event_panel.event.target)
		set_wall_panel_buttons_state(env);
	return (0);
}

int		draw_wall_panel(t_env *env)
{
	draw_button(env, env->editor.event_panel.target_panel.targets[0],
	"Texture");
	draw_button(env, env->editor.event_panel.target_panel.targets[1],
	"Portal");
	draw_button(env, env->editor.event_panel.target_panel.targets[2],
	"Align X");
	draw_button(env, env->editor.event_panel.target_panel.targets[3],
	"Align Y");
	draw_button(env, env->editor.event_panel.target_panel.targets[4],
	"Scale X");
	draw_button(env, env->editor.event_panel.target_panel.targets[5],
	"Scale Y");
	return (0);
}
