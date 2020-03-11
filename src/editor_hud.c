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

void	print_on_off(t_env *env, int bool, t_point p)
{
	if (bool)
		print_text(p, new_printable_text("ON", env->sdl.fonts.lato20,
			0x009246FF, 20), env);
	else
		print_text(p, new_printable_text("OFF", env->sdl.fonts.lato20,
			0xCC0000FF, 20), env);
}

void	editor_options_rectangles(t_env *env)
{
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 40), new_point(360, 230));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 310), new_point(360, 112));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 435), new_point(360, 112));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 560), new_point(360, 92));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 665), new_point(360, 52));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 730), new_point(360, 150));
}

void	editor_options_buttons(t_env *env)
{
	draw_button(env, env->editor.quit_options,
		env->editor.quit_options.str);
	print_text(new_point(5, 155), new_printable_text("OPTIONS",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env);
	print_text(new_point(275, 167), new_printable_text("HELP",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env);
	draw_button(env, env->editor.mipmapping,
		env->editor.mipmapping.str);
	draw_button(env, env->editor.zbuffer, env->editor.zbuffer.str);
	draw_button(env, env->editor.light, env->editor.light.str);
	draw_button(env, env->editor.fps, env->editor.fps.str);
	print_on_off(env, env->options.mipmapping, new_point(64, 265));
	print_on_off(env, env->options.zbuffer, new_point(114, 265));
	print_on_off(env, env->options.lighting, new_point(164, 265));
	print_on_off(env, env->options.show_fps, new_point(214, 265));
}

void	editor_options_ceil_floor(t_env *env)
{
	print_text(new_point(315, 50), new_printable_text("Ceiling/Floor",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select%*s", 55, "left-click");
	print_text(new_point(340, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Height%*s", 53, "+/-");
	print_text(new_point(360, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Slope %*s", 56, "ctrl +/-");
	print_text(new_point(380, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Start slope%*s", 45,
		"ctrl shift <-/->");
	print_text(new_point(400, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_textures(t_env *env)
{
	print_text(new_point(440, 50), new_printable_text("Textures",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select%*s", 55, "left-click");
	print_text(new_point(465, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Add texture%*s", 41, "T");
	print_text(new_point(485, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Scale %*s", 57,
		"ctrl shift +/-");
	print_text(new_point(505, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Align %*s", 57,
		"ctrl shift </>");
	print_text(new_point(525, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_sprites_portals(t_env *env)
{
	print_text(new_point(565, 50), new_printable_text("Sprites",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select%*s", 55, "left-click");
	print_text(new_point(590, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Scale %*s", 57,
		"ctrl shift +/-");
	print_text(new_point(610, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Pos   %*s", 58,
		"ctrl shift </>");
	print_text(new_point(630, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	print_text(new_point(670, 50), new_printable_text("Portals",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select %*s", 57,
		"ctrl left-click");
	print_text(new_point(695, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_bindings_1(t_env *env)
{
	print_text(new_point(735, 50), new_printable_text("Bindings",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Light%*s", 19, "ctrl + L");
	print_text(new_point(760, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Zbuffer%*s", 16, "ctrl + Z");
	print_text(new_point(760, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Fly %*s", 21, "F");
	print_text(new_point(780, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Fly up%*s", 18, "space");
	print_text(new_point(780, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Fly down%*s", 11, "cmd");
	print_text(new_point(800, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "2D/3D%*s", 12, "Enter");
	print_text(new_point(800, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_bindings_2(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Game%*s", 18, "ctrl + G");
	print_text(new_point(820, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Options%*s", 11, "ctrl + O");
	print_text(new_point(820, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Help%*s", 18, "ctrl + H");
	print_text(new_point(840, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Minimap%*s", 12, "ctrl + M");
	print_text(new_point(840, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_hud(t_env *env)
{
	editor_options_rectangles(env);
	editor_options_buttons(env);
	editor_options_ceil_floor(env);
	editor_options_textures(env);
	editor_options_sprites_portals(env);
	editor_options_bindings_1(env);
	editor_options_bindings_2(env);
}

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
		if (!env->options.editor_options)
		{
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
		else
			editor_options_hud(env);
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
