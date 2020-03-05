/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/05 12:11:24 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		keys(t_env *env)
{
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right)
		play_sound(env, &env->sound.footstep_chan, env->sound.footstep,
			env->sound.ambient_vol);
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
	if (env->inputs.nb1)
	{
		env->player.next_weapon = 0;
		if (env->player.next_weapon != env->player.curr_weapon &&
			env->weapons[env->player.next_weapon].possessed)
			weapon_change(env);
		else
			env->player.next_weapon = env->player.curr_weapon;
	}
	else if (env->inputs.nb2)
	{
		env->player.next_weapon = 1;
		if (env->player.next_weapon != env->player.curr_weapon &&
			env->weapons[env->player.next_weapon].possessed)
			weapon_change(env);
		else
			env->player.next_weapon = env->player.curr_weapon;
	}
	else if (env->inputs.nb3)
	{
		env->player.next_weapon = 2;
		if (env->player.next_weapon != env->player.curr_weapon &&
			env->weapons[env->player.next_weapon].possessed)
			weapon_change(env);
		else
			env->player.next_weapon = env->player.curr_weapon;
	}
	return (0);
}
