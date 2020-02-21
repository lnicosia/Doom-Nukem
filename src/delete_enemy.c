/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:34:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 10:34:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	delete_enemy(t_env *env, int enemy)
{
	env->enemies = ft_delindex(env->enemies,
			sizeof(t_enemy) * env->nb_enemies,
			sizeof(t_enemy),
			sizeof(t_enemy) * enemy);
	env->nb_enemies--;
	env->selected_enemy = -1;
	return (0);
}
