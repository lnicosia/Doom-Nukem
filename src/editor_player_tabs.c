/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_player_tabs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:23:23 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 18:45:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_player_sector_tab2(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->player.sector].intensity);
	env->editor.hud.s_player.t_intensity.target =
	&env->sectors[env->player.sector].intensity;
	draw_button(env, env->editor.hud.s_player.intensity, env->snprintf);
	if (print_text(new_point(640, 60), new_printable_text("Gravity",
	env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->player.sector].gravity),
	env->sectors[env->player.sector].gravity);
	env->editor.hud.s_player.t_gravity.target =
	&env->sectors[env->player.sector].gravity;
	draw_button(env, env->editor.hud.s_player.gravity, env->snprintf);
	return (0);
}

int		print_player_sector_tab(t_env *env)
{
	t_point		size;

	TTF_SizeText(env->sdl.fonts.lato_black30, "Player", &size.x, &size.y);
	if (print_text(new_point(465, 200 - size.x / 2), new_printable_text("Player",
		env->sdl.fonts.lato_black30, 0x333333FF, 30), env))
		return (-1);
	if (print_text(new_point(520, 60), new_printable_text("Brightness",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->player.sector].brightness);
	env->editor.hud.s_player.t_brightness.target =
	&env->sectors[env->player.sector].brightness;
	draw_button(env, env->editor.hud.s_player.brightness, env->snprintf);
	if (print_text(new_point(560, 60), new_printable_text("Light_color",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
	env->sectors[env->player.sector].light_color);
	env->editor.hud.s_player.t_color.target =
	&env->sectors[env->player.sector].light_color;
	draw_button(env, env->editor.hud.s_player.color, env->snprintf);
	if (print_text(new_point(600, 60), new_printable_text("Intensity",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	return (print_player_sector_tab2(env));
}

int		print_player_general_tab3(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->player.init_data.camera.angle),
	env->player.init_data.camera.angle);
	env->editor.hud.g_player.t_angle.target =
	&env->player.init_data.camera.angle;
	draw_button(env, env->editor.hud.g_player.angle, env->snprintf);
	return (0);
}

int		print_player_general_tab2(t_env *env)
{
	env->editor.hud.g_player.t_pos_z.target = &env->player.starting_pos.z;
	draw_button(env, env->editor.hud.g_player.pos_z, env->snprintf);
	if (print_text(new_point(640, 60), new_printable_text("Health ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d", env->player.health);
	env->editor.hud.g_player.t_health.target = &env->player.health;
	draw_button(env, env->editor.hud.g_player.health, env->snprintf);
	if (print_text(new_point(680, 60), new_printable_text("Armor ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d", env->player.armor);
	env->editor.hud.g_player.t_armor.target = &env->player.armor;
	draw_button(env, env->editor.hud.g_player.armor, env->snprintf);
	if (print_text(new_point(720, 60), new_printable_text("Speed ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->player.speed), env->player.speed);
	env->editor.hud.g_player.t_speed.target = &env->player.speed;
	draw_button(env, env->editor.hud.g_player.speed, env->snprintf);
	if (print_text(new_point(760, 60), new_printable_text("Angle ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	return (print_player_general_tab3(env));
}

int		print_player_general_tab(t_env *env)
{
	t_point		size;

	if (TTF_SizeText(env->sdl.fonts.lato_black30, "Player", &size.x, &size.y))
		return (-1);
	if (print_text(new_point(465, 200 - size.x / 2),
		new_printable_text("Player", env->sdl.fonts.lato_black30, 0x333333FF,
		30), env))
		return (-1);
	if (print_text(new_point(520, 60), new_printable_text("X ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->player.starting_pos.x)),
	env->player.starting_pos.x);
	env->editor.hud.g_player.t_pos_x.target = &env->player.starting_pos.x;
	draw_button(env, env->editor.hud.g_player.pos_x, env->snprintf);
	if (print_text(new_point(560, 60), new_printable_text("Y ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->player.starting_pos.y)),
	env->player.starting_pos.y);
	env->editor.hud.g_player.t_pos_y.target = &env->player.pos.y;
	if (print_text(new_point(600, 60), new_printable_text("Z ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	draw_button(env, env->editor.hud.g_player.pos_y, env->snprintf);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->player.starting_pos.z)),
	env->player.starting_pos.z);
	return (print_player_general_tab2(env));
}
