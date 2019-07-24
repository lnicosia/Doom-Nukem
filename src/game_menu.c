/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:41:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/24 10:41:54 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	start_game_menu(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	add_image(env, 32, 0, 0);
	add_button(env, 0, 850, 780, 0);
	print_text(new_point(780, 850), new_printable_text("START", env->sdl.fonts.amazdoom70, 0xFFFFFFFF, 70), env);
	update_screen(env);
}
