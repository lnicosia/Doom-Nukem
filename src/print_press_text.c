/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_press_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:44:05 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:41:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_press_text(t_env *env)
{
	print_text(new_point(env->h - 200, env->h_w),
	new_printable_text("Press [E]", env->sdl.fonts.lato50, 0xFFFFFFFF, 30),
	env);
}
