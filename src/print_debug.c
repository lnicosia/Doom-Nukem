/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:14:24 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/15 16:15:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>
void		print_debug(t_env *env)
{
	char	*player_sector;
	int		h;

	h = env->h;
	player_sector = ft_sitoa(env->player.sector);
	print_text(new_point(h - 150, 5), new_printable_text("Player sector = ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(h - 150, 215), new_printable_text(player_sector, env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(0, 1300), new_printable_text("Test", env->sdl.fonts.alice30, 0xFFFFFFFF, 20), env);
	print_text(new_point(h - 200, 5), new_printable_text("Clipping :", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	if (env->options.clipping)
		print_text(new_point(h - 200, 145), new_printable_text("ON", env->sdl.fonts.alice30, 0x00FF00FF, 30), env);
	else
		print_text(new_point(h - 200, 145), new_printable_text("OFF", env->sdl.fonts.alice30, 0xFF0000FF, 30), env);
}
