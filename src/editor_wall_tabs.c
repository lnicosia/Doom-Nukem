/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_wall_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:07:20 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/15 13:41:14 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_wall_sprite_tab(t_env *env)
{
	(void)env;
}

void	print_wall_sector_tab(t_env *env)
{
	print_text(new_point(500, 60), new_printable_text("Wall:",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(500, 230), new_printable_text(ft_sitoa(env->editor.selected_wall),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(540, 60), new_printable_text("Sector:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(540, 230), new_printable_text(ft_sitoa(env->editor.selected_sector),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(580, 60), new_printable_text("Brightness:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(580, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].brightness),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(620, 60), new_printable_text("Light_color:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(620, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].light_color),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(660, 60), new_printable_text("Intensity:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(660, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].intensity),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	print_wall_general_tab(t_env *env)
{
	print_text(new_point(500, 60), new_printable_text("Texture:",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(500, 230), new_printable_text(ft_sitoa(
	env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(540, 60), new_printable_text("Scale X:",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(540, 230), new_printable_text(ft_sitoa(
	env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(580, 60), new_printable_text("Scale Y:",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(580, 230), new_printable_text(ft_sitoa(
	env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(620, 60), new_printable_text("Align X:",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(620, 230), new_printable_text(ft_sitoa(
	env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(660, 60), new_printable_text("Align Y:",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(660, 230), new_printable_text(ft_sitoa(
	env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}