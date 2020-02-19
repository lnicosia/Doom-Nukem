/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_env_sector_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 08:54:19 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/19 09:34:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_sector_general_env(t_env *env)
{
	env->editor.hud.g_sector.t_ceilling.env = env;
	env->editor.hud.g_sector.t_ceilling.pos = new_point(0, 0);
	env->editor.hud.g_sector.t_ceilling.type = DOUBLE;
	env->editor.hud.g_sector.t_floor.env = env;
	env->editor.hud.g_sector.t_floor.pos = new_point(0, 0);
	env->editor.hud.g_sector.t_floor.type = DOUBLE;
	env->editor.hud.g_sector.t_floor_slope.env = env;
	env->editor.hud.g_sector.t_floor_slope.pos = new_point(0, 0);
	env->editor.hud.g_sector.t_floor_slope.type = DOUBLE;
	env->editor.hud.g_sector.t_ceiling_slope.env = env;
	env->editor.hud.g_sector.t_ceiling_slope.pos = new_point(0, 0);
	env->editor.hud.g_sector.t_ceiling_slope.type = DOUBLE;
	env->editor.hud.g_sector.t_brightness.env = env;
	env->editor.hud.g_sector.t_brightness.pos = new_point(0, 0);
	env->editor.hud.g_sector.t_brightness.type = INT;
	env->editor.hud.g_sector.t_color.env = env;
	env->editor.hud.g_sector.t_color.pos = new_point(0, 0);
	env->editor.hud.g_sector.t_color.type = UINT32;
	env->editor.hud.g_sector.t_intensity.env = env;
	env->editor.hud.g_sector.t_intensity.pos = new_point(0, 0);
	env->editor.hud.g_sector.t_intensity.type = INT;
	env->editor.hud.g_sector.t_gravity.env = env;
	env->editor.hud.g_sector.t_gravity.pos = new_point(0, 0);
	env->editor.hud.g_sector.t_gravity.type = DOUBLE;
}
