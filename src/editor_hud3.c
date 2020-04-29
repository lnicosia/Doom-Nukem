/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:07:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:07:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
