/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:01:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/03 15:08:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		init_screen_pos(t_env *env)
{
	env->screen_sectors_size = ft_min(env->nb_sectors, env->w);
	if (!(env->xmin = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
		return (ft_printf("Could not malloc xmins!\n", env));
	if (!(env->xmax = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
		return (ft_printf("Could not malloc xmaxs!\n", env));
	if (!(env->screen_sectors = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
		return (ft_printf("Could not malloc screen sectors!\n", env));
	if (!(env->screen_pos = (t_v2*)malloc(sizeof(t_v2) * (env->w))))
		return (ft_printf("Could not malloc screen pos!\n", env));
	if (!(env->rendered_sectors = (short*)malloc(sizeof(short) * (env->screen_sectors_size))))
		return (ft_printf("Could not malloc rendered sectors!\n", env));
	return (0);
}
