/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:34:29 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/26 10:04:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	start_editor_menu(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	add_image(env, 37, 0, 0);
	env->editor.select_mode = 0;
	print_text(new_point(env->h / 2, env->w / 2 - 50), new_printable_text("Rdit map", env->sdl.fonts.amazdoom50, 0xFFFFFFFF, 50), env);
	add_button(env, 0, env->w / 2 - 50, env->h / 2, 9);
	update_screen(env);
}
