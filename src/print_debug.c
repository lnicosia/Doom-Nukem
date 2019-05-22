/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:14:24 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/22 10:30:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
void		print_debug(t_env *env)
{
	char	*player_sector;
	char	*left_sector;
	char	*right_sector;
	int		h;

	h = env->h;
	player_sector = ft_sitoa(env->player.sector);
	left_sector = ft_sitoa(env->player.near_left_sector);
	right_sector = ft_sitoa(env->player.near_right_sector);
	print_text(new_point(h - 150, 5), new_printable_text("Player sector = ", env->sdl.fonts.alice, 0xFFFFFFFF, 30), env);
	print_text(new_point(h - 150, 215), new_printable_text(player_sector, env->sdl.fonts.alice, 0xFFFFFFFF, 30), env);
	print_text(new_point(h - 100, 5), new_printable_text("Near_left sector = ", env->sdl.fonts.alice, 0xFFFFFFFF, 30), env);
	print_text(new_point(h - 50, 5), new_printable_text("Near_right sector = ", env->sdl.fonts.alice, 0xFFFFFFFF, 30), env);
	print_text(new_point(h - 100, 255), new_printable_text(left_sector, env->sdl.fonts.alice, 0xFFFFFFFF, 30), env);
	print_text(new_point(h - 50, 275), new_printable_text(right_sector, env->sdl.fonts.alice, 0xFFFFFFFF, 30), env);
	print_text(new_point(0, 1300), new_printable_text("Test", env->sdl.fonts.alice, 0xFFFFFFFF, 20), env);
	print_text(new_point(h - 200, 5), new_printable_text("Clipping :", env->sdl.fonts.alice, 0xFFFFFFFF, 30), env);
	if (env->options.clipping)
		print_text(new_point(h - 200, 145), new_printable_text("ON", env->sdl.fonts.alice, 0x00FF00FF, 30), env);
	else
		print_text(new_point(h - 200, 145), new_printable_text("OFF", env->sdl.fonts.alice, 0xFF0000FF, 30), env);
}
