/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keyup5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 11:33:31 by marvin            #+#    #+#             */
/*   Updated: 2020/05/22 11:33:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		space_pressed(t_env *env)
{
	int	clicked_vertex;
	int	ret;

	env->inputs.space = 0;
	if (!vertex_creation_possible(env))
		return (1);
	clicked_vertex = get_existing_vertex(env);
	if (clicked_vertex == -1)
	{
		if ((ret = new_vertex(env, clicked_vertex)) != 1)
			return (ret);
	}
	else if (clicked_vertex >= 0)
	{
		if ((ret = existing_vertex(env, clicked_vertex)) != 1)
			return (ret);
	}
	return (1);
}
