/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:44:44 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/04 17:56:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	editor_hud(t_env *env)
{
	t_point	center;
	t_point	size;

	center = new_point(0, 0);
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
		TTF_SizeText(env->sdl.fonts.lato_bold15, "Ambiance", &center.x, &center.y);
		print_text(new_point(300, 105 - center.x / 2), new_printable_text("Ambiance",
		env->sdl.fonts.lato_bold15 , 0x00000000, 15), env);

		/*print_text(new_point(300, 85), new_printable_text(
		env->sound.musics[env->editor.ambiance_music].music_name,
		env->sdl.fonts.lato15 , 0x00000000, 15), env);*/

		TTF_SizeText(env->sdl.fonts.lato15, 
		env->sound.musics[env->sound.ambient_music].music_name, &center.x, &center.y);
		print_text(new_point(322, 105 - center.x / 2), new_printable_text(
		env->sound.musics[env->sound.ambient_music].music_name,
		env->sdl.fonts.lato15 , 0x00000000, 15), env);	

		TTF_SizeText(env->sdl.fonts.lato_bold15, "fight", &center.x, &center.y);
		print_text(new_point(345, 90), new_printable_text("Fight",
		env->sdl.fonts.lato_bold15, 0x00000000, 15), env);

		TTF_SizeText(env->sdl.fonts.lato15,
			env->sound.musics[env->sound.fight_music].music_name, &center.x, &center.y);
		print_text(new_point(367, 105 - center.x / 2), new_printable_text(
			env->sound.musics[env->sound.fight_music].music_name,
			env->sdl.fonts.lato15 , 0x00000000, 15), env);
		// right rectangle
		draw_rectangle(env,	
			new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
			new_point(210 , 40),
			new_point(170, 360));
		apply_surface(env->ui_textures[24].surface, new_point(296, 230), new_point(128, 89), env);
		apply_surface(env->ui_textures[24].surface, new_point(196, 230), new_point(128, 89), env);
		draw_button(env, env->editor.add_enemy, env->editor.add_enemy.str);
		draw_button(env, env->editor.add_object, env->editor.add_object.str);
		draw_button(env, env->editor.current_texture_selection,
		env->editor.current_texture_selection.str);
		//draw_button(env, env->editor.current_enemy_selection,
		//env->editor.current_enemy_selection.str);
		if (env->enemy_sprites[env->editor.current_enemy].size[0].x >
			env->enemy_sprites[env->editor.current_enemy].size[0].y)
			size = new_point(60, 60
			/ (env->enemy_sprites[env->editor.current_enemy].size[0].x
			/ (double)env->enemy_sprites[env->editor.current_enemy].size[0].y));
		else
			size = new_point(60
			* (env->enemy_sprites[env->editor.current_enemy].size[0].x
			/ (double)env->enemy_sprites[env->editor.current_enemy].size[0].y),
			60);
		apply_sprite(env->enemy_sprites[env->editor.current_enemy],
		new_point(env->editor.current_enemy_selection.pos.y + 32 - size.y / 2,
		env->editor.current_enemy_selection.pos.x + 32 - size.x / 2),
		size, env);
		if (env->object_sprites[env->editor.current_object].size[0].x >
			env->object_sprites[env->editor.current_object].size[0].y)
			size = new_point(60, 60
			/ (env->object_sprites[env->editor.current_object].size[0].x
			/ (double)env->object_sprites[env->editor.current_object].
			size[0].y));
		else
			size = new_point(60
			* (env->object_sprites[env->editor.current_object].size[0].x
			/ (double)env->object_sprites[env->editor.current_object].
			size[0].y), 60);
		apply_sprite(env->object_sprites[env->editor.current_object],
		new_point(env->editor.current_object_selection.pos.y + 32 - size.y / 2,
		env->editor.current_object_selection.pos.x + 32 - size.x / 2),
		size, env);
		draw_button(env, env->editor.change_mode, env->editor.change_mode.str);
		draw_button(env, env->editor.launch_game, env->editor.launch_game.str);
		draw_button(env, env->editor.options, env->editor.options.str);
		draw_button(env, env->editor.save, env->editor.save.str);
		if (!env->editor.in_game || (env->editor.in_game && env->editor.tab))
		{
			draw_button(env, env->editor.previous_ambiance_music,
			env->editor.previous_ambiance_music.str);
			draw_button(env, env->editor.next_ambiance_music,
			env->editor.next_ambiance_music.str);
			draw_button(env, env->editor.previous_fighting_music,
			env->editor.previous_fighting_music.str);
			draw_button(env, env->editor.next_fighting_music,
			env->editor.next_fighting_music.str);
		}
		draw_rectangle(env,
				new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
				new_point(20 , 450),
				new_point(360, 430));
		draw_editor_tabs(env);
		if (env->editor.draw_enemy_tab)
			enemy_tab(env, MAX_ENEMIES);
		if (env->editor.draw_object_tab)
			object_tab(env, MAX_OBJECTS);
		if (env->editor.draw_sprite_tab)
			sprite_selection(env, MAX_OBJECTS);
		if (env->editor.draw_texture_tab || env->editor.draw_enemy_tab
		|| env->editor.draw_sprite_tab)
			env->editor.texture_tab = 1;
		else
			env->editor.texture_tab = 0;
	}
	if (env->editor.creating_event)
	{
		if (env->editor.creating_condition)
			draw_condition_panel(env);
		else
			draw_event_panel(env);
	}
	if (env->editor.selecting_weapon || env->editor.selecting_condition_weapon)
		draw_weapon_picker(env);
}
