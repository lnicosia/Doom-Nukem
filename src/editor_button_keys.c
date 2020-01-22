/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_button_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:55:32 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/22 10:58:48 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	sector_buttons(t_env *env)
{
	if (env->editor.general_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.g_sector.brightness, env);
		button_keys(&env->editor.hud.g_sector.color, env);
		button_keys(&env->editor.hud.g_sector.intensity, env);
		button_keys(&env->editor.hud.g_sector.floor, env);
		button_keys(&env->editor.hud.g_sector.ceiling, env);
		button_keys(&env->editor.hud.g_sector.floor_slope, env);
		button_keys(&env->editor.hud.g_sector.ceiling_slope, env);
	}
}