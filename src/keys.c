/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/08 10:40:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		keys(t_env *env)
{
	double	time;
	int		i;

	i = 0;
	time = SDL_GetTicks();
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right)
		Mix_PlayChannel(-1, env->sound.footstep, 0);
	if ((((env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right || env->inputs.space || env->jump.on_going == 1
			|| env->crouch.on_going || env->inputs.ctrl)
			&& env->player.health > 0

			&&  (((env->selected_enemy == -1 && env->editor.tab)
				|| (env->selected_enemy != -1 && !env->editor.tab))
				|| (env->selected_enemy == -1 && !env->editor.tab)))
		|| (env->player.state.climb || env->player.state.drop)))
		move_player(env);
	if (env->inputs.plus && !env->inputs.shift
			&& env->options.minimap_scale * 1.2 < 100)
		env->options.minimap_scale *= 1.2;
	if (env->inputs.minus && !env->inputs.shift
			&& env->options.minimap_scale / 1.2 > 1)
		env->options.minimap_scale /= 1.2;
	if (env->confirmation_box.state)
		confirmation_box_keys(&env->confirmation_box, env);
}
