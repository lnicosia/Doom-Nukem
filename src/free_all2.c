/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:00:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:00:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		free_sprite_textures(t_env *env)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < MAX_TEXTURES)
	{
		if (env->sprite_textures[i].surface)
			SDL_FreeSurface(env->sprite_textures[i].surface);
		j = 0;
		while (j < env->sprite_textures[i].nb_maps)
		{
			if (env->sprite_textures[i].maps[j])
				SDL_FreeSurface(env->sprite_textures[i].maps[j]);
			j++;
		}
		i++;
	}
}

void		free_wall_textures(t_env *env)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < MAX_WALL_TEXTURE)
	{
		if (env->wall_textures[i].surface)
			SDL_FreeSurface(env->wall_textures[i].surface);
		j = 0;
		while (j < env->wall_textures[i].nb_maps)
		{
			if (env->wall_textures[i].maps[j])
				SDL_FreeSurface(env->wall_textures[i].maps[j]);
			j++;
		}
		i++;
	}
}

void		free_ui_textures(t_env *env)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < MAX_UI_TEXTURES)
	{
		if (env->ui_textures[i].surface)
			SDL_FreeSurface(env->ui_textures[i].surface);
		j = 0;
		while (j < env->ui_textures[i].nb_maps)
		{
			if (env->ui_textures[i].maps[j])
				SDL_FreeSurface(env->ui_textures[i].maps[j]);
			j++;
		}
		i++;
	}
}

void		free_mini_skyboxes_textures(t_env *env)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < MAX_SKYBOX * 2)
	{
		if (env->mini_skyboxes[i].surface)
			SDL_FreeSurface(env->mini_skyboxes[i].surface);
		j = 0;
		while (j < env->mini_skyboxes[i].nb_maps)
		{
			if (env->mini_skyboxes[i].maps[j])
				SDL_FreeSurface(env->mini_skyboxes[i].maps[j]);
			j++;
		}
		i++;
	}
}

void		free_skyboxes(t_env *env)
{
	int		i;
	int		j;
	size_t	k;

	i = 0;
	while (i < MAX_SKYBOX)
	{
		j = 0;
		while (j < 6)
		{
			if (env->skyboxes[i].textures[j].surface)
				SDL_FreeSurface(env->skyboxes[i].textures[j].surface);
			k = 0;
			while (k < env->skyboxes[i].textures[j].nb_maps)
			{
				if (env->skyboxes[i].textures[j].maps[k])
					SDL_FreeSurface(env->skyboxes[i].textures[j].maps[k]);
				k++;
			}
			j++;
		}
		i++;
	}
}

void		free_textures(t_env *env)
{
	free_sprite_textures(env);
	free_wall_textures(env);
	free_ui_textures(env);
	free_mini_skyboxes_textures(env);
	free_skyboxes(env);
}

void		free_event(t_event *event)
{
	if (event->exec_param)
		ft_memdel((void**)&event->exec_param);
	if (event->launch_conditions)
		ft_memdel((void**)&event->launch_conditions);
	if (event->exec_conditions)
		ft_memdel((void**)&event->exec_conditions);
}

void		free_events(t_event **events, size_t *size)
{
	size_t	j;

	j = 0;
	while (j < *size)
	{
		free_event(&(*events)[j]);
		j++;
	}
	if (events)
		ft_memdel((void**)events);
	*size = 0;
}

void		free_sectors(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_sectors)
	{
		free_sector(&env->sectors[i]);
		i++;
	}
	ft_memdel((void**)&env->sectors);
}
