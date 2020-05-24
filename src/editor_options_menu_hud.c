/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_options_menu_hud.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:17:39 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/12 17:19:30 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	editor_options_ceil_floor(t_env *env)
{
	print_text(new_point(315, 50), new_printable_text("Ceiling/Floor",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Height%*s", 53, "+/-");
	print_text(new_point(340, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Slope %*s", 56, "ctrl +/-");
	print_text(new_point(360, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Start slope%*s", 45,
		"ctrl shift <-/->");
	print_text(new_point(380, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_textures(t_env *env)
{
	print_text(new_point(420, 50), new_printable_text("Textures",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Add texture%*s", 41, "T");
	print_text(new_point(445, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Scale %*s", 57,
		"ctrl shift +/-");
	print_text(new_point(465, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Align %*s", 57,
		"ctrl shift </>");
	print_text(new_point(485, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_sprites_portals(t_env *env)
{
	print_text(new_point(525, 50), new_printable_text("Sprites",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Scale %*s", 57,
		"ctrl shift +/-");
	print_text(new_point(550, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Pos   %*s", 58,
		"ctrl shift </>");
	print_text(new_point(570, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	print_text(new_point(610, 50), new_printable_text("Portals",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select %*s", 57,
		"ctrl left-click");
	print_text(new_point(635, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_bindings_1(t_env *env)
{
	print_text(new_point(675, 50), new_printable_text("Bindings",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Light%*s", 19, "ctrl + L");
	print_text(new_point(702, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Zbuffer%*s", 16, "ctrl + Z");
	print_text(new_point(702, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Fly %*s", 21, "F");
	print_text(new_point(724, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Fly up%*s", 18, "space");
	print_text(new_point(724, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Fly down%*s", 11, "cmd");
	print_text(new_point(746, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "2D/3D%*s", 12, "Enter");
	print_text(new_point(746, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Game%*s", 19, "ctrl + G");
	print_text(new_point(768, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_bindings_2(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Options%*s", 11, "ctrl + O");
	print_text(new_point(768, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Help%*s", 18, "ctrl + H");
	print_text(new_point(790, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Minimap%*s", 12, "ctrl + M");
	print_text(new_point(790, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector%*s", 14, "Spacebar");
	print_text(new_point(812, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Vertex%*s", 18,
		"ctrl + click");
	print_text(new_point(812, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Return%*s", 13, "Backspace");
	print_text(new_point(834, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Delete%*s", 15, "Del");
	print_text(new_point(834, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Save%*s", 18, "ctrl + S");
	print_text(new_point(856, 70), new_printable_text(env->snprintf,
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