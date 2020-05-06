/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:05:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 14:02:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		draw_launch_conditions_tab(t_env *env)
{
	SDL_Surface	*img;

	if (env->editor.event_panel.launch_conditions_tab.anim_state == HOVER)
		img = env->ui_textures[CONDITION_ICON_HOVER].surface;
	else if (env->editor.event_panel.launch_conditions_tab.state == DOWN
		|| env->editor.event_panel.launch_conditions_tab.anim_state == PRESSED)
		img = env->ui_textures[CONDITION_ICON_DOWN].surface;
	else
		img = env->ui_textures[CONDITION_ICON].surface;
	if (draw_button(env, env->editor.event_panel.launch_conditions_tab, NULL))
		return (-1);
	apply_surface(img, new_point(env->editor.event_panel.pos.y
	+ env->editor.event_panel.top_size + 200 + (50 - img->h / 2),
	env->editor.event_panel.pos.x + (50 - img->h / 2)),
	new_point(img->w, img->h), env);
	return (0);
}

int		draw_exec_conditions_tab(t_env *env)
{
	SDL_Surface	*img;

	if (env->editor.event_panel.exec_conditions_tab.anim_state == HOVER)
		img = env->ui_textures[CONDITION_ICON_HOVER].surface;
	else if (env->editor.event_panel.exec_conditions_tab.state == DOWN
		|| env->editor.event_panel.exec_conditions_tab.anim_state == PRESSED)
		img = env->ui_textures[CONDITION_ICON_DOWN].surface;
	else
		img = env->ui_textures[CONDITION_ICON].surface;
	if (draw_button(env, env->editor.event_panel.exec_conditions_tab, NULL))
		return (-1);
	apply_surface(img, new_point(env->editor.event_panel.pos.y
	+ env->editor.event_panel.top_size + 300 + (50 - img->h / 2),
	env->editor.event_panel.pos.x + (50 - img->h / 2)),
	new_point(img->w, img->h), env);
	return (0);
}

int		draw_event_panel_tab_content(t_env *env)
{
	if (env->editor.event_panel.target_tab.state == DOWN)
	{
		if (draw_target_panel(env))
			return (-1);
	}
	else if (env->editor.event_panel.action_tab.state == DOWN)
	{
		if (draw_action_panel(env))
			return (-1);
	}
	else if (env->editor.event_panel.launch_conditions_tab.state == DOWN
		|| env->editor.event_panel.exec_conditions_tab.state == DOWN)
	{
		if (draw_conditions_panel(env))
			return (-1);
	}
	return (0);
}

int		draw_event_panel2(t_env *env)
{
	apply_surface(env->ui_textures[EVENT_ICON].surface,
	new_point(env->editor.event_panel.pos.y +
	(env->editor.event_panel.top_size / 2 -
	env->ui_textures[EVENT_ICON].surface->h / 2),
	env->editor.event_panel.pos.x +
	(env->editor.event_panel.top_size / 2 -
	env->ui_textures[EVENT_ICON].surface->h / 2)),
	new_point(env->ui_textures[EVENT_ICON].surface->w,
	env->ui_textures[EVENT_ICON].surface->h), env);
	if (draw_target_tab(env))
		return (-1);
	if (draw_action_tab(env))
		return (-1);
	if (draw_launch_conditions_tab(env))
		return (-1);
	if (draw_exec_conditions_tab(env))
		return (-1);
	if (draw_button(env, env->editor.event_panel.ok, "OK"))
		return (-1);
	if (draw_button(env, env->editor.event_panel.cancel, "X"))
		return (-1);
	if (draw_event_panel_tab_content(env))
		return (-1);
	return (0);
}

int		draw_event_panel(t_env *env)
{
	t_point		text_size;

	draw_rectangle(env, new_rectangle(0xc8ccd0, 0xc8ccd0, 1, 0),
	new_point(env->editor.event_panel.pos.x, env->editor.event_panel.pos.y),
	new_point(env->editor.event_panel.size.x,
	env->editor.event_panel.size.y));
	draw_rectangle(env, new_rectangle(0xFFf1f2f3, 0xFFf1f2f3, 1, 0),
	env->editor.event_panel.pos, new_point(env->editor.event_panel.size.x - 200,
	env->editor.event_panel.top_size - 2));
	draw_rectangle(env, new_rectangle(0xe3e4e8, 0xe3e4e8 + 100, 1, 0),
	new_point(env->editor.event_panel.pos.x + 100,
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size),
	new_point(env->editor.event_panel.size.x - 100,
	env->editor.event_panel.size.y - env->editor.event_panel.top_size));
	if (TTF_SizeText(env->sdl.fonts.lato_black30, "Events", &text_size.x,
	&text_size.y))
		return (-1);
	if (print_text(new_point(env->editor.event_panel.pos.y + 17,
	env->editor.event_panel.pos.x + 70), new_printable_text("Events",
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env))
		return (-1);
	return (draw_event_panel2(env));
}
