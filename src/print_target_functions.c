/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 16:04:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_sector_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sector),
	font, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_wall_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sector),
	font, 0xFFFFFFFF, 0), env);
	print_text(new_point(540, 210), new_printable_text(ft_sitoa(event->
	update_param.wall), font, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_floor_sprite_target(t_env *env, t_event *event, t_point pos,
int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sector),
	font, 0xFFFFFFFF, 0), env);
	print_text(new_point(540, 210), new_printable_text(ft_sitoa(event->
	update_param.sprite), font, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_wall_sprite_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sector),
	font, 0xFFFFFFFF, 0), env);
	print_text(new_point(540, 210), new_printable_text(ft_sitoa(event->
	update_param.wall), font, 0xFFFFFFFF, 0), env);
	print_text(new_point(540, 305), new_printable_text(ft_sitoa(event->
	update_param.sprite), font, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_vertex_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.vertex),
	font, 0xFFFFFFFF, 0), env);
	return (0);
}
