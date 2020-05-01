/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:00:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:00:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		free_all_sdl_relative(t_env *env)
{
	if (env->sdl.window)
		SDL_DestroyWindow(env->sdl.window);
	if (env->sdl.renderer)
		SDL_DestroyRenderer(env->sdl.renderer);
	if (env->sdl.texture)
		SDL_DestroyTexture(env->sdl.texture);
	if (env->sdl.texture_pixels)
		ft_memdel((void**)&env->sdl.texture_pixels);
	if (env->zbuffer)
		ft_memdel((void**)&env->zbuffer);
	if (env->ymin)
		ft_memdel((void**)&env->ymin);
	if (env->ymax)
		ft_memdel((void**)&env->ymax);
}

void		free_audio(t_env *env, int i)
{
	while (i < NB_WEAPONS)
	{
		FMOD_Sound_Release(env->weapons[i].shot);
		i++;
	}
	i = 0;
	FMOD_Sound_Release(env->sound.footstep);
	while (i < NB_MUSICS)
	{
		FMOD_Sound_Release(env->sound.musics[i].music);
		i++;
	}
	FMOD_System_Close(env->sound.system);
	FMOD_System_Release(env->sound.system);
}

void		free_objects(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].nb_collision_events > 0
			&& env->objects[i].collision_events)
			free_events(env->objects[i].collision_events,
			env->objects[i].nb_collision_events);
		i++;
	}
	if (env->objects)
		ft_memdel((void**)&env->objects);
}

void		free_enemies(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].nb_death_events > 0
			&& env->enemies[i].death_events)
			free_events(env->enemies[i].death_events,
			env->enemies[i].nb_death_events);
		if (env->enemies[i].nb_collision_events > 0
			&& env->enemies[i].collision_events)
			free_events(env->enemies[i].collision_events,
			env->enemies[i].nb_collision_events);
		i++;
	}
	if (env->enemies)
		ft_memdel((void**)&env->enemies);
}
