/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:30 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:58:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int		keyup3(t_env *env)
{
	int	err;
	int	is_playing;

	if (env->sdl.event.key.keysym.sym == SDLK_o)
		env->option = env->option ? 0 : 1;
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keyup(&env->confirmation_box, env))
			return (-1);
	}
	if (env->player.curr_weapon == GATLING
		&& env->sdl.event.type == SDL_MOUSEBUTTONUP
		&& FMOD_Channel_IsPlaying(env->sound.player_shots_chan, &is_playing)
		== FMOD_OK && is_playing == 1)
	{
		if ((err = FMOD_Channel_Stop(env->sound.player_shots_chan)) !=
			FMOD_OK)
			return (custom_error("Could not stop player shots channel"
				" (error %d)\n", err));
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
		reset_hover(env);
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
