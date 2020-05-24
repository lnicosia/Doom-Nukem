/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_event_panel_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:13:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 15:56:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_button	new_red_panel_button(int type, int (*action)(void *),
void *param, t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFFed7161, 0xFF333333, 1, 2);
	new.down = new_rectangle(0xFFeb5a47, 0xFF333333, 1, 2);
	new.pressed = new_rectangle(0xFFeb5a47, 0xFF333333, 1, 2);
	new.hover = new_rectangle(0xFFf08475, 0xFF333333, 1, 2);
	new.size_up = new_point(env->editor.event_panel.content_panel_size.x / 4,
	env->editor.event_panel.content_panel_size.y / 6);
	new.size_pressed = new.size_up;
	new.size_down = new.size_up;
	new.size_hover = new.size_up;
	return (new);
}

t_button	new_blue_panel_button(int type, int (*action)(void *),
void *param, t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFF479fdb, 0xFF333333, 1, 2);
	new.down = new_rectangle(0xFF2a91d5, 0xFF333333, 1, 2);
	new.pressed = new_rectangle(0xFF2a91d5, 0xFF333333, 1, 2);
	new.hover = new_rectangle(0xFF55a7dd, 0xFF333333, 1, 2);
	new.size_up = new_point(env->editor.event_panel.content_panel_size.x / 4,
	env->editor.event_panel.content_panel_size.y / 6);
	new.size_pressed = new.size_up;
	new.size_down = new.size_up;
	new.size_hover = new.size_up;
	return (new);
}

t_button	new_green_panel_button(int type, int (*action)(void *),
void *param, t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFF88c057, 0xFF333333, 1, 2);
	new.down = new_rectangle(0xFF6fa63f, 0xFF333333, 1, 2);
	new.pressed = new_rectangle(0xFF6fa63f, 0xFF333333, 1, 2);
	new.hover = new_rectangle(0xFF96c76b, 0xFF333333, 1, 2);
	new.size_up = new_point(env->editor.event_panel.content_panel_size.x / 4,
	env->editor.event_panel.content_panel_size.y / 6);
	new.size_pressed = new.size_up;
	new.size_down = new.size_up;
	new.size_hover = new.size_up;
	return (new);
}

t_button	new_yellow_panel_button(int type, int (*action)(void *),
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

t_button	new_orange_panel_button(int type, int (*action)(void *),
void *param, t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFFf19066, 0xFF333333, 1, 2);
	new.down = new_rectangle(0xFFf0885c, 0xFF333333, 1, 2);
	new.pressed = new_rectangle(0xFFf0885c, 0xFF333333, 1, 2);
	new.hover = new_rectangle(0xFFf29973, 0xFF333333, 1, 2);
	new.size_up = new_point(env->editor.event_panel.content_panel_size.x / 4,
	env->editor.event_panel.content_panel_size.y / 6);
	new.size_pressed = new.size_up;
	new.size_down = new.size_up;
	new.size_hover = new.size_up;
	return (new);
}
