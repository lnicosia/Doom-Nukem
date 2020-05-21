/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemies_hp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:46:11 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:46:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	set_enemies_hp(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].exists)
			env->enemies[i].health = env->enemies[i].map_hp * env->difficulty;
		i++;
	}
}
