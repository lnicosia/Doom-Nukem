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
	env->player.highest_sect = find_highest_sector(env,
		new_motion(env->player.sector, env->player.size_2d,
		env->player.eyesight, env->player.pos));
	start_game_button(env);
	next_difficulty_button(env);
	prev_difficulty_button(env);
	option_menu_ig_button(env);
	return_button(env);
	exit_button(env);
	music_vol_down_button(env);
	music_vol_up_button(env);
	sounds_vol_up_button(env);
	sounds_vol_down_button(env);
	return (doom(env));
}
