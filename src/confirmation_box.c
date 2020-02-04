/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirmation_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:40:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 13:24:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		confirmation_box_keyup(t_confirmation_box *box, t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RETURN
		&& box->yes.anim_state == PRESSED
		&& box->no.anim_state != PRESSED)
	{
		if (box->yes_action)
			box->yes_action(box->yes_target);
		box->state = 0;
		env->editor.enter_locked = 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_BACKSPACE
		&& box->type == YESNO
		&& box->yes.anim_state != PRESSED)
	{
		if (box->no_action)
			box->no_action(box->no_target);
		box->state = 0;
	}
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

void	new_buttons(t_confirmation_box *box, int height, t_env *env)
{
	if (box->type == YESNO)
	{
		box->no = new_rectangle_button(WHEN_DOWN, &no_pressed, box, env);
		box->no.up = new_rectangle(0xFFDD0000, 0xFF990000, 1, 2);
		box->no.down = new_rectangle(0xFF990000, 0xFF990000, 1, 2);
		box->no.pressed = new_rectangle(0xFF990000, 0xFF990000, 1, 2);
		box->no.hover = new_rectangle(0xFFEE0000, 0xFFAA0000, 1, 2);
		box->no.size_up.x = box->size.x / 2;
		box->no.size_up.y = height + 5;
		box->no.size_pressed = box->no.size_up;
		box->no.size_down = box->no.size_up;
		box->no.size_hover = box->no.size_up;
		box->no.pos.x = env->w / 2 - box->size.x / 2;
		box->no.pos.y = env->h / 2 + box->size.y / 2 - height - 5;
		box->no.str = "No";
		box->no.font = box->font;
	}
	box->yes = new_rectangle_button(WHEN_DOWN, &yes_pressed, box, env);
	box->yes.up = new_rectangle(0xFF00DD00, 0xFF009900, 1, 2);
	box->yes.down = new_rectangle(0xFF009900, 0xFF009900, 1, 2);
	box->yes.pressed = new_rectangle(0xFF009900, 0xFF009900, 1, 2);
	box->yes.hover = new_rectangle(0xFF00EE00, 0xFF00AA00, 1, 2);
	box->yes.font = box->font;
	box->yes.size_up.x = box->size.x / 2;
	box->yes.size_up.y = height + 5;
	box->yes.size_pressed = box->yes.size_up;
	box->yes.size_down = box->yes.size_up;
	box->yes.size_hover = box->yes.size_up;
	if (box->type == YESNO)
	{
		box->yes.pos.x = env->w / 2;
		box->yes.pos.y = env->h / 2 + box->size.y / 2 - height - 5;
		box->yes.str = "Yes";
	}
	else
	{
		box->yes.pos.x = env->w / 2 - box->yes.size_up.x / 2;
		box->yes.pos.y = env->h / 2 + box->size.y / 2 - height - 15;
		box->yes.str = "Ok";
	}
}

int			get_box_size(t_confirmation_box *box)
{
	t_point	text_size;
	t_point	yes_size;

	TTF_SizeText(box->font, box->str, &text_size.x, &text_size.y);
	TTF_SizeText(box->font, "Yes", &yes_size.x, &yes_size.y);
	box->size.x = ft_max(yes_size.x * 3, text_size.x + 20);
	box->size.y = ft_max(yes_size.y * 3, 50);
	if (box->type != YESNO)
		box->size.y += 10;
	return (yes_size.y);
}

int	update_confirmation_box(t_confirmation_box *box, char *str,
int type, t_env *env)
{
	if (!str)
		return (custom_error("Confirmation box message is empty"));
	if (!box->font)
		return (custom_error("Confirmation box font is NULL"));
	box->str = str;
	box->state = 1;
	box->type = type;
	new_buttons(box, get_box_size(box), env);
	box->yes_action = NULL;
	box->yes_target = NULL;
	box->no_action = NULL;
	box->no_target = NULL;
	box->no.state = UP;
	box->no.anim_state = REST;
	box->yes.state = UP;
	box->yes.anim_state = REST;
	return (0);
}

int			draw_confirmation_box(t_confirmation_box *box, t_env *env)
{
	t_point	text_size;

	draw_rectangle(env,
			new_rectangle(0xFFAAAAAA, 0xFF666666, 1, 2),
			new_point(env->w / 2 - box->size.x / 2,
			env->h / 2 - box->size.y / 2),
			new_point(box->size.x, box->size.y));
	draw_button(env, box->yes, box->yes.str);
	if (box->type == YESNO)
		draw_button(env, box->no, box->no.str);
	TTF_SizeText(box->font, box->str, &text_size.x, &text_size.y);
	print_text(new_point(env->h / 2 - box->size.y / 3,
				env->w / 2 - text_size.x / 2),
			new_printable_text(box->str, box->font, 0xFFFFFFFF, 0), env);
	return (0);
}
