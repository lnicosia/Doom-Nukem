/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 12:04:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_sector_target(t_env *env, t_event *event, t_point pos)
{
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sector),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_wall_target(t_env *env, t_event *event, t_point pos)
{
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sector),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	print_text(new_point(540, 210), new_printable_text(ft_sitoa(event->
	update_param.wall), env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_floor_sprite_target(t_env *env, t_event *event, t_point pos)
{
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sector),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	print_text(new_point(540, 210), new_printable_text(ft_sitoa(event->
	update_param.sprite), env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_wall_sprite_target(t_env *env, t_event *event, t_point pos)
{
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sector),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	print_text(new_point(540, 210), new_printable_text(ft_sitoa(event->
	update_param.wall), env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	print_text(new_point(540, 305), new_printable_text(ft_sitoa(event->
	update_param.sprite), env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_vertex_target(t_env *env, t_event *event, t_point pos)
{
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.vertex),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	return (0);
}
