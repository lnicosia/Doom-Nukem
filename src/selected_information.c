/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selected_information.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:41:35 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/10 17:29:22 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	selected_information_on_enemy(t_env *env)
{
	double	time;

	time = SDL_GetTicks();
	if (env->selected_stat == 0 && time - env->time.tick2 > 300)
	{
		env->time.tick2 = time;
		if (env->inputs.left && env->enemies[env->selected_enemy].health > 5)
			env->enemies[env->selected_enemy].health -= 5;
		if (env->inputs.right && env->enemies[env->selected_enemy].health < 100)
			env->enemies[env->selected_enemy].health += 5;
	}
	else if (env->selected_stat == 1 && time - env->time.tick2 > 300)
	{
		env->time.tick2 = time;
		if (env->inputs.left && env->enemies[env->selected_enemy].speed > 5)
			env->enemies[env->selected_enemy].speed -= 5;
		if (env->inputs.right && env->enemies[env->selected_enemy].speed < 100)
			env->enemies[env->selected_enemy].speed += 5;
	}
	else if (env->selected_stat == 2 && time - env->time.tick2 > 300)
	{
		env->time.tick2 = time;
		if (env->inputs.left && env->enemies[env->selected_enemy].damage > 5)
			env->enemies[env->selected_enemy].damage -= 5;
		if (env->inputs.right && env->enemies[env->selected_enemy].damage < 100)
			env->enemies[env->selected_enemy].damage += 5;
	}
	else if (env->selected_stat == 3 && time - env->time.tick2 > 300)
	{
		env->time.tick2 = time;
		if (env->inputs.left && env->enemies[env->selected_enemy].sprite == 2)
		{
			env->enemies[env->selected_enemy].sprite--;
			env->enemies[env->selected_enemy].pos.z = get_floor_at_pos(env->sectors[env->enemies[env->selected_enemy].sector], new_v2(env->enemies[env->selected_enemy].pos.x, env->enemies[env->selected_enemy].pos.y), env) + 5;
		}
		if (env->inputs.right && env->enemies[env->selected_enemy].sprite == 1)
		{
			env->enemies[env->selected_enemy].sprite++;
			env->enemies[env->selected_enemy].pos.z = get_floor_at_pos(env->sectors[env->enemies[env->selected_enemy].sector], new_v2(env->enemies[env->selected_enemy].pos.x, env->enemies[env->selected_enemy].pos.y), env);
		}
	}
}

void	selected_information_in_sector(t_env *env)
{
	if (env->selected_stat == 0)
	{

	}
	if (env->selected_stat == 1)
	{

	}
	if (env->selected_stat == 2)
	{

	}
}
