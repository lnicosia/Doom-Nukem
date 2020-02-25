/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_keyup_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:23:49 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/25 11:35:03 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	change_ceiling_floor_height_keyup(t_env *env)
{
	t_sector	*sector;

	sector = NULL;
	if (env->editor.keyup_allowed)
	{
		if (env->selected_ceiling != -1)
		{
			sector = &env->sectors[env->selected_ceiling];
			if (env->sdl.event.key.keysym.sym == SDLK_KP_PLUS
			&& !env->inputs.ctrl)
				env->sectors[env->selected_ceiling].ceiling += 0.1;
			if (env->sdl.event.key.keysym.sym == SDLK_KP_MINUS
			&& !env->inputs.ctrl)
				env->sectors[env->selected_ceiling].ceiling -= 0.1;
			check_height_protections(env, sector);
			update_sector_slope(env, sector);
		}
		else if (env->selected_floor != -1)
		{
			sector = &env->sectors[env->selected_floor];
			if (env->sdl.event.key.keysym.sym == SDLK_KP_PLUS && !env->inputs.ctrl)
				env->sectors[env->selected_floor].floor += 0.1;
			else if (env->sdl.event.key.keysym.sym == SDLK_KP_MINUS && !env->inputs.ctrl)
				env->sectors[env->selected_floor].floor -= 0.1;	
			check_height_protections(env, sector);
			update_sector_slope(env, sector);
		}
	}
}