/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:26:04 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/29 16:38:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_editor(t_env *env)
{
	env->editor.in_game = 0;
	env->editor.select_mode = 0;
	env->editor.center.x = env->h_w;
	env->editor.center.y = env->h_h;
	env->editor.scale = 20;
	env->editor.current_vertices = NULL;
	env->editor.new_sector = 0;
	env->editor.reverted = 0;
	env->nb_vertices = 0;
	env->nb_sectors = 0;
	env->nb_objects = 0;
}
