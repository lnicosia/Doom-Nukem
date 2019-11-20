/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:26:07 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/19 11:31:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	wall_sprites_keys(t_env *env)
{
	if (env->inputs.comma)
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].y--;
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].x--;
		}
		else if (env->inputs.ctrl)
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].y--;
		else
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].x--;
	}
	if (env->inputs.period)
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].x++;
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].y++;
		}
		else if (env->inputs.ctrl)
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].y++;
		else
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].x++;
	}
	if (env->inputs.equals)
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].x *= 1.1;
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].y *= 1.1;
		}
		else if (env->inputs.ctrl)
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].y *= 1.1;
		else
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].x *= 1.1;
	}
	if (env->inputs.minus1)
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].x /= 1.1;
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].y /= 1.1;
		}
		else if (env->inputs.ctrl)
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].y /= 1.1;
		else
			env->sectors[env->editor.selected_sector].sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].x /= 1.1;
	}
}
