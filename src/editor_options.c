/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 13:37:17 by marvin            #+#    #+#             */
/*   Updated: 2020/05/18 11:23:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "env.h"

int		editor_options4(t_env *env, t_point size)
{
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
	return (editor_options5(env));
}

int		editor_options3(t_env *env, t_point size)
{
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
	if (draw_button(env, env->editor.change_mode, env->editor.change_mode.str))
		return (-1);
	if (draw_button(env, env->editor.launch_game, env->editor.launch_game.str))
		return (-1);
	if (draw_button(env, env->editor.options, env->editor.options.str))
		return (-1);
	if (draw_button(env, env->editor.save, env->editor.save.str))
		return (-1);
	return (editor_options4(env, size));
}

int		editor_options2(t_env *env, t_point center, t_point size)
{
	if (TTF_SizeText(env->sdl.fonts.lato15,
	env->sound.musics[env->sound.fight_music].music_name, &center.x, &center.y))
		return (-1);
	if (print_text(new_point(367, 105 - center.x / 2), new_printable_text(
		env->sound.musics[env->sound.fight_music].music_name,
		env->sdl.fonts.lato15, 0x00000000, 15), env))
		return (-1);
	draw_rectangle(env, new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(210, 40), new_point(170, 360));
	apply_surface(env->ui_textures[24].surface, new_point(296, 230),
	new_point(128, 89), env);
	apply_surface(env->ui_textures[24].surface, new_point(196, 230),
	new_point(128, 89), env);
	if (draw_button(env, env->editor.add_enemy, env->editor.add_enemy.str))
		return (-1);
	if (draw_button(env, env->editor.add_object, env->editor.add_object.str))
		return (-1);
	if (draw_button(env, env->editor.current_texture_selection,
		env->editor.current_texture_selection.str))
		return (-1);
	return (editor_options3(env, size));
}

int		editor_options1(t_env *env, t_point center, t_point size)
{
	draw_rectangle(env, new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 40), new_point(170, 225));
	draw_rectangle(env, new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 290), new_point(170, 110));
	if (TTF_SizeText(env->sdl.fonts.lato_bold15,
		"Ambiance", &center.x, &center.y))
		return (-1);
	if (print_text(new_point(300, 105 - center.x / 2),
	new_printable_text("Ambiance", env->sdl.fonts.lato_bold15,
	0x00000000, 15), env))
		return (-1);
	if (TTF_SizeText(env->sdl.fonts.lato15,
	env->sound.musics[env->sound.ambient_music].music_name, &center.x,
	&center.y))
		return (custom_error("TTF_SizeText error: %s\n", TTF_GetError()));
	if (print_text(new_point(322, 105 - center.x / 2), new_printable_text(
	env->sound.musics[env->sound.ambient_music].music_name,
	env->sdl.fonts.lato15, 0x00000000, 15), env))
		return (-1);
	if (TTF_SizeText(env->sdl.fonts.lato_bold15, "fight", &center.x, &center.y))
		return (-1);
	if (print_text(new_point(345, 90), new_printable_text("Fight",
	env->sdl.fonts.lato_bold15, 0x00000000, 15), env))
		return (-1);
	return (editor_options2(env, center, size));
}
