/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:28:57 by marvin            #+#    #+#             */
/*   Updated: 2020/05/21 16:45:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "init.h"
#include "collision.h"
#include "parser.h"

void		refresh_env(t_env *env)
{
	int	i;

	i = 0;
	precompute_slopes(env);
	update_player_z(env);
	ft_bzero(&env->inputs, sizeof(env->inputs));
	i = 0;
	while (i < env->nb_objects)
	{
		env->objects[i].exists = 1;
		i++;
	}
	free_camera(&env->player.camera);
}

int			stop_game(void *param)
{
	((t_env*)param)->running = 0;
	return (0);
}
