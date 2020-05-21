/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:38:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/30 12:01:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_button_param	*new_button_param(t_env *env, int i)
{
	t_button_param	*new;

	if (!(new = (t_button_param*)ft_memalloc(sizeof(t_button_param))))
		return (0);
	new->env = env;
	new->i = i;
	return (new);
}

void			init_options_buttons(t_env *env)
{
	editor_mode_button(env);
	editor_save_button(env);
	editor_launch_game(env);
	editor_options_button(env);
}

void			init_informations_tab(t_env *env)
{
	env->editor.sector_tab = new_tab_button(WHEN_DOWN, &sector_tab, env, env);
	env->editor.sector_tab.str = "Sector";
	env->editor.sector_tab.pos = new_point(139, 425);
	env->editor.general_tab = new_tab_button(WHEN_DOWN, &general_tab, env, env);
	env->editor.general_tab.str = "General";
	env->editor.general_tab.pos = new_point(20, 425);
	env->editor.sprite_tab = new_tab_button(WHEN_DOWN, &sprite_tab, env, env);
	env->editor.sprite_tab.str = "General";
	env->editor.sprite_tab.pos = new_point(258, 425);
	env->editor.events_tab = new_tab_button(WHEN_DOWN, &events_tab, env, env);
	env->editor.events_tab.str = "Events";
	env->editor.events_tab.pos = new_point(377, 425);
}

void			init_music_selection_buttons(t_env *env)
{
	env->editor.next_ambiance_music =
	new_next_button(ON_RELEASE, &next_ambiance_music, env, env);
	env->editor.next_ambiance_music.pos = new_point(160, 315);
	env->editor.previous_ambiance_music =
	new_previous_button(ON_RELEASE, &previous_ambiance_music, env, env);
	env->editor.previous_ambiance_music.pos = new_point(25, 315);
	env->editor.next_fighting_music =
	new_next_button(ON_RELEASE, &next_fighting_music, env, env);
	env->editor.next_fighting_music.pos = new_point(160, 360);
	env->editor.previous_fighting_music =
	new_previous_button(ON_RELEASE, &previous_fighting_music, env, env);
	env->editor.previous_fighting_music.pos = new_point(25, 360);
}

int				init_editor_hud(t_env *env)
{
	if (init_array_texture_buttons(env))
		return (-1);
	init_add_buttons(env);
	init_music_selection_buttons(env);
	if (init_enemy_selection_button(env))
		return (-1);
	if (init_object_selection_button(env))
		return (-1);
	if (init_array_sprite_buttons(env))
		return (-1);
	if (init_skybox_selection_buttons(env))
		return (-1);
	init_informations_tab(env);
	init_options_buttons(env);
	init_editor_options_buttons(env);
	init_editor_tab_buttons(env);
	init_events_selection_buttons(env);
	init_event_panel_buttons(env);
	init_events_creation_buttons(env);
	return (0);
}
