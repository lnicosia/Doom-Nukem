/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_env_wall_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:46:44 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/15 17:53:58 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_wall_general_env(t_env *env)
{
	env->editor.hud.g_wall.t_texture.env = env;
	env->editor.hud.g_wall.t_texture.type = DOUBLE;
	env->editor.hud.g_wall.t_texture.target = &env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall];
}