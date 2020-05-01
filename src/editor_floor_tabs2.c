/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_floor_tabs2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:36:35 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:36:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_floor_sprite_tab2(t_env *env)
{
	print_text(new_point(640, 60), new_printable_text("Scale X",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].
	floor_sprites.scale[env->selected_floor_sprite].x),
	env->sectors[env->selected_floor].
	floor_sprites.scale[env->selected_floor_sprite].x);
	env->editor.hud.sp_floor_sprite.t_scale_x.target = &env->sectors[env->
	selected_floor].floor_sprites.scale[env->selected_floor_sprite].x;
	draw_button(env, env->editor.hud.sp_floor_sprite.scale_x, env->snprintf);
	print_text(new_point(680, 60), new_printable_text("Scale Y",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].
	floor_sprites.scale[env->selected_floor_sprite].y),
	env->sectors[env->selected_floor].
	floor_sprites.scale[env->selected_floor_sprite].y);
	env->editor.hud.sp_floor_sprite.t_scale_y.target = &env->sectors[env->
	selected_floor].floor_sprites.scale[env->selected_floor_sprite].y;
	draw_button(env, env->editor.hud.sp_floor_sprite.scale_y, env->snprintf);
	return (0);
}

int		print_floor_sprite_tab(t_env *env)
{
	env->editor.next_sprite_env.type = FLOOR_S;
	env->editor.previous_sprite_env.type = FLOOR_S;
	print_text(new_point(560, 60), new_printable_text("X",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].
	floor_sprites.pos[env->selected_floor_sprite].x),
	env->sectors[env->selected_floor].
	floor_sprites.pos[env->selected_floor_sprite].x);
	env->editor.hud.sp_floor_sprite.t_pos_x.target = &env->sectors[env->
	selected_floor].floor_sprites.pos[env->selected_floor_sprite].x;
	draw_button(env, env->editor.hud.sp_floor_sprite.pos_x, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Y",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].
	floor_sprites.pos[env->selected_floor_sprite].y),
	env->sectors[env->selected_floor].
	floor_sprites.pos[env->selected_floor_sprite].y);
	env->editor.hud.sp_floor_sprite.t_pos_y.target = &env->sectors[env->
	selected_floor].floor_sprites.pos[env->selected_floor_sprite].y;
	draw_button(env, env->editor.hud.sp_floor_sprite.pos_y, env->snprintf);
	return (print_floor_sprite_tab2(env));
}

int		print_floor_sector_tab2(t_env *env)
{
	draw_button(env, env->editor.hud.s_floor.color, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Intensity:",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->selected_floor].intensity);
	env->editor.hud.s_floor.t_intensity.target =
	&env->sectors[env->selected_floor].intensity;
	draw_button(env, env->editor.hud.s_floor.intensity, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("Gravity:",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].gravity),
	env->sectors[env->selected_floor].gravity);
	env->editor.hud.s_floor.t_gravity.target =
	&env->sectors[env->selected_floor].gravity;
	draw_button(env, env->editor.hud.s_floor.gravity, env->snprintf);
	return (0);
}

int		print_floor_sector_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d",
	env->selected_floor);
	TTF_SizeText(env->sdl.fonts.lato_black30, env->snprintf, &size.x, &size.y);
	print_text(new_point(465, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato_black30, 0x333333FF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->selected_floor].brightness);
	env->editor.hud.s_floor.t_brightness.target =
	&env->sectors[env->selected_floor].brightness;
	draw_button(env, env->editor.hud.s_floor.brightness, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Light_color:",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
	env->sectors[env->selected_floor].light_color);
	env->editor.hud.s_floor.t_color.target =
	&env->sectors[env->selected_floor].light_color;
	return (print_floor_sector_tab2(env));
}
