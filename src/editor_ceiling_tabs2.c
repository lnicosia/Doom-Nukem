/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_ceiling_tabs2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:36:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:36:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "env.h"

int		print_ceiling_sprite_tab2(t_env *env)
{
	draw_button(env, env->editor.hud.sp_ceiling_sprite.pos_y, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("Scale X",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].x),
	env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].x);
	env->editor.hud.sp_ceiling_sprite.t_scale_x.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].x;
	print_text(new_point(680, 60), new_printable_text("Scale Y",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	draw_button(env, env->editor.hud.sp_ceiling_sprite.scale_x, env->snprintf);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].y),
	env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].y);
	env->editor.hud.sp_ceiling_sprite.t_scale_y.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].y;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.scale_y, env->snprintf);
	return (0);
}

int		print_ceiling_sprite_tab(t_env *env)
{
	env->editor.next_sprite_env.type = CEILING_S;
	env->editor.previous_sprite_env.type = CEILING_S;
	print_text(new_point(560, 60), new_printable_text("X",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].
	ceiling_sprites.pos[env->selected_ceiling_sprite].x),
	env->sectors[env->selected_ceiling].
	ceiling_sprites.pos[env->selected_ceiling_sprite].x);
	env->editor.hud.sp_ceiling_sprite.t_pos_x.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].x;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.pos_x, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Y",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].y),
	env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].y);
	env->editor.hud.sp_ceiling_sprite.t_pos_y.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].y;
	return (print_ceiling_sprite_tab2(env));
}
