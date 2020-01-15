/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_player_tabs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:31:19 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/15 11:47:03 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_player_sprite_tab(t_env *env)
{
	(void)env;
}

void	print_player_sector_tab(t_env *env)
{
	print_text(new_point(480, 60), new_printable_text("Sector:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(480, 230), new_printable_text(ft_sitoa(env->player.sector),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 230), new_printable_text(ft_sitoa(env->sectors[env->player.sector].brightness),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 60), new_printable_text("Light_color:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 230), new_printable_text(ft_sitoa(env->sectors[env->player.sector].light_color),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 60), new_printable_text("Intensity:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 230), new_printable_text(ft_sitoa(env->sectors[env->player.sector].intensity),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	print_player_general_tab(t_env *env)
{
	print_text(new_point(520, 60), new_printable_text("Speed: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 230), new_printable_text(ft_sitoa(env->player.speed), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 60), new_printable_text("Health: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 230), new_printable_text(ft_sitoa(env->player.health), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 60), new_printable_text("Pos X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 230), new_printable_text(ft_sitoa(env->player.pos.x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 60), new_printable_text("Pos Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 230), new_printable_text(ft_sitoa(env->player.pos.y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(680, 60), new_printable_text("Pos Z: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(680, 230), new_printable_text(ft_sitoa(env->player.pos.z), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);

}