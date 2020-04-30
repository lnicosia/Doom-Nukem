/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_button2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:32:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:32:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_button	new_hud_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xf1f2f6, 0, 1, 0);
	new.pressed = new_rectangle(0xdfe4ea, 0, 1, 0);
	new.down = new_rectangle(0xdfe4ea, 0, 1, 0);
	new.hover = new_rectangle(0xffffff, 0, 1, 0);
	new.size_up = new_point(192, 32);
	new.size_down = new_point(192, 32);
	new.size_hover = new_point(192, 32);
	new.size_pressed = new_point(192, 32);
	new.up_text_color = 0x333333FF;
	new.hover_text_color = 0x333333FF;
	new.pressed_text_color = 0x333333FF;
	new.down_text_color = 0x333333FF;
	return (new);
}

t_button	new_hud_pos_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xf1f2f6, 0, 1, 0);
	new.pressed = new_rectangle(0xdfe4ea, 0, 1, 0);
	new.down = new_rectangle(0xdfe4ea, 0, 1, 0);
	new.hover = new_rectangle(0xffffff, 0, 1, 0);
	new.size_up = new_point(50, 32);
	new.size_down = new_point(50, 32);
	new.size_hover = new_point(50, 32);
	new.size_pressed = new_point(50, 32);
	new.up_text_color = 0x333333FF;
	new.hover_text_color = 0x333333FF;
	new.pressed_text_color = 0x333333FF;
	new.down_text_color = 0x333333FF;
	return (new);
}

t_button	new_tab_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[36].surface || !env->ui_textures[37].surface
		|| !env->ui_textures[38].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[36].surface;
	new.img_pressed = env->ui_textures[37].surface;
	new.img_down = env->ui_textures[37].surface;
	new.img_hover = env->ui_textures[38].surface;
	new.size_up = new_point(new.img_up->w,
	new.img_up->h);
	new.size_down = new_point(new.img_down->w,
	new.img_down->h);
	new.size_hover = new_point(new.img_hover->w,
	new.img_hover->h);
	new.size_pressed = new_point(new.img_pressed->w,
	new.img_pressed->h);
	return (new);
}

t_button	new_next_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[15].surface || !env->ui_textures[16].surface
		|| !env->ui_textures[17].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[15].surface;
	new.img_pressed = env->ui_textures[16].surface;
	new.img_down = env->ui_textures[16].surface;
	new.img_hover = env->ui_textures[17].surface;
	new.size_up = new_point(32, 32);
	new.size_down = new_point(32, 32);
	new.size_hover = new_point(32, 32);
	new.size_pressed = new_point(32, 32);
	return (new);
}

t_button	new_previous_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[18].surface || !env->ui_textures[19].surface
		|| !env->ui_textures[20].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[18].surface;
	new.img_pressed = env->ui_textures[19].surface;
	new.img_down = env->ui_textures[19].surface;
	new.img_hover = env->ui_textures[20].surface;
	new.size_up = new_point(32, 32);
	new.size_down = new_point(32, 32);
	new.size_hover = new_point(32, 32);
	new.size_pressed = new_point(32, 32);
	return (new);
}
