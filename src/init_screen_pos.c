/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:01:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/30 11:25:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_screen_pos(t_env *env)
{
	env->screen_sectors_size = ft_min(env->nb_sectors, env->w);
	if (!(env->xmin = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
		return (ft_printf("Could not malloc xmins!\n", env));
	if (!(env->xmax = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
		return (ft_printf("Could not malloc xmaxs!\n", env));
	if (!(env->screen_sectors = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
		return (ft_printf("Could not malloc screen sectors!\n", env));
	if (!(env->rendered_sectors = (short*)malloc(sizeof(short) * (env->screen_sectors_size))))
		return (ft_printf("Could not malloc rendered sectors!\n", env));
	return (0);
}
