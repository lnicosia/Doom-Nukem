/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:16:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/15 10:44:26 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_options(t_env *env)
{
	ft_printf("Initializing options..\n");
	env->options.contouring = 1;
	env->options.render_sectors = 1;
	env->options.lighting = 0;
	env->options.show_minimap = 1;
	env->options.wall_lover = 0;
	env->options.show_fps = 1;
	env->options.color_clipping = 1;
	env->options.wall_color = 0;
	env->options.test = 1;
	env->options.minimap_scale = 20;
	env->options.render_type = 0;
	env->options.clipping = 1;
}
