/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_type_buttons_functions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:23:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/19 10:56:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"

int		set_equals(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = EQUALS;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	return (0);
}

int		set_different(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = DIFFERENT;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	return (0);
}

int		set_less(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = LESS;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	return (0);
}

int		set_greater(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = GREATER;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	return (0);
}

int		set_less_or_equals(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = LESS_OR_EQUALS;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	return (0);
}
