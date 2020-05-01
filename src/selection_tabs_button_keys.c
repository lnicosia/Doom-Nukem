/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_tabs_button_keys.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:33:05 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 10:44:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		texture_selection_tab_keys(t_env *env)
{
	int	i;

	i = 0;
	if (env->editor.draw_texture_tab)
	{
		while (i < MAX_WALL_TEXTURE)
		{
			if (button_keys(&env->editor.textures[i], env))
				return (-1);
			i++;
		}
		i = 0;
		while (i < MAX_SKYBOX)
		{
			if (button_keys(&env->editor.skyboxes[i], env))
				return (-1);
			i++;
		}
	}
	return (0);
}

int		selection_tab_button_keys2(t_env *env)
{
	int	i;

	i = 0;
	if (env->editor.draw_object_tab)
	{
		while (i < MAX_OBJECTS)
		{
			if (button_keys(&env->editor.object_tab[i], env))
				return (-1);
			i++;
		}
	}
	return (0);
}

int		selection_tab_button_keys(t_env *env)
{
	int	i;

	i = 0;
	if (texture_selection_tab_keys(env))
		return (-1);
	if (env->editor.draw_enemy_tab)
	{
		while (i < MAX_ENEMIES)
		{
			if (button_keys(&env->editor.enemy_tab[i], env))
				return (-1);
			i++;
		}
	}
	if (env->editor.draw_sprite_tab)
	{
		while (i < MAX_OBJECTS)
		{
			if (button_keys(&env->editor.sprite_selection[i], env))
				return (-1);
			i++;
		}
	}
	return (selection_tab_button_keys2(env));
}
