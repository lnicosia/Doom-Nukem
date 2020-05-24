/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 01:56:26 by marvin            #+#    #+#             */
/*   Updated: 2020/05/18 15:33:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_resources_init3(t_env *env)
{
	int	i;

	i = 0;
	while (i < NB_WALL_SPRITES)
	{
		ft_memdel((void**)&env->init.sprites_names[i]);
		i++;
	}
	i = 0;
	while (i < NB_FONTS_FILE)
	{
		ft_memdel((void**)&env->init.fonts_names[i]);
		i++;
	}
	i = 0;
	while (i < MAX_SKYBOX * 6)
	{
		ft_memdel((void**)&env->init.skyboxes_names[i]);
		i++;
	}
}

void	free_resources_init2(t_env *env)
{
	int	i;

	i = 0;
	i = 0;
	while (i < NB_MUSICS)
	{
		ft_memdel((void**)&env->init.musics_names[i]);
		i++;
	}
	i = 0;
	while (i < MAX_WALL_TEXTURE)
	{
		ft_memdel((void**)&env->init.text_name[i]);
		i++;
	}
	i = 0;
	while (i < MAX_OBJECTS)
	{
		ft_memdel((void**)&env->init.objects_names[i]);
		i++;
	}
	i = 0;
	free_resources_init3(env);
}

void	free_resources_init(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_ENEMIES)
	{
		ft_memdel((void**)&env->init.enemy_names[i]);
		i++;
	}
	i = 0;
	while (i < NB_HUD_FILES)
	{
		ft_memdel((void**)&env->init.hud_names[i]);
		i++;
	}
	i = 0;
	while (i < NB_SOUNDS)
	{
		ft_memdel((void**)&env->init.sounds_names[i]);
		i++;
	}
	free_resources_init2(env);
}
