/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sector_tab_button.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:40:42 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 11:39:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_sector_general_buttons2(t_env *env)
{
	env->editor.hud.g_sector.floor_slope = new_hud_button(ON_RELEASE,
	&change_floor_slope, &env->editor.hud.g_sector.t_floor_slope, env);
	env->editor.hud.g_sector.t_floor_slope.pos = new_point(170, 720);
	env->editor.hud.g_sector.floor_slope.pos = new_point(170, 720);
	env->editor.hud.g_sector.ceiling_slope = new_hud_button(ON_RELEASE,
	&change_ceiling_slope, &env->editor.hud.g_sector.t_ceiling_slope, env);
	env->editor.hud.g_sector.ceiling_slope.pos = new_point(170, 760);
	env->editor.hud.g_sector.t_ceiling_slope.pos = new_point(170, 760);
	env->editor.hud.g_sector.gravity = new_hud_button(ON_RELEASE,
	&change_gravity, &env->editor.hud.g_sector.t_gravity, env);
	env->editor.hud.g_sector.gravity.pos = new_point(170, 800);
	env->editor.hud.g_sector.t_gravity.pos = new_point(170, 800);
}

void	init_sector_general_buttons(t_env *env)
{
	env->editor.hud.g_sector.brightness = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.g_sector.t_brightness, env);
	env->editor.hud.g_sector.brightness.pos = new_point(170, 520);
	env->editor.hud.g_sector.t_brightness.pos = new_point(170, 520);
	env->editor.hud.g_sector.color = new_hud_button(ON_RELEASE,
	&change_color, &env->editor.hud.g_sector.t_color, env);
	env->editor.hud.g_sector.color.pos = new_point(170, 560);
	env->editor.hud.g_sector.t_color.pos = new_point(170, 560);
	env->editor.hud.g_sector.intensity = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.g_sector.t_intensity, env);
	env->editor.hud.g_sector.intensity.pos = new_point(170, 600);
	env->editor.hud.g_sector.t_intensity.pos = new_point(170, 600);
	env->editor.hud.g_sector.ceiling = new_hud_button(ON_RELEASE,
	&change_ceiling_height, &env->editor.hud.g_sector.t_ceiling, env);
	env->editor.hud.g_sector.ceiling.pos = new_point(170, 680);
	env->editor.hud.g_sector.t_ceiling.pos = new_point(170, 680);
	env->editor.hud.g_sector.floor = new_hud_button(ON_RELEASE,
	&change_floor_height, &env->editor.hud.g_sector.t_floor, env);
	env->editor.hud.g_sector.floor.pos = new_point(170, 640);
	env->editor.hud.g_sector.t_floor.pos = new_point(170, 640);
	init_sector_general_buttons2(env);
}
