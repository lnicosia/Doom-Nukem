/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:10:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 12:10:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		damage_done(t_env *env, double rotated_pos_z)
{
	if (env->weapons[env->player.curr_weapon].splash)
		return ((int)(env->weapons[env->player.curr_weapon].damage
		/ (rotated_pos_z / 4 + 1)));
	else
		return (env->weapons[env->player.curr_weapon].damage);
}

int		hitscan_enemies(t_env *env, int i)
{
	if (!(env->enemies[i].exists && env->enemies[i].seen))
		return (-1);
	if ((env->enemies[i].left - env->enemies[i].left) * (env->h / 2
		- env->enemies[i].bottom) - (env->w / 2 - env->enemies[i].left)
		* (env->enemies[i].top - env->enemies[i].bottom) < 0)
		return (0);
	if ((env->enemies[i].right - env->enemies[i].left)
		* (env->h / 2 - env->enemies[i].top)
		- (env->w / 2 - env->enemies[i].left)
		* (env->enemies[i].top - env->enemies[i].top) < 0)
		return (0);
	if ((env->enemies[i].right - env->enemies[i].right)
		* (env->h / 2 - env->enemies[i].top)
		- (env->w / 2 - env->enemies[i].right)
		* (env->enemies[i].bottom - env->enemies[i].top) < 0)
		return (0);
	if ((env->enemies[i].left - env->enemies[i].right)
		* (env->h / 2 - env->enemies[i].bottom)
		- (env->w / 2 - env->enemies[i].right)
		* (env->enemies[i].bottom - env->enemies[i].bottom) < 0)
		return (0);
	if (env->enemies[i].rotated_pos.z > env->weapons[env->player.curr_weapon].
		range || env->enemies[i].rotated_pos.z < 0)
		return (0);
	return (1);
}

int		hitscan_objects(t_env *env, int i)
{
	if (!(env->objects[i].exists && env->objects[i].seen))
		return (-1);
	if ((env->objects[i].left - env->objects[i].left) * (env->h / 2
		- env->objects[i].bottom) - (env->w / 2 - env->objects[i].left)
		* (env->objects[i].top - env->objects[i].bottom) < 0)
		return (0);
	if ((env->objects[i].right - env->objects[i].left)
		* (env->h / 2 - env->objects[i].top)
		- (env->w / 2 - env->objects[i].left)
		* (env->objects[i].top - env->objects[i].top) < 0)
		return (0);
	if ((env->objects[i].right - env->objects[i].right)
		* (env->h / 2 - env->objects[i].top)
		- (env->w / 2 - env->objects[i].right)
		* (env->objects[i].bottom - env->objects[i].top) < 0)
		return (0);
	if ((env->objects[i].left - env->objects[i].right)
		* (env->h / 2 - env->objects[i].bottom)
		- (env->w / 2 - env->objects[i].right)
		* (env->objects[i].bottom - env->objects[i].bottom) < 0)
		return (0);
	if (env->objects[i].rotated_pos.z > env->weapons[env->player.curr_weapon].
		range || env->objects[i].rotated_pos.z < 0)
		return (0);
	return (1);
}
