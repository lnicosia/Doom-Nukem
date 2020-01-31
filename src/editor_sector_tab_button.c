/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sector_tab_button.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:40:42 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/31 17:25:27 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_sector_general_buttons(t_env *env)
{
	env->editor.hud.g_sector.brightness = new_hud_button(ON_RELEASE, &change_var,
	&env->editor.hud.g_sector.t_brightness, env);
	env->editor.hud.g_sector.brightness.pos = new_point(250, 520);
	env->editor.hud.g_sector.t_brightness.pos = new_point(250, 520);
	env->editor.hud.g_sector.color = new_hud_button(ON_RELEASE, &change_var,
	&env->editor.hud.g_sector.t_color, env);
	env->editor.hud.g_sector.color.pos = new_point(250, 560);
	env->editor.hud.g_sector.t_color.pos = new_point(250, 560);
	env->editor.hud.g_sector.intensity = new_hud_button(ON_RELEASE, &change_var,
	&env->editor.hud.g_sector.t_intensity, env);
	env->editor.hud.g_sector.intensity.pos = new_point(250, 600);
	env->editor.hud.g_sector.t_intensity.pos = new_point(250, 600);
	env->editor.hud.g_sector.ceiling = new_hud_button(ON_RELEASE, &change_var,
	&env->editor.hud.g_sector.t_ceilling, env);
	env->editor.hud.g_sector.ceiling.pos = new_point(250, 680);
	env->editor.hud.g_sector.t_ceilling.pos = new_point(250, 680);
	env->editor.hud.g_sector.floor = new_hud_button(ON_RELEASE, &change_var,
	&env->editor.hud.g_sector.t_floor, env);
	env->editor.hud.g_sector.floor.pos = new_point(250, 640);
	env->editor.hud.g_sector.t_floor.pos = new_point(250, 640);
	env->editor.hud.g_sector.floor_slope = new_hud_button(ON_RELEASE, &change_var,
	&env->editor.hud.g_sector.t_floor_slope, env);
	env->editor.hud.g_sector.t_floor_slope.pos = new_point(250, 720);
	env->editor.hud.g_sector.floor_slope.pos = new_point(250, 720);
	env->editor.hud.g_sector.ceiling_slope = new_hud_button(ON_RELEASE, &change_var,
	&env->editor.hud.g_sector.t_ceiling_slope, env);
	env->editor.hud.g_sector.ceiling_slope.pos = new_point(250, 760);
	env->editor.hud.g_sector.t_ceiling_slope.pos = new_point(250, 760);
}