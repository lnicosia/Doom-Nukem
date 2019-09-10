/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:46:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 11:11:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		project_walls(int i, t_sector *sector, t_env *env)
{
	sector->scale[i] = env->camera.scale / -sector->vz[i];
	sector->f[i] = env->h_h + (sector->clipped_vf[i]);
}
