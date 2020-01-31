/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_target_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 16:57:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_global_link_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	/*TTF_Font	*font;
	t_point		text_size;

	(void)condition;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text("Global event", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "Global event", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;*/
	(void)condition;
	(void)env;
	(void)size;
	return (pos.y);
}

int		print_sector_link_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;
	t_point		text_size;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text("Sector", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "Sector", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(condition->target_sector),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(condition->target_sector),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}

int		print_enemy_link_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;
	t_point		text_size;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text("Enemy", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "Enemy", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(condition->target_enemy),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(condition->target_enemy),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}

int		print_wall_sprite_link_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;
	t_point		text_size;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text("Sector", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "Sector", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(condition->target_sector),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(condition->target_sector),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text("wall", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "wall", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(condition->target_wall),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(condition->target_wall),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text("sprite", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "sprite", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(condition->target_sprite),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(condition->target_sprite),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}
