/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 20:26:34 by marvin            #+#    #+#             */
/*   Updated: 2020/05/21 20:28:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "collision.h"
#include "parser.h"
#include <math.h>

int		init_game6(t_env *env)
{
	env->fixed_camera.angle_z_cos = cos(env->fixed_camera.angle_z);
	env->fixed_camera.angle_z_sin = sin(env->fixed_camera.angle_z);
	update_camera_position(&env->fixed_camera);
	env->confirmation_box.font = env->sdl.fonts.lato20;
	env->player.highest_sect = find_highest_sector(env,
		new_motion(env->player.sector, env->player.size_2d,
		env->player.eyesight, env->player.pos));
	start_game_button(env);
	if (next_difficulty_button(env))
		return (crash("Could not init next difficulty menu button\n", env));
	if (prev_difficulty_button(env))
		return (crash("Could not init previous difficulty menu button\n", env));
	option_menu_ig_button(env);
	return_button(env);
	exit_button(env);
	music_vol_down_button(env);
	music_vol_up_button(env);
	sounds_vol_up_button(env);
	sounds_vol_down_button(env);
	fps_option_button(env);
	fov_increase_button(env);
	fov_decrease_button(env);
	next_resolution_button(env);
	prev_resolution_button(env);
	return (doom(env));
}
