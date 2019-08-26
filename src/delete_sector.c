/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:56:17 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/26 11:39:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	delete_sector(t_env *env)
{
	env->sectors = ft_delindex(env->sectors,
			 env->nb_sectors * sizeof(t_sector),
			 sizeof(t_sector),
			 env->editor.selected_vertex * sizeof(t_sector));
	env->nb_sectors--;
}
