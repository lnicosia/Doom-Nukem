/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_tab_gestion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:03:01 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/14 16:41:11 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	editor_options_tab_keyup(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_l && env->inputs.ctrl
		&& env->sdl.event.type == SDL_KEYUP)
		env->options.lighting = env->options.lighting ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_z && env->inputs.ctrl
		&& env->sdl.event.type == SDL_KEYUP)
		env->options.zbuffer = env->options.zbuffer ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_m && env->inputs.ctrl
		&& env->sdl.event.type == SDL_KEYUP)
		env->options.show_minimap = env->options.show_minimap ? 0 : 1;
}

int		editor_3d_tabs_keyup(t_env *env)
{
	if (general_keyup(env))
		return (-1);
	if (env->editor.events_tab.state == DOWN)
	{
		if (events_tab_keyup(env))
			return (-1);
	}
	if (env->editor.sprite_tab.state == DOWN)
	{
		if (sprite_tab_keyup(env))
			return (-1);
	}
	return (0);
}

void	editor_show_tab(t_env *env)
{
	env->editor.tab = env->editor.tab ? 0 : 1;
	env->editor.draw_enemy_tab = 0;
	env->editor.draw_object_tab = 0;
	env->editor.draw_texture_tab = 0;
	env->editor.draw_sprite_tab = 0;
	env->options.editor_options = 0;
	if (env->editor.tab)
		SDL_SetRelativeMouseMode(0);
	else if (!env->editor.tab)
		SDL_SetRelativeMouseMode(1);
	SDL_GetRelativeMouseState(&env->sdl.mouse_x,
	&env->sdl.mouse_y);
	SDL_GetRelativeMouseState(&env->sdl.mouse_x,
	&env->sdl.mouse_y);
	tabs_gestion(env);
}
