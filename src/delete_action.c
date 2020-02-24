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
#include "update_existing_events.h"

/*
**	Called if the user confirms the delete
**	Checks if any event or condition had a link with the sector
**	If so, raise a confirmation box asking the user again
**	if he still wants to delete
**	If not, no confirmation box is raised and the sector is deleted
*/

int		delete_selected_sector(void *param)
{
	t_env			*env;
	t_event_target	target;

	env = (t_env *)param;
	ft_bzero(&target, sizeof(target));
	target.sector = env->editor.selected_sector;
	target.type = SECTOR_DELETED;
	if (update_sector_existing_events(env, target))
		return (-1);
	if (env->confirmation_box.state)
		return (0);
	if (delete_sector(env))
		return (-1);
	return (0);
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
