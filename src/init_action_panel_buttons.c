/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_action_panel_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:01:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 17:29:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	new_event_panel_dialog_box(t_input_box *box, int type, void *target,
t_env *env)
{
	size_t	len;
	size_t	dec_len;
	char	*tmp;

	if (type < 0 || type > 3 || !target)
		return (-1);
	box->size = env->editor.event_panel.action_panel.value.size_up;
	box->pos = env->editor.event_panel.action_panel.value.pos;
	box->rectangle = env->editor.event_panel.action_panel.value.up;
	box->rectangle = new_rectangle(0xc8ccd0, 0x333333, 1, 2);
	box->type = type;
	box->state = 1;
	box->accept_inputs = 0;
	len = 0;
	if (type == INT)
	{
		box->int_target = (int*)target;
		if (!(box->str = ft_itoa(*((int*)target))))
			return (-1);
		set_double_stats(box);
	}
	else if (type == DOUBLE)
	{
		box->double_target = (double*)target;
		if (box->str)
			ft_strdel(&box->str);
		len = get_double_len(*(box->double_target));
		dec_len = get_decimal_len(*(box->double_target));
		if (!(box->str = ft_strnew(len)))
			return (-1);
		ft_snprintf(box->str, len + 1, "%.5f", dec_len,
		*(box->double_target));
		set_double_stats(box);
	}
	else if (type == UINT32)
	{
		box->uint32_target = (Uint32*)target;
		if (box->str)
			ft_strdel(&box->str);
		if (!(tmp = ft_strnew(15)))
			return (-1);
		ft_snprintf(tmp, 15, "0x%X", *box->uint32_target);
		if (!(box->str = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
		set_double_stats(box);
	}
	else if (type == STRING)
	{
		box->str_target = (char**)target;
		if (box->str)
			ft_strdel(&box->str);
		box->str = ft_strdup(*(char**)target);
	}
	box->cursor = ft_strlen(box->str);
	box->accept_inputs = 1;
	box->select_start = 0;
	box->select_end = ft_strlen(box->str);
	box->check = 0;
	box->update = 0;
	box->error_message = "Error";
	return (0);
}

int		set_dialog_event_text(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (new_event_panel_dialog_box(&env->input_box, STRING,
		&env->editor.event_panel.event.exec_param, env))
		return (-1);
	env->input_box.pos.y = env->editor.event_panel.action_panel.text.pos.y;
	env->input_box.pos.x = env->editor.event_panel.pos.x + 100
	+ env->editor.event_panel.content_panel_size.x / 2
	- env->input_box.size.x / 2;
	return (0);
}

int		set_event_go_to(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.action_panel.add.state = UP;
	env->editor.event_panel.action_panel.add.anim_state = REST;
	if (env->editor.event_panel.event.mod_type == INCR)
		env->editor.event_panel.event.goal =
		env->editor.event_panel.event.start_incr;
	env->editor.event_panel.event.mod_type = FIXED;
	return (0);
}

int		set_event_add(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.action_panel.go_to.state = UP;
	env->editor.event_panel.action_panel.go_to.anim_state = REST;
	if (env->editor.event_panel.event.mod_type == FIXED)
		env->editor.event_panel.event.start_incr =
		env->editor.event_panel.event.goal;
	env->editor.event_panel.event.mod_type = INCR;
	return (0);
}

void	update_action_panel_buttons_pos(t_env *env)
{
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	panel->action_panel.add.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 2 + 10,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2
	- panel->action_panel.add.size_up.y * 2);
	panel->action_panel.go_to.pos = new_point(panel->action_panel.add.pos.x
	- panel->action_panel.go_to.size_up.x - 20, panel->action_panel.add.pos.y);
	panel->action_panel.delay.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 4 - panel->action_panel.delay.size_up.x / 2,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2
	+ panel->action_panel.delay.size_up.y);
	panel->action_panel.max_uses.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x * 0.75
	- panel->action_panel.delay.size_up.x / 2, panel->action_panel.delay.pos.y);
	panel->action_panel.value.pos = new_point(panel->pos.x + 90
	+ panel->content_panel_size.x / 2 - panel->action_panel.value.size_up.x,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2
	- panel->action_panel.value.size_up.y / 2);
	panel->action_panel.speed.pos = new_point(panel->pos.x + 100
	+ panel->content_panel_size.x / 2 + 10,
	panel->action_panel.value.pos.y);
	panel->action_panel.text.pos.y = panel->action_panel.add.pos.y;
	panel->action_panel.text.pos.x = panel->pos.x + 100 + panel->content_panel_size.x / 2 - panel->action_panel.text.size_up.x / 2;
}

void	init_action_panel_buttons(t_env *env)
{
	env->editor.event_panel.action_panel.go_to = new_small_panel_button(
	WHEN_DOWN, &set_event_go_to, env, env);
	env->editor.event_panel.action_panel.go_to.state = DOWN;
	env->editor.event_panel.action_panel.add = new_small_panel_button(
	WHEN_DOWN, &set_event_add, env, env);
	env->editor.event_panel.action_panel.value = new_green_panel_button(
	ON_RELEASE, &set_event_value, env, env);
	env->editor.event_panel.action_panel.speed = new_green_panel_button(
	ON_RELEASE, &set_event_speed, env, env);
	env->editor.event_panel.action_panel.delay = new_blue_panel_button(
	ON_RELEASE, &set_event_delay, env, env);
	env->editor.event_panel.action_panel.max_uses = new_blue_panel_button(
	ON_RELEASE, &set_event_max_uses, env, env);
	env->editor.event_panel.action_panel.text = new_yellow_panel_button(
	ON_RELEASE, &set_dialog_event_text, env, env);
	update_action_panel_buttons_pos(env);
}
