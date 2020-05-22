/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 11:53:28 by marvin            #+#    #+#             */
/*   Updated: 2020/05/22 12:14:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemies.h"
#include "collision.h"

/*
** Tests a random direction to free the enemy if he's stuck
*/

t_v3	random_move(t_env *env, int nb, t_motion motion, t_v3 move)
{
	env->enemies[nb].dir = rand_dir(env, nb);
	move.x = (env->enemies[nb].dir) ? move.y : -move.y;
	move.y = (env->enemies[nb].dir) ? -move.x : move.x;
	move = check_collision(env, move, motion);
	return (move);
}
