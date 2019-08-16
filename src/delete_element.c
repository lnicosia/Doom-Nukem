/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:00:29 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/16 15:24:29 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	delete_vertex()
{

}

int	delete_object(t_env *env)
{
	t_object	*tmp;
	int			i;

	i = 0;
	if (!(tmp = (t_object*)malloc(sizeof(t_object) * env->nb_objects)))
		return (ft_printf("Deleting: failed copying objects\n"));
	if (env->editor.drag_object && !env->inputs.left_click
		&& env->sdl.mx <= 200)
	{
		tmp = env->objects;
		if (!(env->objects = (t_object*)ft_realloc(env->objects, sizeof(t_object) * env->nb_objects, sizeof(t_object) * (env->nb_objects - 1))))
		{
			env->objects = tmp;
			return (ft_printf("failed tu reduce the number of objects"));
		}
		env->objects--;
		while (i < env->nb_objects)
		{
			if (i == env->editor.select_object)
				i++;
			else
			{
				env->objects[i] = tmp[i];
				i++;
			}
		}
	}
	return (0);
}
