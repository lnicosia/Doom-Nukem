/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:44:44 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/30 14:10:06 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	editor_hud(t_env *env)
{
	t_point	center;

	center.x = 100;
	center.y = 200;
	draw_circle(new_circle(0xFFFF0000, 0xFFFF0000, center, (env->editor.scale / 2)), env);
	print_text(new_point(150, 60), new_printable_text("Player", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	center.x = 100;
	center.y = 300;
	draw_circle(new_circle(0xFFFFFF00, 0xFFFFFF00, center, (env->editor.scale / 2)), env);
	print_text(new_point(250, 60), new_printable_text("Object", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}
