/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_button_keyup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:59:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/22 11:05:07 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	sector_buttons_up(t_env *env)
{
	if (env->editor.general_tab.state == DOWN)
	{
		button_keyup(&env->editor.hud.g_sector.brightness, env);
		button_keyup(&env->editor.hud.g_sector.color, env);
		button_keyup(&env->editor.hud.g_sector.intensity, env);
		button_keyup(&env->editor.hud.g_sector.floor, env);
		button_keyup(&env->editor.hud.g_sector.ceiling, env);
		button_keyup(&env->editor.hud.g_sector.floor_slope, env);
		button_keyup(&env->editor.hud.g_sector.ceiling_slope, env);
	}
}