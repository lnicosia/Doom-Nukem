/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:28:16 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/07 10:49:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_point	get_button_current_size(t_button b)
{
	t_point	size;

	size = new_point(0, 0);
	if (b.anim_state == HOVER)
		size = b.size_hover;
	else if (b.anim_state == PRESSED)
		size = b.size_pressed;
	else if (b.state == UP)
		size = b.size_up;
	else if (b.state == DOWN)
		size = b.size_down;
	return (size);
}

int	is_mouse_on_button(t_button b, t_point mouse)
{
	t_point	size;

	size = get_button_current_size(b);
	if (mouse.x < b.pos.x || mouse.x > b.pos.x + size.x
		|| mouse.y < b.pos.y || mouse.y > b.pos.y + size.y)
		return (0);
	return (1);
}

void	button_mouseup(t_button *b, t_env *env)
{
	b->anim_state = REST;
	/*if (env->sdl.mx < b->pos.x || env->sdl.mx > b->pos.x + b->size.x
		|| env->sdl.my < b->pos.y || env->sdl.my > b->pos.y + b->size.y)
		return ;*/
	if (!is_mouse_on_button(*b, new_point(env->sdl.mx, env->sdl.my)))
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
	/*if (env->sdl.mx < b->pos.x || env->sdl.mx > b->pos.x + b->size.x
		|| env->sdl.my < b->pos.y || env->sdl.my > b->pos.y + b->size.y)*/
	if (!is_mouse_on_button(*b, new_point(env->sdl.mx, env->sdl.my)))
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
