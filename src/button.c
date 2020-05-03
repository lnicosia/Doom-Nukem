/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:29:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:58:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		set_color_and_size(Uint32 *color, t_point *button_size, t_button b)
{
	if (b.anim_state == HOVER)
	{
		*color = b.hover_text_color;
		*button_size = b.size_hover;
	}
	else if (b.anim_state == PRESSED)
	{
		*color = b.pressed_text_color;
		*button_size = b.size_pressed;
	}
	else if (b.state == UP)
	{
		*color = b.up_text_color;
		*button_size = b.size_up;
	}
	else if (b.state == DOWN)
	{
		*color = b.down_text_color;
		*button_size = b.size_down;
	}
}

void		draw_button_text(t_button b, char *str, t_env *env)
{
	t_printable_text	text;
	t_point				pos;
	t_point				text_size;
	t_point				button_size;
	Uint32				color;

	if (!str || !b.font)
		return ;
	color = 0xFFFFFFFF;
	button_size = new_point(0, 0);
	set_color_and_size(&color, &button_size, b);
	TTF_SizeText(b.font, str, &text_size.x, &text_size.y);
	pos = new_point(b.pos.y + button_size.y / 2 - text_size.y / 2,
	b.pos.x + button_size.x / 2 - text_size.x / 2);
	text = new_printable_text(str, b.font, color, button_size.y);
	print_text(pos, text, env);
}

t_button	init_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	ft_bzero(&new, sizeof(t_button));
	new.pos = new_point(env->h_w - 111, env->h_h - 23);
	new.up_text_color = 0x00000000;
	new.hover_text_color = 0x00000000;
	new.pressed_text_color = 0x00000000;
	new.down_text_color = 0x00000000;
	if (!env->sdl.fonts.lato20)
		ft_dprintf(STDERR_FILENO, "Button font has not been init yet!\n");
	new.font = env->sdl.fonts.lato20;
	if (type == ON_RELEASE)
		new.release_param = param;
	else
		new.param = param;
	new.draw = 1;
	new.state = UP;
	new.anim_state = REST;
	if (type == ON_PRESS)
		new.press_action = action;
	else if (type == WHEN_DOWN)
		new.down_action = action;
	else if (type == ON_RELEASE)
		new.release_action = action;
	return (new);
}

t_button	new_previous_button_2(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[61].surface || !env->ui_textures[62].surface
		|| !env->ui_textures[63].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[61].surface;
	new.img_pressed = env->ui_textures[62].surface;
	new.img_down = env->ui_textures[62].surface;
	new.img_hover = env->ui_textures[63].surface;
	new.size_up = new_point(32, 32);
	new.size_down = new_point(32, 32);
	new.size_hover = new_point(32, 32);
	new.size_pressed = new_point(32, 32);
	return (new);
}
