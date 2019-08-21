/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:00:29 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/21 12:34:59 by lnicosia         ###   ########.fr       */
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
	int			j;

	j = 0;
	i = 0;
	if (!(tmp = (t_object*)malloc(sizeof(t_object) * env->nb_objects)))
		return (ft_printf("Deleting: failed copying objects\n"));
	env->flag = 0;
	tmp = env->objects;
	env->objects = ft_delindex(env->objects,
								env->nb_objects * sizeof(t_object),
								sizeof(t_object),
								env->editor.selected_object * sizeof(t_object));
	env->nb_objects--;
	env->editor.selected_object = -1;
	return (0);
}
