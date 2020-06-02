/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keyup2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:41:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/21 20:11:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		editor_keyup10(t_env *env)
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
	return (editor_keyup11(env));
}

int		editor_keyup9(t_env *env)
{
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
	return (editor_keyup10(env));
}

int		editor_keyup8(t_env *env)
{
	if (button_keyup(&env->editor.enemy_background, env))
		return (-1);
	if ((env->selected_object == -1
		|| env->objects[env->selected_object].sector != -1)
		&& button_keyup(&env->editor.sector_tab, env))
		return (-1);
	if (button_keyup(&env->editor.general_tab, env))
		return (-1);
	if (button_keyup(&env->editor.sprite_tab, env))
		return (-1);
	if (button_keyup(&env->editor.events_tab, env))
		return (-1);
	if (button_keyup(&env->editor.previous_ambiance_music, env))
		return (-1);
	if (button_keyup(&env->editor.previous_fighting_music, env))
		return (-1);
	if (button_keyup(&env->editor.next_ambiance_music, env))
		return (-1);
	if (button_keyup(&env->editor.next_fighting_music, env))
		return (-1);
	return (editor_keyup9(env));
}

int		editor_keyup7(t_env *env)
{
	if (!env->editor.texture_selection_just_closed)
	{
		if (button_keyup(&env->editor.current_texture_selection, env))
			return (-1);
	}
	else
		env->editor.texture_selection_just_closed = 0;
	if (!env->editor.enemy_selection_just_closed)
	{
		if (button_keyup(&env->editor.current_enemy_selection, env))
			return (-1);
	}
	else
		env->editor.enemy_selection_just_closed = 0;
	if (!env->editor.object_selection_just_closed)
	{
		if (button_keyup(&env->editor.current_object_selection, env))
			return (-1);
	}
	else
		env->editor.object_selection_just_closed = 0;
	if (button_keyup(&env->editor.texture_background, env))
		return (-1);
	return (editor_keyup8(env));
}

int		editor_keyup6(t_env *env)
{
	int	ret;

	if (env->sdl.event.key.keysym.sym == env->keys.enter
		&& env->editor.enter_locked)
		env->editor.enter_locked = 0;
	else if (env->sdl.event.key.keysym.sym == env->keys.enter
		&& !env->confirmation_box.state && !env->input_box.state
		&& !env->editor.enter_locked)
	{
		ret = valid_map(env);
		if (ret == -1)
			return (-1);
		else if (!ret)
		{
			if (going_in_3d_mode(env))
				return (-1);
		}
	}
	if (button_keyup(&env->editor.change_mode, env))
		return (-1);
	if (button_keyup(&env->editor.options, env))
		return (-1);
	if (button_keyup(&env->editor.launch_game, env))
		return (-1);
	return (editor_keyup7(env));
}
