/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_selection_buttons.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:25:57 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/27 17:35:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_events_selection_buttons(t_env *env)
{
	(void)env;
	env->editor.next_events = new_next_button(WHEN_DOWN,
	NULL, NULL, env);
	env->editor.next_events.pos = new_point(300, 480);
	env->editor.previous_events = new_previous_button(WHEN_DOWN,
	NULL, NULL, env);
	env->editor.previous_events.pos = new_point(90, 480);
}
