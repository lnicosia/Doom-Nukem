/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:26:04 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/25 17:12:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_edit(t_env *env)
{
	env->edit.menu = 0;
	env->edit.select_mode = 0;
	env->edit.nb_vertex =  0;
	env->edit.center.x = env->h_w;
	env->edit.center.y = env->h_h;
	env->edit.scale = 20;
	env->edit.vertices = NULL;
	env->edit.current_vertices = NULL;
	env->edit.sectors = NULL;
	env->edit.vertex_count = 0;
	env->edit.current_sector_start = 0;
	env->edit.sector_done = 1;
}
