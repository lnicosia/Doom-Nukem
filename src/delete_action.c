/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:41:33 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/03 15:00:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		delete_action(t_env *env)
{
	if (env->editor.selected_vertex != -1
			&& !current_vertices_contains(env, env->editor.selected_vertex))
	{
		delete_vertex(env, env->editor.selected_vertex);
		delete_invalid_sectors(env);
		delete_invalid_vertices(env);
		env->editor.selected_vertex = -1;
	}
	if (env->editor.selected_sector != -1)
	{
		if (!env->confirmation_box.state)
		{
			env->confirmation_box.state = 1;
			if (!(env->confirmation_box.str = ft_strdup("Delete the selected sector?")))
				return (ft_perror("Could not malloc confirmation box str"));
			new_confirmation_box(&env->confirmation_box, env);
		}
	}
	if (env->editor.selected_object != -1)
	{
		delete_object(env, env->editor.selected_object);
		env->editor.selected_object = -1;
	}
	if (env->editor.selected_player != -1)
	{
		env->editor.new_player = 0;
		env->editor.selected_player = -1;
	}
	env->inputs.del = 0;
	return (0);
}
