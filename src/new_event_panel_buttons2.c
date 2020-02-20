/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_event_panel_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:13:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 15:56:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_button	new_dark_panel_button(int type, int (*action)(void *),
void *param, t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFF4d4d4d, 0xFF333333, 1, 2);
	new.down = new_rectangle(0xFF404040, 0xFF333333, 1, 2);
	new.pressed = new_rectangle(0xFF404040, 0xFF333333, 1, 2);
	new.hover = new_rectangle(0xFF595959, 0xFF333333, 1, 2);
	new.size_up = new_point(env->editor.event_panel.content_panel_size.x / 4,
	env->editor.event_panel.content_panel_size.y / 6);
	new.size_pressed = new.size_up;
	new.size_down = new.size_up;
	new.size_hover = new.size_up;
	return (new);
}

t_button	new_purple_panel_button(int type, int (*action)(void *),
void *param, t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFF9c88ff, 0xFF333333, 1, 2);
	new.down = new_rectangle(0xFF9580ff, 0xFF333333, 1, 2);
	new.pressed = new_rectangle(0xFF9580ff, 0xFF333333, 1, 2);
	new.hover = new_rectangle(0xFFaa99ff, 0xFF333333, 1, 2);
	new.size_up = new_point(env->editor.event_panel.content_panel_size.x / 4,
	env->editor.event_panel.content_panel_size.y / 6);
	new.size_pressed = new.size_up;
	new.size_down = new.size_up;
	new.size_hover = new.size_up;
	return (new);
}

t_button	new_turquoise_panel_button(int type, int (*action)(void *),
void *param, t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFF82ccdd, 0xFF333333, 1, 2);
	new.down = new_rectangle(0xFF73c6d9, 0xFF333333, 1, 2);
	new.pressed = new_rectangle(0xFF73c6d9, 0xFF333333, 1, 2);
	new.hover = new_rectangle(0xFF9bd6e4, 0xFF333333, 1, 2);
	new.size_up = new_point(env->editor.event_panel.content_panel_size.x / 4,
	env->editor.event_panel.content_panel_size.y / 6);
	new.size_pressed = new.size_up;
	new.size_down = new.size_up;
	new.size_hover = new.size_up;
	return (new);
}

t_button	new_small_panel_button(int type, int (*action)(void *),
void *param, t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFFffcc66, 0xFF333333, 1, 2);
	new.down = new_rectangle(0xFFed7161, 0xFFed7161, 1, 2);
	new.pressed = new_rectangle(0xFFffc34d, 0xFF333333, 1, 2);
	new.hover = new_rectangle(0xFFffd480, 0xFF333333, 1, 2);
	new.size_up = new_point(env->editor.event_panel.content_panel_size.x / 4,
	env->editor.event_panel.content_panel_size.y / 6);
	new.size_pressed = new.size_up;
	new.size_down = new.size_up;
	new.size_hover = new.size_up;
	return (new);
}

t_button	new_condition_panel_button(int type, int (*action)(void *),
void *param, t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFFffcc66, 0xFF333333, 1, 2);
	new.down = new_rectangle(0xFFed7161, 0xFFed7161, 1, 2);
	new.pressed = new_rectangle(0xFFffc34d, 0xFF333333, 1, 2);
	new.hover = new_rectangle(0xFFffd480, 0xFF333333, 1, 2);
	new.size_up = new_point(env->editor.event_panel.content_panel_size.x / 5.5,
	env->editor.event_panel.content_panel_size.y / 8);
	new.size_pressed = new.size_up;
	new.size_down = new.size_up;
	new.size_hover = new.size_up;
	return (new);
}
