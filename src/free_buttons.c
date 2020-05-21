/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:32:58 by marvin            #+#    #+#             */
/*   Updated: 2020/05/18 15:33:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	free_texture_selection_buttons(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_WALL_TEXTURE)
	{
		if (env->editor.textures[i].release_param)
			ft_memdel((void**)&env->editor.textures[i].release_param);
		i++;
	}
}

void	free_enemy_selection_buttons(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_ENEMIES)
	{
		if (env->editor.enemy_tab[i].release_param)
			ft_memdel((void**)&env->editor.enemy_tab[i].release_param);
		i++;
	}
}

void	free_object_selection_buttons(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_OBJECTS)
	{
		if (env->editor.object_tab[i].release_param)
			ft_memdel((void**)&env->editor.object_tab[i].release_param);
		i++;
	}
}

void	free_sprite_selection_buttons(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_OBJECTS)
	{
		if (env->editor.sprite_selection[i].release_param)
			ft_memdel((void**)&env->editor.sprite_selection[i].release_param);
		i++;
	}
	if (env->editor.current_sprite_selection.release_param)
		ft_memdel((void**)&env->editor.current_sprite_selection.release_param);
}

void	free_buttons(t_env *env)
{
	int	i;

	free_texture_selection_buttons(env);
	free_enemy_selection_buttons(env);
	free_object_selection_buttons(env);
	free_sprite_selection_buttons(env);
	i = 0;
	while (i < MAX_SKYBOX + MAX_SKYBOX)
	{
		if (env->editor.skyboxes[i].release_param)
			ft_memdel((void**)&env->editor.skyboxes[i].release_param);
		i++;
	}
}
