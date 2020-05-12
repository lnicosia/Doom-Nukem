/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existing_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:48:21 by marvin            #+#    #+#             */
/*   Updated: 2020/05/11 15:42:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		wall_textures(t_env *env, char *name)
{
	int	i;

	i = 0;
	while (i < MAX_WALL_TEXTURE)
	{
		if (!(ft_strcmp(name, env->init.text_name[i]))
		&& env->init.textures[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

int		sprites_textures(t_env *env, char *name)
{
	int	i;

	i = 0;
	while (i < MAX_ENEMIES)
	{
		if (!(ft_strcmp(name, env->init.enemy_names[i]))
		&& env->init.enemies[i] == 1)
			return (1);
		i++;
	}
	i = 0;
	while (i < NB_OBJECTS_SPRITES)
	{
		if (!(ft_strcmp(name, env->init.sprites_names[i]))
		&& env->init.sprites[i] == 1)
		{
			ft_printf("object sprite bullshit\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int		skyboxes_textures(t_env *env, char *name)
{
	int	i;

	i = 0;
	while (i < MAX_SKYBOX * 6)
	{
		if (!(ft_strcmp(name, env->init.skyboxes_names[i]))
		&& env->init.skyboxes[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

int		hud_textures(t_env *env, char *name)
{
	int	i;

	i = 0;
	while (i < NB_HUD_FILES)
	{
		if (!(ft_strcmp(name, env->init.hud_names[i]))
		&& env->init.hud[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

int		check_existing_files(t_env *env, char *name)
{
	if (wall_textures(env, name))
		return (1);
	if (sprites_textures(env, name))
		return (2);
	if (skyboxes_textures(env, name))
		return (3);
	if (hud_textures(env, name))
		return (4);
	return (0);
}