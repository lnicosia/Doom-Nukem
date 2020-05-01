/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:34:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 14:48:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int	delete_enemy(void *param)
{
	t_env	*env;
	int		enemy;

	env = (t_env*)param;
	enemy = env->selected_enemy;
	free_events(env->enemies[enemy].collision_events,
	env->enemies[enemy].nb_collision_events);
	free_events(env->enemies[enemy].death_events,
	env->enemies[enemy].nb_death_events);
	env->enemies = (t_enemy*)ft_delindex(env->enemies,
			sizeof(t_enemy) * env->nb_enemies,
			sizeof(t_enemy),
			sizeof(t_enemy) * enemy);
	env->nb_enemies--;
	if (env->nb_enemies > 0 && !env->enemies)
		return (-1);
	env->selected_enemy = -1;
	return (0);
}
