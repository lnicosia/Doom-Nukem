/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_floor_tabs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:31:40 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/15 11:48:13 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	printf_floor_sprite_tab(t_env *env)
{
	(void)env;
}

void	print_floor_sector_tab(t_env *env)
{
	print_text(new_point(520, 60), new_printable_text("Sector:",
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 280), new_printable_text(ft_sitoa(env->selected_floor),
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(480, 60), new_printable_text("Sector:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(480, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].num),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].brightness),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 60), new_printable_text("Light_color:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].light_color),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 60), new_printable_text("Intensity:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].intensity),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	print_floor_general_tab(t_env *env)
{
	print_text(new_point(520, 80), new_printable_text("Height: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 80), new_printable_text("Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor_slope), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 60), new_printable_text("Texture: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor_texture), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 60), new_printable_text("Scale X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor_scale->x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(680, 60), new_printable_text("Scale Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(680, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor_scale->y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(720, 60), new_printable_text("Align X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(720, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor_align->x ), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(760, 60), new_printable_text("Align Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(760, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor_align->y ), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}