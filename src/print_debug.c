/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:14:24 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/15 17:50:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void		print_debug(t_env *env)
{
	char	*near_z;
	char	*player_sector;
	char	*camera_sector;

	player_sector = ft_itoa(env->player.sector);
	camera_sector = ft_itoa(env->player.camera_sector);
	print_text(new_v2(env->h - 150, 5), new_printable_text("Player sector = ", "fonts/alice/Alice-Regular.ttf", 0xFFFFFFFF, 30), env);
	print_text(new_v2(env->h - 150, 215), new_printable_text(player_sector, "fonts/alice/Alice-Regular.ttf", 0xFFFFFFFF, 30), env);
	print_text(new_v2(env->h - 100, 5), new_printable_text("Camera sector = ", "fonts/alice/Alice-Regular.ttf", 0xFFFFFFFF, 30), env);
	print_text(new_v2(env->h - 100, 225), new_printable_text(camera_sector, "fonts/alice/Alice-Regular.ttf", 0xFFFFFFFF, 30), env);
	print_text(new_v2(0, 1300), new_printable_text("Test", "fonts//alice/Alice-Regular.ttf", 0xFFFFFFFF, 20), env);
	if (env->options.render_type)
		print_text(new_v2(env->h - 50, 5), new_printable_text("Rendering from camera", "fonts/alice/Alice-Regular.ttf", 0xFFFFFFFF, 30), env);
	else
		print_text(new_v2(env->h - 50, 5), new_printable_text("Rendering from player", "fonts/alice/Alice-Regular.ttf", 0xFFFFFFFF, 30), env);
	print_text(new_v2(env->h - 200, 5), new_printable_text("Clipping :", "fonts/alice/Alice-Regular.ttf", 0xFFFFFFFF, 30), env);
	if (env->options.clipping)
		print_text(new_v2(env->h - 200, 145), new_printable_text("ON", "fonts/alice/Alice-Regular.ttf", 0x00FF00FF, 30), env);
	else
		print_text(new_v2(env->h - 200, 145), new_printable_text("OFF", "fonts/alice/Alice-Regular.ttf", 0xFF0000FF, 30), env);
	asprintf(&near_z, "%f", env->camera.near_z);
	print_text(new_v2(env->h - 250, 5), new_printable_text("Near_z =", "fonts/alice/Alice-Regular.ttf", 0xFFFFFFFF, 30), env);
	print_text(new_v2(env->h - 250, 135), new_printable_text(near_z, "fonts/alice/Alice-Regular.ttf", 0xFFFFFFFF, 30), env);
	ft_strdel(&near_z);
	ft_strdel(&player_sector);
	ft_strdel(&camera_sector);
}
