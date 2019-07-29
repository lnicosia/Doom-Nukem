/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/29 18:26:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		editor_render(t_env *env)
{
	if (env->inputs.enter)
	{
		env->editor.in_game = 0;
		env->inputs.enter = 0;
		SDL_SetRelativeMouseMode(0);
		ft_memdel((void**)&env->xmin);
		ft_memdel((void**)&env->xmax);
		ft_memdel((void**)&env->screen_sectors);
		ft_memdel((void**)&env->screen_pos);
		ft_memdel((void**)&env->rendered_sectors);
		return (0);
	}
	reset_clipped(env);
	keys(env);
	if (draw_walls(env))
		return (crash("Failed to draw walls\n", env));
	if (env->options.show_fps)
		fps(env);
	game_time(env);
	view(env);
	return (0);
}
