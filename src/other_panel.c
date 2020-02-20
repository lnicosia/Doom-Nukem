/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:43:52 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 17:02:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		set_other_panel_buttons_state(t_target_panel *panel, int index)
{
	if (index == WIN)
		panel->targets[0].state = DOWN;
		return (0);
}

int		select_other(void *param)
{
	t_env			*env;
	t_target_panel	*panel;
	int				i;

	env = (t_env*)param;
	panel = &env->editor.event_panel.target_panel;
	panel->other_type = 1;
	i = 0;
	while (i < 8)
	{
		panel->targets[i].state = UP;
		i++;
	}
	set_other_panel_buttons_state(panel,
	env->editor.event_panel.event.target_index);
	update_target_panel_buttons_pos(env);
	return (0);
}

int		draw_other_panel(t_env *env, t_target_panel *panel)
{
	draw_button(env, panel->targets[0], "Win");
	return (0);
}
