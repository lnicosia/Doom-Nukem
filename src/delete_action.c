/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:44:43 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/13 15:44:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		delete_selected_sector(void *param)
{
	t_env	*env;
	int	i;

	env = (t_env *)param;
	delete_sector(env, env->editor.selected_sector);
	delete_invalid_sectors(env);
	delete_invalid_vertices(env);
	env->editor.selected_sector = -1;
	clear_portals(env);
	i = 0;
	while (i < env->nb_sectors)
	{
		create_portals(env, env->sectors[i]);
		i++;
	}
	env->player.sector = get_sector_global(env, env->player.pos);
}

int		delete_action(t_env *env)
{
	int	i;

	if (env->editor.selected_vertex != -1
			&& !current_vertices_contains(env, env->editor.selected_vertex))
	{
		i = 0;
		delete_vertex(env, env->editor.selected_vertex);
		delete_invalid_sectors(env);
		delete_invalid_vertices(env);
		env->editor.selected_vertex = -1;
		clear_portals(env);
		while (i < env->nb_sectors)
		{
			create_portals(env, env->sectors[i]);
			i++;
		}
	}
	if (env->editor.selected_sector != -1 && !env->confirmation_box.state)
	{
		if (update_confirmation_box(&env->confirmation_box,
			"Delete the selected sector?", YESNO, env))
			return (-1);
		env->confirmation_box.yes_action = &delete_selected_sector;
		env->confirmation_box.yes_target = env;
	}
	if (env->selected_object != -1)
	{
		delete_object(env, env->selected_object);
		env->selected_object = -1;
	}
	env->inputs.del = 0;
	return (0);
}
