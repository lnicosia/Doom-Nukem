/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:14:24 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/13 11:16:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		print_debug(t_env *env)
{
	int		h;

	h = env->h;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Player sector = %d",
	env->player.sector);
	print_text(new_point(h - 150, 5), new_printable_text(env->snprintf,
	env->sdl.fonts.lato30, 0xFFFFFFFF, 30), env);
}
