/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:44:43 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/06 17:19:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "update_existing_events.h"

/*
**	Returns if a sector contains a given vertex index
*/

int		sector_contains_vertex(t_sector sector, int vertex)
{
	int		i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		if (sector.vertices[i] == vertex)
			return (1);
		i++;
	}
	return (0);
}

/*
**	Finds every vertex that is gonna be invalid after the given sector
**	will be deleted. Then checks if any existing event is linked to them
*/

int		find_future_invalid_vertices_existing_events(t_env *env,
t_sector sector)
{
	int				i;
	t_event_target	target;

	i = 0;
	init_target(&target);
	while (i < sector.nb_vertices)
	{
		if (!is_vertex_going_to_be_used(env, sector.num, sector.vertices[i]))
		{
			target.type = VERTEX_DELETED;
			target.vertex = i;
			if (update_sector_existing_events(env, target))
				return (-1);
		}
		i++;
	}
	return (0);
}

/*
**	Finds every sector that is gonna be invalid after the given vertex
**	will be deleted. Then checks if any existing event is linked to them
*/

int		find_future_invalid_sectors_existing_events(t_env *env, int vertex)
{
	int				i;
	t_event_target	target;

	i = 0;
	init_target(&target);
	while (i < env->nb_sectors)
	{
		if (env->sectors[i].nb_vertices < 4
			&& sector_contains_vertex(env->sectors[i], vertex))
		{
			target.type = SECTOR_DELETED;
			target.sector = i;
			if (update_sector_existing_events(env, target))
				return (-1);
			if (find_future_invalid_vertices_existing_events(env,
				env->sectors[i]))
				return (-1);
		}
		i++;
	}
	return (0);
}

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
	init_target(&target);
	target.sector = env->editor.selected_sector;
	target.type = SECTOR_DELETED;
	//if (update_sector_existing_events(env, target))
		//return (-1);
	//if (find_future_invalid_vertices_existing_events(env,
		//env->sectors[env->editor.selected_sector]))
		//return (-1);
	env->confirmation_box.yes_action = &delete_sector;
	env->confirmation_box.yes_target = env;
	env->confirmation_box.no_action = &delete_events_to_delete_list;
	env->confirmation_box.no_target = env;
	if (env->confirmation_box.state)
		return (0);
	if (delete_sector(env))
		return (-1);
	return (0);
}

int		delete_selected_vertex(t_env *env)
{
	int				i;
	t_event_target	target;

	init_target(&target);
	target.vertex = env->editor.selected_vertex;
	target.type = VERTEX_DELETED;
	i = 0;
	//if (update_sector_existing_events(env, target))
		//return (-1);
	//if (find_future_invalid_sectors_existing_events(env,
		//env->editor.selected_vertex))
		//return (-1);
	env->confirmation_box.yes_action = &delete_vertex;
	env->confirmation_box.yes_target = env;
	env->confirmation_box.no_action = &delete_events_to_delete_list;
	env->confirmation_box.no_target = env;
	if (env->confirmation_box.state)
		return (0);
	if (delete_vertex(env))
		return (-1);
	return (0);
}

int		delete_action(t_env *env)
{
	if (env->selected_object != -1)
	{
		if (delete_object(env))
			return (-1);
		env->selected_object = -1;
	}
	else if (env->selected_enemy != -1)
	{
		if (delete_enemy(env))
			return (-1);
		env->selected_enemy = -1;
	}
	else if (env->selected_wall_sprite_wall != -1)
	{
		if (delete_wall_sprite(env))
			return (-1);
	}
	else if (env->selected_floor_sprite != -1)
	{
		if (delete_floor_sprite(env))
			return (-1);
	}
	else if (env->editor.selected_vertex != -1
			&& !current_vertices_contains(env, env->editor.selected_vertex))
	{
		if (delete_selected_vertex(env))
			return (-1);
	}
	else if (env->editor.selected_sector != -1 && !env->confirmation_box.state)
	{
		if (update_confirmation_box(&env->confirmation_box,
			"Delete the selected sector?", YESNO, env))
			return (-1);
		env->confirmation_box.yes_action = &delete_selected_sector;
		env->confirmation_box.yes_target = env;
	}
	env->inputs.del = 0;
	return (0);
}
