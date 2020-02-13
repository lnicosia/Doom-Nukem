/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_texture_wall_align_functions.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:57:35 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/13 12:21:15 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	left_wall_texture_alignement(t_env *env)
{
	if (env->inputs.shift && !env->inputs.ctrl
	&& env->sectors[env->editor.selected_sector].
	align[env->editor.selected_wall].y  > -1000
	&& env->sectors[env->editor.selected_sector].
	align[env->editor.selected_wall].x  > -1000)
	{
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].y -= 1;
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].x -= 1;
	}
	else if (env->inputs.ctrl
	&& env->sectors[env->editor.selected_sector].
	align[env->editor.selected_wall].y > -1000)
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].y -= 1;
	else if (env->sectors[env->editor.selected_sector].
	align[env->editor.selected_wall].x > -1000 )
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].x -= 1;
}

void	right_wall_texture_alignement(t_env *env)
{
	if (env->inputs.shift && !env->inputs.ctrl)
	{
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].y += 1;
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].x += 1;
	}
	else if (env->inputs.ctrl)
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].y += 1;
	else
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].x += 1;
}