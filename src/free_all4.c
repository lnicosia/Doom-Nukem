/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:27:10 by marvin            #+#    #+#             */
/*   Updated: 2020/05/18 15:32:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		free_sprite_textures(t_env *env)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < MAX_SPRITES_TEXTURES)
	{
		if (env->sprite_textures[i].surface)
			SDL_FreeSurface(env->sprite_textures[i].surface);
		if (env->sprite_textures[i].nb_maps > 0)
		{
			j = 0;
			while (j < env->sprite_textures[i].nb_maps - 1)
			{
				if (env->sprite_textures[i].maps[j])
					SDL_FreeSurface(env->sprite_textures[i].maps[j]);
				j++;
			}
			if (env->sprite_textures[i].maps)
				ft_memdel((void**)&env->sprite_textures[i].maps);
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
		if (env->wall_textures[i].nb_maps > 0)
		{
			j = 0;
			while (j < env->wall_textures[i].nb_maps - 1)
			{
				if (env->wall_textures[i].maps[j])
					SDL_FreeSurface(env->wall_textures[i].maps[j]);
				j++;
			}
			if (env->wall_textures[i].maps)
				ft_memdel((void**)&env->wall_textures[i].maps);
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
		if (env->ui_textures[i].nb_maps > 0)
		{
			j = 0;
			while (j < env->ui_textures[i].nb_maps - 1)
			{
				if (env->ui_textures[i].maps[j])
					SDL_FreeSurface(env->ui_textures[i].maps[j]);
				j++;
			}
			if (env->ui_textures[i].maps)
				ft_memdel((void**)&env->ui_textures[i].maps);
		}
		i++;
	}
}

void		free_mini_skyboxes_textures(t_env *env)
{
	int		i;

	i = 0;
	while (i < MAX_SKYBOX * 2)
	{
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
	while (i < MAX_SKYBOX)
	{
		j = 0;
		while (j < 6)
		{
			if (env->skyboxes[i].textures[j].surface)
				SDL_FreeSurface(env->skyboxes[i].textures[j].surface);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (env->skybox[i].texture_scale)
			ft_memdel((void**)&env->skybox[i].texture_scale);
		i++;
	}
}
