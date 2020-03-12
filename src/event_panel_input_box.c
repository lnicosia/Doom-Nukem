/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_panel_input_box.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:22:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/12 15:36:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	new_event_panel_value_box(t_input_box *box, int type, void *target,
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
		if (*box->int_target < 0)
			box->minus = 1;
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
		if (*box->double_target < 0)
			box->minus = 1;
		if (dec_len)
		{
			box->period = 1;
			box->period_index = len - dec_len + box->minus;
		}
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
		if (*box->uint32_target < 0)
			box->minus = 1;
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
	if (find_input_box_max_char(box))
		return (-1);
	box->cursor = ft_strlen(box->str);
	box->accept_inputs = 1;
	box->select_start = 0;
	box->select_end = ft_strlen(box->str);
	box->check = 0;
	box->update = 0;
	box->count = 0;
	box->error_message = "Error";
	return (0);
}

int	new_event_panel_box(t_input_box *box, int type, void *target, t_env *env)
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
		if (*box->int_target < 0)
			box->minus = 1;
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
		if (*box->double_target < 0)
			box->minus = 1;
		if (dec_len)
		{
			box->period = 1;
			box->period_index = len - dec_len + box->minus;
		}
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
		if (*box->uint32_target < 0)
			box->minus = 1;
		set_double_stats(box);
	}
	else if (type == STRING)
	{
		box->str_target = (char**)target;
		if (box->str)
			ft_strdel(&box->str);
		box->str = ft_strdup(*(char**)target);
	}
	if (find_input_box_max_char(box))
		return (-1);
	box->cursor = ft_strlen(box->str);
	box->accept_inputs = 1;
	box->select_start = 0;
	box->select_end = ft_strlen(box->str);
	box->check = 0;
	box->update = 0;
	box->count = 0;
	box->error_message = "Error";
	return (0);
}

int	set_event_value(void *param)
{
	t_env	*env;
	void	*target;

	env = (t_env*)param;
	target = NULL;
	if (env->editor.event_panel.event.type == INT)
		target = &env->editor.event_panel.action_panel.int_value;
	else if (env->editor.event_panel.event.type == DOUBLE)
		target = &env->editor.event_panel.action_panel.double_value;
	else if (env->editor.event_panel.event.type == UINT32)
		target = &env->editor.event_panel.action_panel.uint32_value;
	if (new_event_panel_value_box(&env->input_box,
		env->editor.event_panel.event.type, target, env))
		return (-1);
	return (0);
}

int	set_event_speed(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (new_event_panel_value_box(&env->input_box,
		DOUBLE, &env->editor.event_panel.event.speed, env))
		return (-1);
	env->input_box.pos = env->editor.event_panel.action_panel.speed.pos;
	env->input_box.size = env->editor.event_panel.action_panel.speed.size_up;
	return (0);
}

int	set_event_delay(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (new_event_panel_box(&env->input_box,
		INT, &env->editor.event_panel.action_panel.delay_value, env))
		return (-1);
	env->input_box.pos = env->editor.event_panel.action_panel.delay.pos;
	env->input_box.size = env->editor.event_panel.action_panel.delay.size_up;
	return (0);
}

int	set_event_max_uses(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (new_event_panel_box(&env->input_box,
		INT, &env->editor.event_panel.event.max_uses, env))
		return (-1);
	env->input_box.pos = env->editor.event_panel.action_panel.max_uses.pos;
	env->input_box.size = env->editor.event_panel.action_panel.max_uses.size_up;
	return (0);
}
