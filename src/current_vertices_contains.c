/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_vertices_contains.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:25:21 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/21 15:28:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		current_vertices_contains(t_env *env, int index)
{
	t_list		*tmp;
	t_vertex	*v;

	tmp = env->editor.current_vertices;
	while (tmp)
	{
		v = (t_vertex*)tmp->content;
		if (v->num == index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
