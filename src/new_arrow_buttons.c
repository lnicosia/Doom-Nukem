/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arrow_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:46:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 11:50:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_button	new_next_arrow(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[NEXT_ICON].surface
		|| !env->ui_textures[NEXT_ICON].surface
		|| !env->ui_textures[NEXT_ICON].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[NEXT_ICON].surface;
	new.img_pressed = env->ui_textures[NEXT_ICON_DOWN].surface;
	new.img_down = env->ui_textures[NEXT_ICON_DOWN].surface;
	new.img_hover = env->ui_textures[NEXT_ICON_HOVER].surface;
	new.size_up = new_point(new.img_up->w, new.img_up->h);
	new.size_down = new_point(new.img_down->w, new.img_down->h);
	new.size_pressed = new_point(new.img_pressed->w, new.img_pressed->h);
	new.size_hover = new_point(new.img_hover->w, new.img_hover->h);
	return (new);
}

t_button	new_previous_arrow(int type, int (*action)(void *), void *param,
t_env *env)
{
	t_button	new;

	new = init_button(type, action, param, env);
	if (!env->ui_textures[PREVIOUS_ICON].surface
		|| !env->ui_textures[PREVIOUS_ICON].surface
		|| !env->ui_textures[PREVIOUS_ICON].surface)
		ft_dprintf(STDERR_FILENO, "Button textures have not been init yet!\n");
	new.img_up = env->ui_textures[PREVIOUS_ICON].surface;
	new.img_pressed = env->ui_textures[PREVIOUS_ICON_DOWN].surface;
	new.img_down = env->ui_textures[PREVIOUS_ICON_DOWN].surface;
	new.img_hover = env->ui_textures[PREVIOUS_ICON_HOVER].surface;
	new.size_up = new_point(new.img_up->w, new.img_up->h);
	new.size_down = new_point(new.img_down->w, new.img_down->h);
	new.size_pressed = new_point(new.img_pressed->w, new.img_pressed->h);
	new.size_hover = new_point(new.img_hover->w, new.img_hover->h);
	return (new);
}
