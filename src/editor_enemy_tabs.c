/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_enemy_tabs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:55:46 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 18:05:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_enemy_sector_tab2(t_env *env)
{
	print_text(new_point(600, 60), new_printable_text("Intensity",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->enemies[env->selected_enemy].sector].intensity);
	env->editor.hud.s_enemy.t_intensity.target =
	&env->sectors[env->enemies[env->selected_enemy].sector].intensity;
	draw_button(env, env->editor.hud.s_enemy.intensity, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("Gravity",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->enemies[env->selected_enemy].sector].
	gravity), env->sectors[env->enemies[env->selected_enemy].sector].gravity);
	env->editor.hud.s_enemy.t_gravity.target =
	&env->sectors[env->enemies[env->selected_enemy].sector].gravity;
	draw_button(env, env->editor.hud.s_enemy.gravity, env->snprintf);
	return (0);
}

int		print_enemy_sector_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Enemy %d",
	env->selected_enemy);
	TTF_SizeText(env->sdl.fonts.lato_black30, env->snprintf, &size.x, &size.y);
	print_text(new_point(465, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato_black30, 0x333333FF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->enemies[env->selected_enemy].sector].brightness);
	env->editor.hud.s_enemy.t_brightness.target =
	&env->sectors[env->enemies[env->selected_enemy].sector].brightness;
	draw_button(env, env->editor.hud.s_enemy.brightness, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Light color",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
	env->sectors[env->enemies[env->selected_enemy].sector].light_color);
	env->editor.hud.s_enemy.t_color.target =
	&env->sectors[env->enemies[env->selected_enemy].sector].light_color;
	draw_button(env, env->editor.hud.s_enemy.color, env->snprintf);
	return (print_enemy_sector_tab2(env));
}

int		print_enemy_general_tab3(t_env *env)
{
	draw_button(env, env->editor.hud.g_enemy.speed, env->snprintf);
	print_text(new_point(720, 60), new_printable_text("Scale",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->enemies[env->selected_enemy].scale),
	env->enemies[env->selected_enemy].scale);
	env->editor.hud.g_enemy.t_scale.target =
	&env->enemies[env->selected_enemy].scale;
	draw_button(env, env->editor.hud.g_enemy.scale, env->snprintf);
	print_text(new_point(760, 60), new_printable_text("Damage",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->enemies[env->selected_enemy].damage);
	env->editor.hud.g_enemy.t_damage.target =
	&env->enemies[env->selected_enemy].damage;
	draw_button(env, env->editor.hud.g_enemy.damage, env->snprintf);
	print_text(new_point(800, 60), new_printable_text("Angle",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->enemies[env->selected_enemy].angle),
	env->enemies[env->selected_enemy].angle);
	env->editor.hud.g_enemy.t_angle.target =
	&env->enemies[env->selected_enemy].angle;
	draw_button(env, env->editor.hud.g_enemy.angle, env->snprintf);
	return (0);
}

int		print_enemy_general_tab2(t_env *env)
{
	draw_button(env, env->editor.hud.g_enemy.pos_y, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Z",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->enemies[env->selected_enemy].pos.z)),
	env->enemies[env->selected_enemy].pos.z);
	env->editor.hud.g_enemy.t_pos_z.target =
	&env->enemies[env->selected_enemy].pos.z;
	draw_button(env, env->editor.hud.g_enemy.pos_z, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("Health",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->enemies[env->selected_enemy].map_hp);
	env->editor.hud.g_enemy.t_health.target =
	&env->enemies[env->selected_enemy].map_hp;
	draw_button(env, env->editor.hud.g_enemy.health, env->snprintf);
	print_text(new_point(680, 60), new_printable_text("Speed",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->enemies[env->selected_enemy].speed);
	env->editor.hud.g_enemy.t_speed.target =
	&env->enemies[env->selected_enemy].speed;
	return (print_enemy_general_tab3(env));
}

int		print_enemy_general_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Enemy %d",
	env->selected_enemy);
	TTF_SizeText(env->sdl.fonts.lato_black30, env->snprintf, &size.x, &size.y);
	print_text(new_point(465, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato_black30, 0x333333FF, 30), env);
	print_text(new_point(520, 60), new_printable_text("X",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->enemies[env->selected_enemy].pos.x)),
	env->enemies[env->selected_enemy].pos.x);
	env->editor.hud.g_enemy.t_pos_x.target =
	&env->enemies[env->selected_enemy].pos.x;
	draw_button(env, env->editor.hud.g_enemy.pos_x, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Y",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->enemies[env->selected_enemy].pos.y)),
	env->enemies[env->selected_enemy].pos.y);
	env->editor.hud.g_enemy.t_pos_y.target =
	&env->enemies[env->selected_enemy].pos.y;
	return (print_enemy_general_tab2(env));
}
