/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:29:20 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/04 17:23:15 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		draw_button_text(t_button b, t_env *env)
{
	t_printable_text	text;
	t_point			pos;
	t_point			text_size;
	t_point			button_size;
	Uint32			color;

	if (!b.str || !b.font)
		return ;
	color = 0xFFFFFFFF;
	button_size = new_point(0, 0);
	if (b.anim_state == HOVER)
	{
		color = b.hover_text_color;
		button_size = b.size_hover;
	}
	else if (b.anim_state == PRESSED)
	{
		color = b.pressed_text_color;
		button_size = b.size_pressed;
	}
	else if (b.state == UP)
	{
		color = b.up_text_color;
		button_size = b.size_up;
	}
	else if (b.state == DOWN)
	{
		color = b.down_text_color;
		button_size = b.size_down;
	}
	TTF_SizeText(b.font, b.str, &text_size.x, &text_size.y);
	pos = new_point(b.pos.y + button_size.y / 2 - text_size.y / 2,
	b.pos.x + button_size.x / 2 - text_size.x / 2);
	text = new_printable_text(b.str, b.font, color, button_size.y);
	print_text(pos, text, env);
}

t_button	init_button(int type, void (*action)(void *), void *target,
t_env *env)
{
	t_button	new;

	ft_bzero(&new, sizeof(t_button));
	new.pos = new_point(env->h_w - 111, env->h_h - 23);
	new.up_text_color = 0xFFFFFFFF;
	new.hover_text_color = 0xFFFFFFFF;
	new.pressed_text_color = 0xEEEEEEFF;
	new.down_text_color = 0xEEEEEEFF;
	if (!env->sdl.fonts.lato20)
		ft_dprintf(STDERR_FILENO, "Button font has not been init yet!\n");
	new.font = env->sdl.fonts.lato20;
	new.target = target;
	new.draw = 1;
	new.state = UP;
	new.anim_state = REST;
	if (type == ON_PRESS)
		new.press_action = action;
	else if (type == WHEN_DOWN)
		new.down_action = action;
	return (new);
}

t_button	new_rectangle_button(int type, void (*action)(void *), void *target, t_env *env)
{
	t_button	new;

	new = init_button(type, action, target, env);
	new.up = new_rectangle(0xFFAAAAAA, 0xFF666666, 1, 2);
	new.down = new_rectangle(0xFF888888, 0xFF444444, 1, 2);
	new.pressed = new_rectangle(0xFF888888, 0xFF444444, 1, 2);
	new.hover = new_rectangle(0xFFBBBBBB, 0xFF888888, 1, 2);
	new.size_up = new_point(212, 45);
	new.size_pressed = new_point(212, 45);
	new.size_down = new_point(212, 45);
	new.size_hover = new_point(212, 45);
	return (new);
}

t_button	new_miniature_button(int type, void (*action)(void *), void *target, t_env *env)
{
	t_button	new;

	new = init_button(type, action, target, env);
/*	if (!env->sprite_textures[28].surface || !env->sprite_textures[29].surface
		|| !env->sprite_textures[30].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");*/
	new.img_up = &env->editor.miniature;
	new.img_pressed = &env->editor.miniature;
	new.img_down = &env->editor.miniature;
	new.img_hover = &env->editor.miniature;
	new.size_up = new_point(new.img_up->surface->w,
	new.img_up->surface->h);
	new.size_down = new_point(new.img_down->maps[6]->w,
	new.img_down->surface->h);
	new.size_hover = new_point(new.img_hover->surface->w,
	new.img_hover->surface->h);
	new.size_pressed = new_point(new.img_pressed->surface->w,
	new.img_pressed->surface->h);
	return (new);
}

t_button	new_image_button(int type, void (*action)(void *), void *target, t_env *env)
{
	t_button	new;

	new = init_button(type, action, target, env);
/*	if (!env->sprite_textures[28].surface || !env->sprite_textures[29].surface
		|| !env->sprite_textures[30].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");*/
	new.img_up = &env->wall_textures[0];
	new.img_pressed = &env->wall_textures[0];
	new.img_down = &env->wall_textures[0];
	new.img_hover = &env->wall_textures[0];
	new.size_up = new_point(new.img_up->surface->w,
	new.img_up->surface->h);
	new.size_down = new_point(new.img_down->maps[6]->w,
	new.img_down->surface->h);
	new.size_hover = new_point(new.img_hover->surface->w,
	new.img_hover->surface->h);
	new.size_pressed = new_point(new.img_pressed->surface->w,
	new.img_pressed->surface->h);
	return (new);
}

void	draw_button(t_env *env, t_button b)
{
	t_point	pos;

	pos = new_point(b.pos.y, b.pos.x);
	if (!b.img_up || !b.img_pressed || !b.img_down || !b.img_hover)
	{
		if (b.anim_state == HOVER)
			draw_rectangle(env, b.hover, b.pos, b.size_up);
		else if (b.anim_state == PRESSED)
			draw_rectangle(env, b.pressed, b.pos, b.size_pressed);
		else if (b.state == UP)
			draw_rectangle(env, b.up, b.pos, b.size_up);
		else if (b.state == DOWN)
			draw_rectangle(env, b.down, b.pos, b.size_down);
	}
	else
	{
		if (b.anim_state == HOVER)
			apply_surface(b.img_hover->surface, pos, b.size_up, env);
		else if (b.anim_state == PRESSED)
			apply_surface(b.img_pressed->surface, pos, b.size_pressed, env);
		else if (b.state == UP)
			apply_surface(b.img_up->surface, pos, b.size_up, env);
		else if (b.state == DOWN)
			apply_surface(b.img_down->surface, pos, b.size_down, env);
	}
	draw_button_text(b, env);
}
