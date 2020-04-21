/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:30 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 19:09:18 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		keyup3(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_o)
		env->option = env->option ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_TAB)
		env->options.zbuffer = env->options.zbuffer ? 0 : 1;
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keyup(&env->confirmation_box, env))
			return (-1);
	}
	return (0);
}

int		start_press_event(t_env *env)
{
	if (start_event(&env->sectors[env->hovered_wall_sprite_sector].
	wall_sprites[env->hovered_wall_sprite_wall].
	press_events[env->hovered_wall_sprite_sprite],
	&env->sectors[env->hovered_wall_sprite_sector].
	wall_sprites[env->hovered_wall_sprite_wall].
	nb_press_events[env->hovered_wall_sprite_sprite], env))
		return (-1);
	if (env->sectors[env->hovered_wall_sprite_sector].
	wall_sprites[env->hovered_wall_sprite_wall].
	nb_press_events[env->hovered_wall_sprite_sprite] == 0)
	{
		env->hovered_wall_sprite_wall = -1;
		env->hovered_wall_sprite_sector = -1;
		env->hovered_wall_sprite_sprite = -1;
	}
	return (0);
}

int		keyup2(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_e
		&& env->hovered_wall_sprite_sprite != -1
		&& env->hovered_wall_sprite_wall != -1
		&& env->hovered_wall_sprite_sector != -1
		&& env->sectors[env->hovered_wall_sprite_sector].
		wall_sprites[env->hovered_wall_sprite_wall].
		nb_press_events[env->hovered_wall_sprite_sprite]
		&& env->sectors[env->hovered_wall_sprite_sector].
		wall_sprites[env->hovered_wall_sprite_wall].
		press_events[env->hovered_wall_sprite_sprite])
	{
	  	if (start_press_event(env))
		  	return (-1);
	}
	return (keyup3(env));
}

int		keyup(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_m && env)
		env->options.show_minimap = env->options.show_minimap ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_f)
		env->options.show_fps = env->options.show_fps ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN && env->dialog_box
	  && !env->confirmation_box.state)
		env->next_dialog = 1;
	if (env->sdl.event.key.keysym.sym == env->keys.enter
		&& env->editor.enter_locked)
		env->editor.enter_locked = 0;
	if (env->sdl.event.key.keysym.sym == SDLK_n)
		env->drawing = env->drawing ? 0 : 1;
	return (keyup2(env));
}
