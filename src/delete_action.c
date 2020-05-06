/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:44:43 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/29 15:52:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "update_existing_events.h"

int		delete_action2(t_env *env)
{
	if (env->editor.selected_vertex != -1
			&& !current_vertices_contains(env, env->editor.selected_vertex))
	{
		if (update_confirmation_box(&env->confirmation_box,
			"Delete the selected vertex?", YESNO, env))
			return (-1);
		env->confirmation_box.yes_action = &delete_selected_vertex;
		env->confirmation_box.yes_target = env;
	}
	else if (env->editor.selected_sector != -1 && !env->confirmation_box.state)
	{
		if (update_confirmation_box(&env->confirmation_box,
			"Delete the selected sector?", YESNO, env))
			return (-1);
		env->confirmation_box.yes_action = &delete_selected_sector;
		env->confirmation_box.yes_target = env;
	}
	else if (env->selected_ceiling_sprite != -1)
	{
		if (delete_ceiling_sprite(env))
			return (-1);
	}
	env->inputs.del = 0;
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
	else
		return (delete_action2(env));
	return (0);
}
