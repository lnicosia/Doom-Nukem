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

int		editor_options_sprites_portals(t_env *env)
{
	if (print_text(new_point(565, 50), new_printable_text("Sprites",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select%*s", 55, "left-click");
	if (print_text(new_point(590, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Scale %*s", 57,
		"ctrl shift +/-");
	if (print_text(new_point(610, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Pos   %*s", 58,
		"ctrl shift </>");
	if (print_text(new_point(630, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	if (print_text(new_point(670, 50), new_printable_text("Portals",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select %*s", 57,
		"ctrl left-click");
	if (print_text(new_point(695, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	return (0);
}

int		editor_options_bindings_1(t_env *env)
{
	if (print_text(new_point(735, 50), new_printable_text("Bindings",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Light%*s", 19, "ctrl + L");
	if (print_text(new_point(760, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Zbuffer%*s", 16, "ctrl + Z");
	if (print_text(new_point(760, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Fly %*s", 21, "F");
	if (print_text(new_point(780, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Fly up%*s", 18, "space");
	if (print_text(new_point(780, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Fly down%*s", 11, "cmd");
	if (print_text(new_point(800, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "2D/3D%*s", 12, "Enter");
	if (print_text(new_point(800, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	return (0);
}

int		editor_options_bindings_2(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Game%*s", 18, "ctrl + G");
	if (print_text(new_point(820, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Options%*s", 11, "ctrl + O");
	if (print_text(new_point(820, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Help%*s", 18, "ctrl + H");
	if (print_text(new_point(840, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Minimap%*s", 12, "ctrl + M");
	if (print_text(new_point(840, 230), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	return (0);
}

int		editor_options_hud(t_env *env)
{
	editor_options_rectangles(env);
	if (editor_options_buttons(env))
		return (-1);
	if (editor_options_ceil_floor(env))
		return (-1);
	if (editor_options_textures(env))
		return (-1);
	if (editor_options_sprites_portals(env))
		return (-1);
	if (editor_options_bindings_1(env))
		return (-1);
	if (editor_options_bindings_2(env))
		return (-1);
	return (0);
}
