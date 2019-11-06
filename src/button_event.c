/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:28:16 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/06 18:48:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	button_mouseup(t_button *b, t_env *env)
{
	b->anim_state = REST;
	if (env->sdl.mx < b->pos.x || env->sdl.mx > b->pos.x + b->size.x
		|| env->sdl.my < b->pos.y || env->sdl.my > b->pos.y + b->size.y)
		return ;
	b->state = b->state == UP ? DOWN : UP;
	if (b->state == DOWN)
	{
		if (b->down_action)
			b->down_action(NULL);
	}
}

void	button_event(t_button *b, t_env *env)
{
	if (env->sdl.mx < b->pos.x || env->sdl.mx > b->pos.x + b->size.x
		|| env->sdl.my < b->pos.y || env->sdl.my > b->pos.y + b->size.y)
	{
		b->anim_state = REST;
		return ;
	}
	if (env->inputs.left_click)
	{
		b->anim_state = PRESSED;
		if (b->press_action)
			b->press_action(NULL);
	}
	else if (b->state == UP)
		b->anim_state = HOVER;
}
