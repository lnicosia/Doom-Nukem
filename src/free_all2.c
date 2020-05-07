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
	ft_printf("sprites\n");
	while (i < MAX_TEXTURES)
	{
		ft_printf("i = %d\n", i);
		if (env->sprite_textures[i].surface)
			SDL_FreeSurface(env->sprite_textures[i].surface);
		j = 0;
		ft_printf("texture has %d maps\n", env->sprite_textures[i].nb_maps);
		while (j < env->sprite_textures[i].nb_maps - 1)
		{
			ft_printf("j = %d\n", j);
			ft_printf("map[%d] addr = %p\n", j, env->sprite_textures[i].maps[j]);
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
	ft_printf("walls\n");
	while (i < MAX_WALL_TEXTURE)
	{
		ft_printf("i = %d\n", i);
		if (env->wall_textures[i].surface)
			SDL_FreeSurface(env->wall_textures[i].surface);
		j = 0;
		ft_printf("texture has %d maps\n", env->wall_textures[i].nb_maps);
		while (j < env->wall_textures[i].nb_maps - 1)
		{
			ft_printf("j = %d\n", j);
			ft_printf("map[%d] addr = %p\n", j, env->wall_textures[i].maps[j]);
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
	ft_printf("ui\n");
	while (i < MAX_UI_TEXTURES)
	{
		ft_printf("i = %d\n", i);
		if (env->ui_textures[i].surface)
			SDL_FreeSurface(env->ui_textures[i].surface);
		j = 0;
		ft_printf("texture has %d maps\n", env->ui_textures[i].nb_maps);
		while (j < env->ui_textures[i].nb_maps - 1)
		{
			ft_printf("j = %d\n", j);
			ft_printf("map[%d] addr = %p\n", j, env->ui_textures[i].maps[j]);
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

	i = 0;
	ft_printf("mini skyboxes\n");
	while (i < MAX_SKYBOX * 2)
	{
		ft_printf("i = %d\n", i);
		if (env->mini_skyboxes[i].surface)
			SDL_FreeSurface(env->mini_skyboxes[i].surface);
		i++;
	}
}

void		free_skyboxes(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("skyboxes\n");
	while (i < MAX_SKYBOX)
	{
		ft_printf("skybox %d\n", i);
		j = 0;
		while (j < 6)
		{
			ft_printf("skybox side %d\n", j);
			if (env->skyboxes[i].textures[j].surface)
				SDL_FreeSurface(env->skyboxes[i].textures[j].surface);
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
