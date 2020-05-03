/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:49:58 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:49:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_lost_soul(int i, t_env *env)
{
	env->enemies[i].height_ratio = 2;
	env->enemies[i].width_ratio = 0.5;
	env->enemies[i].main_sprite = LOST_SOUL;
	env->enemies[i].type = AERIAL;
	env->enemies[i].behavior = MELEE_KAMIKAZE;
	env->enemies[i].size_2d = env->enemies[i].scale
		* env->enemies[i].width_ratio;
	env->enemies[i].eyesight = env->enemies[i].size_2d
		* env->enemies[i].height_ratio;
	env->enemies[i].nb_rest_state = 2;
	env->enemies[i].nb_pursuit_state = 2;
	env->enemies[i].nb_firing_state = 0;
	env->enemies[i].height_on_floor = 5;
}

void	init_cyber_demon(int i, t_env *env)
{
	env->enemies[i].height_ratio = 2.5;
	env->enemies[i].width_ratio = 0.375;
	env->enemies[i].main_sprite = CYBER_DEMON;
	env->enemies[i].firing_sprite = 10;
	env->enemies[i].type = TERRESTRIAL;
	env->enemies[i].behavior = RANGED_PROJECTILE;
	env->enemies[i].size_2d = env->enemies[i].scale
		* env->enemies[i].width_ratio;
	env->enemies[i].eyesight = env->enemies[i].size_2d
		* env->enemies[i].height_ratio;
	env->enemies[i].nb_rest_state = 4;
	env->enemies[i].nb_pursuit_state = 4;
	env->enemies[i].nb_firing_state = 3;
	env->enemies[i].height_on_floor = 0;
}

void	init_enemies_data(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_enemies)
	{
		env->enemies[i].hit = 0;
		env->enemies[i].state = 0;
		env->enemies[i].shot = 0;
		env->enemies[i].exists = 1;
		env->enemies[i].saw_player = 0;
		if (env->enemies[i].sprite >= 0 && env->enemies[i].sprite < 5)
			init_lost_soul(i, env);
		else if (env->enemies[i].sprite >= 5 && env->enemies[i].sprite < 13)
			init_cyber_demon(i, env);
		env->enemies[i].seen = 0;
		env->enemies[i].dir = 0;
		env->enemies[i].sector = get_sector_no_z(env, env->enemies[i].pos);
		env->enemies[i].last_player_pos = env->enemies[i].pos;
		i++;
	}
}
