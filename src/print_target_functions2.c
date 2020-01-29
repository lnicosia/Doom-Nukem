/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target_functions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/29 13:23:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_weapon_target(t_env *env, t_event event)
{
	print_text(new_point(540, 135), new_printable_text(ft_sitoa(event
	.update_param.weapon), env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_enemy_target(t_env *env, t_event event)
{
	print_text(new_point(540, 135), new_printable_text(ft_sitoa(event
	.update_param.enemy), env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_object_target(t_env *env, t_event event)
{
	print_text(new_point(540, 135), new_printable_text(ft_sitoa(event
	.update_param.object), env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	return (0);
}

int		print_nothing_target(t_env *env, t_event event)
{
	(void)env;
	(void)event;
	return (0);
}
