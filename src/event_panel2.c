/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_panel2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:51:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:51:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_target_tab(t_env *env)
{
	SDL_Surface	*img;

	if (env->editor.event_panel.target_tab.anim_state == HOVER)
		img = env->ui_textures[TARGET_ICON_HOVER].surface;
	else if (env->editor.event_panel.target_tab.state == DOWN
		|| env->editor.event_panel.target_tab.anim_state == PRESSED)
		img = env->ui_textures[TARGET_ICON_DOWN].surface;
	else
		img = env->ui_textures[TARGET_ICON].surface;
	draw_button(env, env->editor.event_panel.target_tab, NULL);
	apply_surface(img, new_point(env->editor.event_panel.pos.y
	+ env->editor.event_panel.top_size + (50 - img->h / 2),
	env->editor.event_panel.pos.x + (50 - img->h / 2)),
	new_point(img->w, img->h), env);
}

void	draw_action_tab(t_env *env)
{
	SDL_Surface	*img;

	if (env->editor.event_panel.action_tab.anim_state == HOVER)
		img = env->ui_textures[ACTION_ICON_HOVER].surface;
	else if (env->editor.event_panel.action_tab.state == DOWN
		|| env->editor.event_panel.action_tab.anim_state == PRESSED)
		img = env->ui_textures[ACTION_ICON_DOWN].surface;
	else
		img = env->ui_textures[ACTION_ICON].surface;
	draw_button(env, env->editor.event_panel.action_tab, NULL);
	apply_surface(img, new_point(env->editor.event_panel.pos.y
	+ env->editor.event_panel.top_size + 100 + (50 - img->h / 2),
	env->editor.event_panel.pos.x + (50 - img->h / 2)),
	new_point(img->w, img->h), env);
}
