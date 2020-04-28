/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:26:07 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/26 14:13:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	wall_sprites_keys3(t_env *env, t_v2 *scale)
{
	if (env->inputs.minus1 && check_texture_scale(env, scale))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			scale->x /= 1.1;
			scale->y /= 1.1;
		}
		else if (env->inputs.ctrl)
			scale->y /= 1.1;
		else
			scale->x /= 1.1;
	}
}

void	wall_sprites_keys2(t_env *env, t_v2 *pos, t_v2 *scale)
{
	if (env->inputs.period && check_sprite_pos(pos))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			pos->x++;
			pos->y++;
		}
	else if (env->inputs.ctrl)
		pos->y++;
	else
		pos->x++;
	}
	if (env->inputs.equals && check_texture_scale(env, scale))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			scale->x *= 1.1;
			scale->y *= 1.1;
		}
		else if (env->inputs.ctrl)
			scale->y *= 1.1;
		else
			scale->x *= 1.1;
	}
	wall_sprites_keys3(env, scale);
}

void	wall_sprites_keys(t_env *env, t_v2 *pos, t_v2 *scale)
{
  	if (env->editor.key_delay <= INPUT_DELAY)
	  	return ;
	if (env->inputs.comma && check_sprite_pos(pos))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			pos->y--;
			pos->x--;
		}
		else if (env->inputs.ctrl)
			pos->y--;
		else
			pos->x--;
	}
	wall_sprites_keys2(env, pos, scale);
}
