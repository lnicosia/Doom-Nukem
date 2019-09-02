/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:39:31 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/30 15:23:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	delete_object(t_env *env, int object)
{
	env->objects = ft_delindex(env->objects,
			sizeof(t_object) * env->nb_objects,
			sizeof(t_object),
			sizeof(t_object) * object);
	env->nb_objects--;
	env->editor.selected_object = -1;
	return (0);
}
