/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_floor_tabs3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 12:32:22 by marvin            #+#    #+#             */
/*   Updated: 2020/05/18 13:05:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int	print_floor_sprite_tab3(t_env *env)
{
	if (draw_button(env, env->editor.hud.sp_floor_sprite.scale_y,
		env->snprintf))
		return (-1);
	return (0);
}

int	print_floor_sprite_tab2(t_env *env)
{
	if (draw_button(env, env->editor.hud.sp_floor_sprite.pos_y, env->snprintf))
		return (-1);
	if (print_text(new_point(640, 60), new_printable_text("Scale X",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].
	floor_sprites.scale[env->selected_floor_sprite].x),
	env->sectors[env->selected_floor].
	floor_sprites.scale[env->selected_floor_sprite].x);
	env->editor.hud.sp_floor_sprite.t_scale_x.target = &env->sectors[env->
	selected_floor].floor_sprites.scale[env->selected_floor_sprite].x;
	if (draw_button(env, env->editor.hud.sp_floor_sprite.scale_x,
		env->snprintf))
		return (-1);
	if (print_text(new_point(680, 60), new_printable_text("Scale Y",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].
	floor_sprites.scale[env->selected_floor_sprite].y),
	env->sectors[env->selected_floor].
	floor_sprites.scale[env->selected_floor_sprite].y);
	env->editor.hud.sp_floor_sprite.t_scale_y.target = &env->sectors[env->
	selected_floor].floor_sprites.scale[env->selected_floor_sprite].y;
	return (print_floor_sprite_tab3(env));
}

int	print_floor_sprite_tab(t_env *env)
{
	env->editor.next_sprite_env.type = FLOOR_S;
	env->editor.previous_sprite_env.type = FLOOR_S;
	if (print_text(new_point(560, 60), new_printable_text("X",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].
	floor_sprites.pos[env->selected_floor_sprite].x),
	env->sectors[env->selected_floor].
	floor_sprites.pos[env->selected_floor_sprite].x);
	env->editor.hud.sp_floor_sprite.t_pos_x.target = &env->sectors[env->
	selected_floor].floor_sprites.pos[env->selected_floor_sprite].x;
	if (draw_button(env, env->editor.hud.sp_floor_sprite.pos_x, env->snprintf))
		return (-1);
	if (print_text(new_point(600, 60), new_printable_text("Y",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].
	floor_sprites.pos[env->selected_floor_sprite].y),
	env->sectors[env->selected_floor].
	floor_sprites.pos[env->selected_floor_sprite].y);
	env->editor.hud.sp_floor_sprite.t_pos_y.target = &env->sectors[env->
	selected_floor].floor_sprites.pos[env->selected_floor_sprite].y;
	return (print_floor_sprite_tab2(env));
}

