/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_panel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:12:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 12:21:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_condition_type_tab(t_env *env)
{
	SDL_Surface	*img;

	if (env->editor.event_panel.target_tab.anim_state == HOVER)
		img = env->ui_textures[ACTION_ICON_HOVER].surface;
	else if (env->editor.event_panel.target_tab.state == DOWN
		|| env->editor.event_panel.target_tab.anim_state == PRESSED)
		img = env->ui_textures[ACTION_ICON_DOWN].surface;
	else
		img = env->ui_textures[ACTION_ICON].surface;
	draw_button(env, env->editor.event_panel.target_tab, NULL);
	apply_surface(img,
	new_point(env->editor.event_panel.pos.y + env->editor.event_panel.top_size +
	(50 - img->h / 2),
	env->editor.event_panel.pos.x + (50 - img->h / 2)),
	new_point(img->w, img->h), env);
}

void	draw_condition_target_tab(t_env *env)
{
	SDL_Surface	*img;

	if (env->editor.event_panel.action_tab.anim_state == HOVER)
		img = env->ui_textures[TARGET_ICON_HOVER].surface;
	else if (env->editor.event_panel.action_tab.state == DOWN
		|| env->editor.event_panel.action_tab.anim_state == PRESSED)
		img = env->ui_textures[TARGET_ICON_DOWN].surface;
	else
		img = env->ui_textures[TARGET_ICON].surface;
	draw_button(env, env->editor.event_panel.action_tab, NULL);
	apply_surface(img,
	new_point(env->editor.event_panel.pos.y + env->editor.event_panel.top_size +
	100 + (50 - img->h / 2),
	env->editor.event_panel.pos.x + (50 - img->h / 2)),
	new_point(img->w, img->h), env);
}

void	draw_condition_condition_panel(t_env *env)
{
	draw_button(env, env->editor.condition_panel.equals, "=");
	draw_button(env, env->editor.condition_panel.different, "!=");
	draw_button(env, env->editor.condition_panel.less, "<");
	draw_button(env, env->editor.condition_panel.greater, ">");
	draw_button(env, env->editor.condition_panel.less_or_equals, "<=");
	draw_button(env, env->editor.condition_panel.greater_or_equals, ">=");
	draw_button(env, env->editor.condition_panel.event_ended, "end");
	draw_button(env, env->editor.condition_panel.event_ended_start, "end(start)");
	draw_button(env, env->editor.condition_panel.function, "func");
}

void	draw_condition_panel_tab_content(t_env *env)
{
	if (env->editor.event_panel.target_tab.state == DOWN)
		draw_condition_condition_panel(env);
	/*else if (env->editor.event_panel.action_tab.state == DOWN)
		draw_condition_target_panel(env);*/
}

int		draw_condition_panel(t_env *env)
{
	t_point		text_size;

	// Background
	draw_rectangle(env, new_rectangle(0xc8ccd0, 0xc8ccd0, 1, 0),
	new_point(env->editor.event_panel.pos.x, env->editor.event_panel.pos.y),
	new_point(env->editor.event_panel.size.x,
	env->editor.event_panel.size.y - 200));

	// Bande du haut
	draw_rectangle(env, new_rectangle(0xFFf1f2f3, 0xFFf1f2f3, 1, 0),
	env->editor.event_panel.pos, new_point(env->editor.event_panel.size.x - 200,
	env->editor.event_panel.top_size - 2));

	// Panneau principal
	draw_rectangle(env, new_rectangle(0xe3e4e8, 0xe3e4e8 + 100, 1, 0),
	new_point(env->editor.event_panel.pos.x + 100,
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size),
	new_point(env->editor.event_panel.size.x - 100,
	env->editor.event_panel.size.y - env->editor.event_panel.top_size - 200));

	// Text
	//ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Events");
	TTF_SizeText(env->sdl.fonts.lato_black30, "Condition", &text_size.x,
	&text_size.y);
	print_text(new_point(env->editor.event_panel.pos.y + 20,
	env->editor.event_panel.pos.x + 75), new_printable_text("Condition",
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env);

	apply_surface(env->ui_textures[CONDITION_ICON].surface,
	new_point(env->editor.event_panel.pos.y +
	(env->editor.event_panel.top_size / 2 -
	env->ui_textures[CONDITION_ICON].surface->h / 2),
	env->editor.event_panel.pos.x +
	(env->editor.event_panel.top_size / 2 -
	env->ui_textures[CONDITION_ICON].surface->h / 2)),
	new_point(env->ui_textures[CONDITION_ICON].surface->w,
	env->ui_textures[CONDITION_ICON].surface->h), env);

	draw_button(env, env->editor.event_panel.ok, "OK");
	draw_button(env, env->editor.event_panel.cancel, "X");
	draw_condition_type_tab(env);
	draw_condition_target_tab(env);
	draw_condition_panel_tab_content(env);
	int x, y = 0;
	x = env->editor.event_panel.pos.x + 100
	+ env->editor.event_panel.content_panel_size.x / 2;
	y = env->editor.event_panel.pos.y + env->editor.event_panel.top_size;
	while (y <= env->editor.event_panel.pos.y + env->editor.event_panel.size.y)
	{
		env->sdl.texture_pixels[x + y * env->w] = 0;
		y++;
	}
	x = env->editor.event_panel.pos.x + 100;
	y = env->editor.event_panel.pos.y + env->editor.event_panel.top_size
	+ env->editor.event_panel.content_panel_size.y / 2;
	while (x <= env->editor.event_panel.pos.x + env->editor.event_panel.size.x)
	{
		env->sdl.texture_pixels[x + y * env->w] = 0;
		x++;
	}
	return (0);
}
