/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:33:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:33:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_button	new_rectangle_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	new.up = new_rectangle(0xFFf1f2f3, 0xFFf1f2f3, 1, 0);
	new.down = new_rectangle(0xFFe3e4e8, 0xFFe3e4e8, 1, 0);
	new.pressed = new_rectangle(0xFFe3e4e8, 0xFFe3e4e8, 1, 0);
	new.hover = new_rectangle(0xFFf7f8f9, 0xFFf7f8f9, 1, 0);
	new.size_up = new_point(98, 98);
	new.size_pressed = new_point(98, 98);
	new.size_down = new_point(98, 98);
	new.size_hover = new_point(98, 98);
	return (new);
}

t_button	new_image_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[39].surface || !env->ui_textures[40].surface
		|| !env->ui_textures[41].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[39].surface;
	new.img_pressed = env->ui_textures[40].surface;
	new.img_down = env->ui_textures[40].surface;
	new.img_hover = env->ui_textures[41].surface;
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

t_button	new_add_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[35].surface || !env->ui_textures[35].surface
		|| !env->ui_textures[35].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[35].surface;
	new.img_pressed = env->ui_textures[35].surface;
	new.img_down = env->ui_textures[35].surface;
	new.img_hover = env->ui_textures[35].surface;
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

t_button	new_minus_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[21].surface || !env->ui_textures[22].surface
		|| !env->ui_textures[23].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[21].surface;
	new.img_pressed = env->ui_textures[22].surface;
	new.img_down = env->ui_textures[22].surface;
	new.img_hover = env->ui_textures[23].surface;
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

t_button	new_background_button(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[32].surface || !env->ui_textures[33].surface
		|| !env->ui_textures[34].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[32].surface;
	new.img_pressed = env->ui_textures[33].surface;
	new.img_down = env->ui_textures[33].surface;
	new.img_hover = env->ui_textures[34].surface;
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
