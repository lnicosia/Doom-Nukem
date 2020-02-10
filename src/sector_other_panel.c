/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_other_panel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 15:17:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		select_sector_other(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.sector_other_type = 1;
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
