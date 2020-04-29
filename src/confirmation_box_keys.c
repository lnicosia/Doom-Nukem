/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirmation_box_keys.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:20:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:20:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		confirmation_box_keyup2(t_confirmation_box *box, t_env *env)
{
	if (env->sdl.event.type == SDL_MOUSEBUTTONUP
		&& env->sdl.event.button.button == SDL_BUTTON_LEFT)
	{
		if (box->yes.anim_state != PRESSED && button_keyup(&box->no, env))
			return (-1);
		if (box->no.anim_state != PRESSED && button_keyup(&box->yes, env))
			return (-1);
	}
	return (0);
}

int		confirmation_box_keyup(t_confirmation_box *box, t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN
		&& !env->editor.enter_locked
		&& box->yes.anim_state == PRESSED
		&& box->no.anim_state != PRESSED)
	{
		box->state = 0;
		env->editor.enter_locked = 1;
		if (box->yes_action)
		{
			if (box->yes_action(box->yes_target))
				return (-1);
		}
	}
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE
		&& box->type == YESNO
		&& box->yes.anim_state != PRESSED)
	{
		if (box->no_action)
		{
			if (box->no_action(box->no_target))
				return (-1);
		}
		box->state = 0;
	}
	return (confirmation_box_keyup2(box, env));
}

int		confirmation_box_keys(t_confirmation_box *box, t_env *env)
{
	if (box->yes.anim_state != PRESSED
		&& box->type == YESNO
		&& button_keys(&box->no, env))
		return (-1);
	if (box->no.anim_state != PRESSED && button_keys(&box->yes, env))
		return (-1);
	if (env->inputs.enter
		&& box->no.anim_state != PRESSED)
		box->yes.anim_state = PRESSED;
	if (env->inputs.backspace
		&& box->type == YESNO
		&& box->yes.anim_state != PRESSED)
		box->no.anim_state = PRESSED;
	return (0);
}

int		no_pressed(void *target)
{
	t_confirmation_box	*box;

	box = (t_confirmation_box*)target;
	box->state = 0;
	if (box->no_action)
		box->no_action(box->no_target);
	return (0);
}

int		yes_pressed(void *target)
{
	t_confirmation_box	*box;

	box = (t_confirmation_box*)target;
	box->state = 0;
	if (box->yes_action)
		box->yes_action(box->yes_target);
	return (0);
}
