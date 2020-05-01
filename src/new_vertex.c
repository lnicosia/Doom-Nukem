/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:36:14 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:36:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int		new_vertex(t_env *env, int clicked_vertex)
{
	int	ret;

	ret = is_new_vertex_valid(env, clicked_vertex);
	if (ret == -1)
		return (-1);
	else if (!ret)
		return (0);
	if (add_vertex(env))
		return (ft_printf("Could not add new vertex\n"));
	if (add_vertex_to_current_sector(env, env->nb_vertices - 1))
		return (-1);
	if (env->editor.start_vertex == -1)
		env->editor.start_vertex = env->nb_vertices - 1;
	return (1);
}

int		vertex_creation_possible(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_SPACE
		&& env->editor.event_panel_dragged == -1
		&& env->editor.dragged_player == -1
		&& env->editor.dragged_start_player == -1
		&& env->editor.dragged_object == -1
		&& env->editor.dragged_vertex == -1
		&& !env->editor.in_game
		&& env->sdl.mx > 400)
		return (1);
	return (0);
}

int		new_sector(t_env *env, int clicked_vertex)
{
	int	ret;

	ret = is_new_vertex_valid(env, clicked_vertex);
	if (ret == -1)
		return (-1);
	else if (!ret)
		return (0);
	env->editor.reverted = get_clockwise_order(env) ? 0 : 1;
	env->editor.start_vertex = -1;
	if (add_sector(env))
		return (0);
	free_current_vertices(env);
	return (1);
}

int		new_vertex_in_current_sector(t_env *env, int clicked_vertex)
{
	int	ret;

	if (clicked_vertex == ((t_vertex*)env->editor.current_vertices->content)->
		num && ft_lstlen(env->editor.current_vertices) > 2)
	{
		if ((ret = new_sector(env, clicked_vertex)))
			return (ret);
	}
	else
	{
		ret = is_new_vertex_valid(env, clicked_vertex);
		if (ret == -1)
			return (-1);
		else if (!ret)
			return (0);
		if (add_vertex_to_current_sector(env, clicked_vertex))
			return (-1);
	}
	if (ft_lstlen(env->editor.current_vertices) == 2 && check_pos_vertices(env))
	{
		env->editor.split_sector = 1;
		if (split_sector(env))
			return (-1);
	}
	return (1);
}

int		existing_vertex(t_env *env, int clicked_vertex)
{
	int	ret;

	if (env->editor.start_vertex == -1)
	{
		env->editor.start_vertex = clicked_vertex;
		if (add_vertex_to_current_sector(env, clicked_vertex))
			return (-1);
	}
	else
	{
		if ((ret = new_vertex_in_current_sector(env, clicked_vertex)))
			return (ret);
	}
	return (1);
}
