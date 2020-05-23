/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_updaters5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:53:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:53:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			is_player_on_floor(t_env *env)
{
	if (env->player.pos.z == get_floor_at_pos(&env->sectors[env->player.sector],
		env->player.pos, env))
		return (1);
	return (0);
}

int			update_vertex_event(t_event *event, void *penv)
{
	t_env	*env;
	int		i;
	int		player_is_on_floor;
	int		j;

	env = (t_env*)penv;
	i = -1;
	player_is_on_floor = is_player_on_floor(env);
	while (++i < env->nb_sectors)
	{
		j = -1;
		while (++j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] != event->update_param.vertex)
				continue ;
			update_sector_slope(env, &env->sectors[i]);
			if (env->player.sector == i && player_is_on_floor)
			{
				update_player_pos(env);
				env->player.pos.z = get_floor_at_pos(&env->
				sectors[env->player.sector], env->player.pos, env);
				update_player_pos(env);
			}
			break ;
		}
	}
	return (0);
}
