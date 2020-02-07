/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:44:44 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/04 14:37:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	editor_hud(t_env *env)
{
	if (!env->editor.in_game || (env->editor.in_game &&  env->editor.tab))
	{
		//background
		draw_rectangle(env,
			new_rectangle(0xbdc3c7, 0xbdc3c7, 1, 0),
			new_point(0 , 0),
			new_point(400, 900));
		// left rectangle
		draw_rectangle(env,	
			new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
			new_point(20 , 40),
			new_point(170, 225));
		// music rectangle
		draw_rectangle(env,	
			new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
			new_point(20 , 290),
			new_point(170, 110));
		// right rectangle
		draw_rectangle(env,	
			new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
			new_point(210 , 40),
			new_point(170, 360));
		apply_surface(env->ui_textures[24].surface, new_point(296, 230), new_point(128, 89), env);
		apply_surface(env->ui_textures[24].surface, new_point(196, 230), new_point(128, 89), env);
		//apply_surface(env->ui_textures[24].surface, new_point(120, 230), new_point(128, 89), env);
		draw_button(env, env->editor.add_enemy, env->editor.add_enemy.str);
		draw_button(env, env->editor.add_object, env->editor.add_object.str);
		/*draw_button(env, env->editor.texture_background,
		env->editor.texture_background.str);
		draw_button(env, env->editor.enemy_background,
		env->editor.enemy_background.str);*/
		draw_button(env, env->editor.current_texture_selection,
		env->editor.current_texture_selection.str);
		draw_button(env, env->editor.current_enemy_selection,
		env->editor.current_enemy_selection.str);
		draw_button(env, env->editor.change_mode, env->editor.change_mode.str);
		draw_button(env, env->editor.launch_game, env->editor.launch_game.str);
		draw_button(env, env->editor.options, env->editor.options.str);
		draw_button(env, env->editor.save, env->editor.save.str);
		draw_rectangle(env,
				new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
				new_point(20 , 450),
				new_point(360, 430));
		draw_editor_tabs(env);
		if (env->editor.draw_enemy_tab)
			enemy_tab(env, MAX_ENEMIES);
		if (env->editor.draw_sprite_tab)
			sprite_selection(env, MAX_OBJECTS);
		if (env->editor.draw_selection_tab || env->editor.draw_enemy_tab
		|| env->editor.draw_sprite_tab)
			env->editor.selection_tab = 1;
		else
			env->editor.selection_tab = 0;
	}
}
