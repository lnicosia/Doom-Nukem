/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_selected_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:38:26 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:38:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	go_to_next_wall(t_env *env)
{
	if (env->editor.selected_wall < env->sectors[env->editor.
		selected_sector].nb_vertices - 1)
	{
		env->editor.selected_wall++;
		env->selected_wall1 =
		env->vertices[env->sectors[env->editor.selected_sector].
		vertices[env->editor.selected_wall]].num;
		env->selected_wall2 =
		env->vertices[env->sectors[env->editor.selected_sector].
		vertices[env->editor.selected_wall + 1]].num;
	}
	else
	{
		env->editor.selected_wall = 0;
		env->selected_wall1 =
		env->vertices[env->sectors[env->editor.selected_sector].
		vertices[0]].num;
		env->selected_wall2 =
		env->vertices[env->sectors[env->editor.selected_sector].
		vertices[1]].num;
	}
}

void	go_to_previous_wall(t_env *env)
{
	if (env->editor.selected_wall > 0)
	{
		env->editor.selected_wall--;
		env->selected_wall1 =
		env->vertices[env->sectors[env->editor.selected_sector].
		vertices[env->editor.selected_wall]].num;
		env->selected_wall2 =
		env->vertices[env->sectors[env->editor.selected_sector].
		vertices[env->editor.selected_wall + 1]].num;
	}
	else
	{
		env->editor.selected_wall =
		env->sectors[env->editor.selected_sector].nb_vertices - 1;
		env->selected_wall1 =
		env->vertices[env->sectors[env->editor.selected_sector].
		vertices[env->sectors[env->editor.selected_sector].
		nb_vertices - 1]].num;
		env->selected_wall2 =
		env->vertices[env->sectors[env->editor.selected_sector].
		vertices[env->sectors[env->editor.selected_sector].nb_vertices]].num;
	}
}

int		next_selected_wall(void *target)
{
	t_env			*env;
	t_button_next	*button;

	env = (t_env *)target;
	button = NULL;
	if (env->editor.next_wall.state == DOWN)
		button = &env->editor.next_wall_env;
	else if (env->editor.previous_wall.state == DOWN)
		button = &env->editor.previous_wall_env;
	if (button->button_type == NEXT)
	{
		go_to_next_wall(env);
	}
	else if (button->button_type == PREVIOUS)
	{
		go_to_previous_wall(env);
	}
	env->editor.next_wall.state = UP;
	env->editor.next_wall.anim_state = REST;
	env->editor.previous_wall.state = UP;
	env->editor.previous_wall.anim_state = REST;
	return (0);
}
