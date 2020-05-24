/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:06:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/14 19:44:05 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_options(t_env *env)
{
	ft_printf("Initializing options..\n");
	env->options.render_sectors = 1;
	env->options.lighting = 1;
	env->options.show_minimap = 1;
	env->options.show_fps = 1;
	env->options.minimap_scale = 2.5;
	env->option = 0;
	env->options.zbuffer = 0;
	env->options.mipmapping = 1;
	env->minimap_size = new_point(300, 300);
	env->minimap_pos = new_point(env->w - env->minimap_size.x / 2 - 20,
	env->minimap_size.y / 2 + 20);
	env->crosshair_pos = new_point(env->h_w, env->h_h);
	env->options.max_floor_sprites = 5;
	env->options.max_wall_sprites = 30;
	env->options.editor_options = 0;
}
