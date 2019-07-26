/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:26:04 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/26 10:03:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_editor(t_env *env)
{
	env->editor.menu = 0;
	env->editor.select_mode = 0;
	env->editor.center.x = env->h_w;
	env->editor.center.y = env->h_h;
	env->editor.scale = 20;
	env->editor.vertices = NULL;
	env->editor.current_vertices = NULL;
	env->editor.sectors = NULL;
	env->editor.vertices_count = 0;
	env->editor.sectors_count = 0;
	env->editor.current_sector_start = 0;
	env->editor.new_sector = 0;
}
