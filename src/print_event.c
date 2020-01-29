/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:47:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/29 12:13:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_event(t_env *env, t_event event)
{
	(void)env;
	(void)event;
	print_text(new_point(540, 10), new_printable_text("Target: ",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_text(new_point(540, 75), new_printable_text(env->
	event_types[event.target_index],
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	env->print_target_data[event.target_index](env, event);
}
