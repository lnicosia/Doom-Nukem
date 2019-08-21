/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:00:29 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/20 18:01:52 by lnicosia         ###   ########.fr       */
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
	//if (!env->editor.drag_object && !env->inputs.left_click
			//&& env->sdl.mx <= 200 && env->flag)
	//{
		env->flag = 0;
		tmp = env->objects;
		env->objects = ft_delindex(env->objects,
									env->nb_objects * sizeof(t_object),
									sizeof(t_object),
									env->editor.select_object * sizeof(t_object));
		env->nb_objects--;
		if (!env->nb_objects && env->editor.objects == 1)
			env->editor.objects = 0;
		env->editor.select_object = -1;
	//}
	return (0);
}
