/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 15:19:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		select_vertex(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_panel.vertex_type = 1;
	return (0);
}

int		draw_vertex_panel(t_env *env)
{
	draw_button(env, env->editor.event_panel.target_panel.targets[0], "X");
	draw_button(env, env->editor.event_panel.target_panel.targets[1], "Y");
	return (0);
}
