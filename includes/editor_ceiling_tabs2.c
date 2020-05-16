/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_ceiling_tabs2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:42:20 by marvin            #+#    #+#             */
/*   Updated: 2020/05/16 14:49:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int	print_ceiling_sector_tab3(t_env *env)
{
    ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].gravity),
	env->sectors[env->selected_ceiling].gravity);
	env->editor.hud.s_ceiling.t_gravity.target =
	&env->sectors[env->selected_ceiling].gravity;
	if (draw_button(env, env->editor.hud.s_ceiling.gravity, env->snprintf))
		return (-1);
    return (0);
}

int	print_ceiling_sector_tab2(t_env *env)
{
    ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
	env->sectors[env->selected_ceiling].light_color);
	env->editor.hud.s_ceiling.t_color.target =
	&env->sectors[env->selected_ceiling].light_color;
	if (draw_button(env, env->editor.hud.s_ceiling.color, env->snprintf))
		return (-1);
	if (print_text(new_point(600, 60), new_printable_text("Intensity",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->selected_ceiling].intensity);
	env->editor.hud.s_ceiling.t_intensity.target =
	&env->sectors[env->selected_ceiling].intensity;
	if (draw_button(env, env->editor.hud.s_ceiling.intensity, env->snprintf))
		return (-1);
	if (print_text(new_point(640, 60), new_printable_text("Gravity",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	return (print_ceiling_sector_tab2(env));
}

int	print_ceiling_sector_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d",
	env->selected_ceiling);
	if (TTF_SizeText(env->sdl.fonts.lato_black30,
		env->snprintf, &size.x, &size.y))
		return (-1);
	if (print_text(new_point(465, 200 - size.x / 2),
		new_printable_text(env->snprintf,
		env->sdl.fonts.lato_black30, 0x333333FF, 30), env))
		return (-1);
	if (print_text(new_point(520, 60), new_printable_text("Brightness",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->selected_ceiling].brightness);
	env->editor.hud.s_ceiling.t_brightness.target =
	&env->sectors[env->selected_ceiling].brightness;
	if (draw_button(env, env->editor.hud.s_ceiling.brightness, env->snprintf))
		return (-1);
	if (print_text(new_point(560, 60), new_printable_text("Light_color",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	return (print_ceiling_sector_tab2(env));
}