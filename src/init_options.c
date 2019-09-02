/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:16:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/02 17:42:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_options(t_env *env)
{
	ft_printf("Initializing options..\n");
	env->options.contouring = 0;
	env->options.render_sectors = 1;
	env->options.lighting = 0;
	env->options.show_minimap = 1;
	env->options.wall_lover = 0;
	env->options.show_fps = 1;
	env->options.color_clipping = 0;
	env->options.wall_color = 1;
	env->options.test = 0;
	env->options.minimap_scale = 10;
	env->options.clipping = 1;
	env->option = 0;
	env->options.show_ennemies = 1;
	env->options.zbuffer = 0;
}
