/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_event_target7.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:45:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 16:32:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events.h"
#include "parser.h"

int		select_other_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel)
{
	(void)env;
	if (target_panel->selected_button == 0)
	{
		panel->event.target = 0;
		panel->event.exec_func = &win;
		panel->event.mod_type = FUNC;
		panel->event.target_index = WIN;
	}
	if (target_panel->selected_button == 1)
	{
		panel->event.target = 0;
		panel->event.exec_func = &dialog_event;
		panel->event.mod_type = FUNC;
		panel->event.target_index = DIALOG;
	}
	return (0);
}
