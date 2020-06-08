/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:14:57 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/11 17:54:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "draw.h"

int		all_editor_keyup(t_env *env)
{
	if (!env->input_box.state && (env->sdl.event.type == SDL_KEYUP
		|| env->sdl.event.type == SDL_MOUSEBUTTONUP))
	{
		if (!env->editor.in_game && !env->options.editor_options)
		{
			if (editor_keyup(env))
				return (custom_error("Crash from editor 2D keyup\n"));
		}
		else if (!env->options.editor_options && env->editor.in_game)
		{
			if (editor_3d_keyup(env))
				return (custom_error("Crash from editor 3D keyup\n"));
		}
		else if (env->options.editor_options)
		{
			if (editor_options_keyup(env))
				return (-1);
			if (env->sdl.event.key.keysym.sym == SDLK_TAB)
				editor_show_tab(env);
		}
	}
	return (0);
}

int		editor_poll_event(t_env *env)
{
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT || (env->sdl.event.type == SDL_KEYUP
			&& env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
			env->running = 0;
		else if (env->sdl.event.type == SDL_KEYDOWN
				|| env->sdl.event.type == SDL_KEYUP
				|| env->sdl.event.type == SDL_MOUSEBUTTONDOWN
				|| env->sdl.event.type == SDL_MOUSEBUTTONUP
				|| env->sdl.event.type == SDL_MOUSEWHEEL)
			update_inputs(env);
		if (all_editor_keyup(env))
			return (-1);
		zoom(env);
		if (env->input_box.state)
		{
			if (input_box_keys(&env->input_box, env))
				return (custom_error("Crash from input box keys\n"));
		}
	}
	return (0);
}

int		editor1(t_env *env)
{
	if (editor_hud(env))
		return (-1);
	if (env->confirmation_box.state)
	{
		if (draw_confirmation_box(&env->confirmation_box, env))
			return (-1);
	}
	if (env->input_box.state)
	{
		if (draw_input_box(&env->input_box, env))
			return (-1);
	}
	if (env->options.zbuffer && env->editor.in_game)
	{
		if (update_screen_zbuffer(env))
			return (-1);
	}
	else
	{
		if (update_screen(env))
			return (-1);
	}
	return (0);
}

int		editor(t_env *env)
{
	while (env->running)
	{
		env->pid = getpid();
		clear_image(env);
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		SDL_GetMouseState(&env->sdl.mx, &env->sdl.my);
		if (editor_poll_event(env))
			return (crash("Editor poll event failed\n", env));
		if (!env->editor.in_game)
		{
			if (editor_2d(env))
				return (crash("Editor 2d failed\n", env));
		}
		else if (env->editor.in_game)
		{
			if (editor_render(env))
				return (crash("Render function failed\n", env));
		}
		if (editor1(env))
			return (crash("editor failed\n", env));
		env->speed_time = SDL_GetTicks();
	}
	free_all(env);
	return (0);
}
