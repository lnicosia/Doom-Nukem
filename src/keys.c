/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/31 18:37:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		keys(t_env *env)
{
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right)
		play_sound(env, &env->sound.footstep_chan, env->sound.footstep,
			env->sound.ambient_vol);
	if (env->inputs.right_click)
	{
		FMOD_Channel_SetPaused(env->sound.music_chan, 1);
		FMOD_System_PlaySound(env->sound.system, env->sound.mt_erebus, 0, 0, &env->sound.music_chan);
		FMOD_Channel_SetVolume(env->sound.music_chan, env->sound.music_vol);
		FMOD_Channel_SetPaused(env->sound.music_chan, 0);
	}
	if ((((env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right || env->inputs.space || env->jump.on_going == 1
			|| env->crouch.on_going || env->inputs.ctrl)
			&& env->player.health > 0

			&&  (((env->selected_enemy == -1 && env->editor.tab)
				|| (env->selected_enemy != -1 && !env->editor.tab))
				|| (env->selected_enemy == -1 && !env->editor.tab)))
		|| (env->player.state.climb || env->player.state.drop)))
		move_player(env);
	if (env->inputs.plus && !env->inputs.shift
			&& env->options.minimap_scale * 1.2 < 100)
		env->options.minimap_scale *= 1.2;
	if (env->inputs.minus && !env->inputs.shift
			&& env->options.minimap_scale / 1.2 > 1)
		env->options.minimap_scale /= 1.2;
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keys(&env->confirmation_box, env))
			return (-1);
	}
	if (env->inputs.e
		&& env->hovered_wall_sprite_sprite != -1
		&& env->hovered_wall_sprite_wall != -1
		&& env->hovered_wall_sprite_sector != -1)
	{
		env->press_wall_sprite_color = 0xFFFFFFFF;
		env->press_wall_sprite_intensity = 128;
	}
	else
	{
		env->press_wall_sprite_color = 0xFFFFFFFF;
		env->press_wall_sprite_intensity = 64;
	}
	return (0);
}
