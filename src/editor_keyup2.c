/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keyup2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:41:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:41:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		space_pressed(t_env *env)
{
	int	clicked_vertex;
	int	ret;

	env->inputs.space = 0;
	if (!vertex_creation_possible(env))
		return (1);
	clicked_vertex = get_existing_vertex(env);
	if (clicked_vertex == -1)
	{
		if ((ret = new_vertex(env, clicked_vertex)) != 1)
			return (ret);
	}
	else if (clicked_vertex >= 0)
	{
		if ((ret = existing_vertex(env, clicked_vertex)) != 1)
			return (ret);
	}
	return (1);
}

int		editor_keyup9(t_env *env)
{
	int	i;

	i = 0;
	if (env->editor.draw_enemy_tab)
	{
		while (i < MAX_ENEMIES)
		{
			if (button_keyup(&env->editor.enemy_tab[i], env))
				return (-1);
			i++;
		}
	}
	if (env->editor.draw_object_tab)
	{
		while (i < MAX_OBJECTS)
		{
			if (button_keyup(&env->editor.object_tab[i], env))
				return (-1);
			i++;
		}
	}
	return (0);
}

int		editor_keyup8(t_env *env)
{
	int	i;

	i = 0;
	if (env->editor.draw_texture_tab)
	{
		while (i < MAX_WALL_TEXTURE)
		{
			if (button_keyup(&env->editor.textures[i], env))
				return (-1);
			i++;
		}
		i = 0;
		while (i < MAX_SKYBOX)
		{
			button_keyup(&env->editor.skyboxes[i], env);
			i++;
		}
	}
	return (editor_keyup9(env));
}

int		editor_keyup7(t_env *env)
{
	if (button_keyup(&env->editor.previous_fighting_music, env))
		return (-1);
	if (button_keyup(&env->editor.next_ambiance_music, env))
		return (-1);
	if (button_keyup(&env->editor.next_fighting_music, env))
		return (-1);
	if (env->editor.events_tab.state == DOWN)
	{
		if (events_tab_keyup(env))
			return (-1);
	}
	if (env->editor.selected_sector != -1 && sector_buttons_up(env))
		return (-1);
	if (env->editor.selected_start_player != -1 && player_buttons_up(env))
		return (-1);
	if (env->selected_enemy != -1 && enemy_buttons_up(env))
		return (-1);
	if (env->selected_object != -1 && object_buttons_up(env))
		return (-1);
	return (editor_keyup8(env));
}

int		editor_keyup6(t_env *env)
{
	if (button_keyup(&env->editor.options, env))
		return (-1);
	if (button_keyup(&env->editor.launch_game, env))
		return (-1);
	if (button_keyup(&env->editor.current_texture_selection, env))
		return (-1);
	if (button_keyup(&env->editor.current_enemy_selection, env))
		return (-1);
	if (button_keyup(&env->editor.current_object_selection, env))
		return (-1);
	if (button_keyup(&env->editor.texture_background, env))
		return (-1);
	if (button_keyup(&env->editor.enemy_background, env))
		return (-1);
	if (button_keyup(&env->editor.sector_tab, env))
		return (-1);
	if (button_keyup(&env->editor.general_tab, env))
		return (-1);
	if (button_keyup(&env->editor.sprite_tab, env))
		return (-1);
	if (button_keyup(&env->editor.events_tab, env))
		return (-1);
	if (button_keyup(&env->editor.previous_ambiance_music, env))
		return (-1);
	return (editor_keyup7(env));
}
