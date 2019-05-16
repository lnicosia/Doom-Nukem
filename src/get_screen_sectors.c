/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_sectors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:08:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/16 18:19:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		get_screen_sectors(t_env *env)
{
	int		size;
	//t_v2	curr;
	int		x;

	size = ft_min(env->nb_sectors, env->w);
	x = 0;
	while (x < env->w)
	{
		//ft_printf("x = %d = %f\n", x, 2 * x / (env->camera.x2 - env->camera.x1) / env->camera.scale + env->camera.x1);
		x++;
	}
	env->xmin[0] = ft_max(env->w / 2 + env->camera.x1 * env->camera.scale, 0);
	env->xmax[0] = ft_min(env->w / 2 + env->camera.x2 * env->camera.scale, env->w - 1);
	env->screen_sectors[0] = env->player.sector;
	return (1);
}
