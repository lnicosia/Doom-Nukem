/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:36:54 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/26 14:09:35 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void    print_results(t_env *env)
{
	char	*accuracy;
	int		length;

    draw_rectangle(env,
		new_rectangle(0x00000000, 0xFF888888, 1, 5),
		new_point(200 , 180),
		new_point(350, 520));
	accuracy = ft_sitoa(env->player.accuracy);
	length = ft_strlen(accuracy);
	print_text(new_point(200, 320), new_printable_text("Score :", env->sdl.fonts.amazdoom50, 0xFFFFFFFF, 50), env);
	print_text(new_point(280, 220), new_printable_text("Enemies Killed: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(280, 450), new_printable_text(ft_sitoa(env->player.killed), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(360, 220), new_printable_text("Accuracy: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(360, 450), new_printable_text(ft_sitoa(env->player.accuracy), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(360, 450 + length * 17), new_printable_text("%", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}