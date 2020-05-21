/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_ceiling_tabs2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:36:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/18 11:54:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "env.h"

int		print_ceiling_sprite_tab3(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].y),
	env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].y);
	env->editor.hud.sp_ceiling_sprite.t_scale_y.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].y;
	if (draw_button(env, env->editor.hud.sp_ceiling_sprite.scale_y,
		env->snprintf))
		return (-1);
	return (0);
}

int		print_ceiling_sprite_tab2(t_env *env)
{
	env->editor.hud.sp_ceiling_sprite.t_pos_y.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].y;
	if (draw_button(env, env->editor.hud.sp_ceiling_sprite.pos_y,
		env->snprintf))
		return (-1);
	if (print_text(new_point(640, 60), new_printable_text("Scale X",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].x),
	env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].x);
	env->editor.hud.sp_ceiling_sprite.t_scale_x.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].x;
	if (print_text(new_point(680, 60), new_printable_text("Scale Y",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	if (draw_button(env, env->editor.hud.sp_ceiling_sprite.scale_x,
		env->snprintf))
		return (-1);
	return (print_ceiling_sprite_tab3(env));
}

int		print_ceiling_sprite_tab(t_env *env)
{
	env->editor.next_sprite_env.type = CEILING_S;
	env->editor.previous_sprite_env.type = CEILING_S;
	if (print_text(new_point(560, 60), new_printable_text("X",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].
	ceiling_sprites.pos[env->selected_ceiling_sprite].x),
	env->sectors[env->selected_ceiling].
	ceiling_sprites.pos[env->selected_ceiling_sprite].x);
	env->editor.hud.sp_ceiling_sprite.t_pos_x.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].x;
	if (draw_button(env, env->editor.hud.sp_ceiling_sprite.pos_x,
		env->snprintf))
		return (-1);
	if (print_text(new_point(600, 60), new_printable_text("Y",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].y),
	env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].y);
	return (print_ceiling_sprite_tab2(env));
}
