/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_wall_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:26:37 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 18:48:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_wall_general_tab4(t_env *env)
{
	if (env->sectors[env->editor.selected_sector].
	neighbors[env->editor.selected_wall] != -1)
	{
		print_text(new_point(720, 60), new_printable_text("Portal",
		env->sdl.fonts.lato20, 0x00000000, 30), env);
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
		env->sectors[env->editor.selected_sector].
		portals[env->editor.selected_wall]);
		env->editor.hud.g_wall.t_portal.target =
		&env->sectors[env->editor.selected_sector].
		portals[env->editor.selected_wall];
		draw_button(env, env->editor.hud.g_wall.portal, env->snprintf);
	}
	draw_button(env, env->editor.hud.g_wall.add_sprite,
	env->editor.hud.g_wall.add_sprite.str);
	return (0);
}

int		print_wall_general_tab3(t_env *env)
{
	env->editor.hud.g_wall.t_texture_align_x.target =
	&env->sectors[env->editor.selected_sector].
	align[env->editor.selected_wall].x;
	draw_button(env, env->editor.hud.g_wall.texture_align_x, env->snprintf);
	print_text(new_point(680, 60), new_printable_text("Align Y",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.
	selected_sector].align[env->editor.selected_wall].y),
	env->sectors[env->editor.
	selected_sector].align[env->editor.selected_wall].y);
	env->editor.hud.g_wall.t_texture_align_y.target =
	&env->sectors[env->editor.selected_sector].
	align[env->editor.selected_wall].y;
	draw_button(env, env->editor.hud.g_wall.texture_align_y, env->snprintf);
	return (print_wall_general_tab4(env));
}

int		print_wall_general_tab2(t_env *env)
{
	env->editor.hud.g_wall.t_texture_scale_x.target =
	&env->sectors[env->editor.selected_sector].
	scale[env->editor.selected_wall].x;
	draw_button(env, env->editor.hud.g_wall.texture_scale_x, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Scale Y",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.
	selected_sector].scale[env->editor.selected_wall].y),
	env->sectors[env->editor.
	selected_sector].scale[env->editor.selected_wall].y);
	env->editor.hud.g_wall.t_texture_scale_y.target =
	&env->sectors[env->editor.selected_sector].
	scale[env->editor.selected_wall].y;
	draw_button(env, env->editor.hud.g_wall.texture_scale_y, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("Align X",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.
	selected_sector].align[env->editor.selected_wall].x),
	env->sectors[env->editor.
	selected_sector].align[env->editor.selected_wall].x);
	return (print_wall_general_tab3(env));
}

int		print_wall_general_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d",
	env->editor.selected_sector);
	TTF_SizeText(env->sdl.fonts.lato_black30, env->snprintf, &size.x, &size.y);
	print_text(new_point(465, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato_black30, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Wall %d",
	env->editor.selected_wall);
	TTF_SizeText(env->sdl.fonts.lato20, env->snprintf, &size.x, &size.y);
	print_text(new_point(510, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	draw_button(env, env->editor.next_wall, env->editor.next_wall.str);
	draw_button(env, env->editor.previous_wall, env->editor.previous_wall.str);
	print_text(new_point(560, 60), new_printable_text("Scale X",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.
	selected_sector].scale[env->editor.selected_wall].x),
	env->sectors[env->editor.
	selected_sector].scale[env->editor.selected_wall].x);
	return (print_wall_general_tab2(env));
}
