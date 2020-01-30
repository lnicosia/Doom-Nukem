/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target_functions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 16:04:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_weapon_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.weapon),
	font, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_enemy_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.enemy),
	font, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_object_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.object),
	font, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_nothing_target(t_env *env, t_event *event, t_point pos, int size)
{
	(void)env;
	(void)event;
	(void)pos;
	(void)size;
	return (0);
}
