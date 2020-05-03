/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:36:54 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/30 18:41:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_results(t_env *env)
{
	draw_rectangle(env,
		new_rectangle(0x00000000, 0xFF888888, 1, 5),
		new_point(200, 180), new_point(350, 520));
	print_text(new_point(200, 320), new_printable_text("Score :",
	env->sdl.fonts.amazdoom50, 0xFFFFFFFF, 50), env);
	if (env->player.killed > 1)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "You killed %d enemies",
		env->player.killed);
	else
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "You killed %d enemy",
		env->player.killed);
	print_text(new_point(280, 220), new_printable_text(env->snprintf,
	env->sdl.fonts.lato30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Accuracy: %.f%%",
	env->player.accuracy);
	print_text(new_point(360, 220), new_printable_text(env->snprintf,
	env->sdl.fonts.lato30, 0xFFFFFFFF, 30), env);
}
